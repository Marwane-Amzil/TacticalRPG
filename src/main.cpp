#include <SFML/Graphics.hpp>
#include <GUI/game/World.hpp>
#include <GUI/game/EntitySprite.hpp>
#include <GUI/game/Animation.hpp>
#include <utils/SpriteFactory.hpp>
#include <utils/TextureManager.hpp>
#include <utils/AnimationManager.hpp>
#include <Grid.hpp>
#include <Entities.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1080, 780), "SFML Window", sf::Style::Titlebar | sf::Style::Close);
	gui::World world;
	utils::TextureManager tm;
	utils::AnimationManager am;
	utils::SpriteFactory sf(world, tm, am);
	sf::Vector2i mouse_position;
	sf::Image icon;
	sf::Clock clock;
	std::vector<gui::EntitySprite*> sprites;

	sprites.push_back(sf.create(new Knight(10, 10, 'B')));
	sprites.push_back(sf.create(new Knight(4, 11, 'B')));
	sprites.push_back(sf.create(new Knight(1, 7, 'B')));
	sprites.push_back(sf.create(new Knight(2, 2, 'B')));
	sprites.push_back(sf.create(new Knight(15, 15, 'B')));

	sprites[0]->setCurrentAnimation(3);
	sprites[1]->setCurrentAnimation(3);
	sprites[2]->setCurrentAnimation(4);
	sprites[3]->setCurrentAnimation(5);
	sprites[4]->setCurrentAnimation(6);

	//animation.setLoop(true);
	icon.loadFromFile("assets/ui/buttons/index.jpg");
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	window.setVerticalSyncEnabled(true);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		sf::Time frame_time = clock.restart();

		mouse_position = sf::Mouse::getPosition(window);

		for (auto& sprite : sprites)
		{
			sprite->playAnimation();
			sprite->update(frame_time);
		}

		window.draw(world);
		window.display();
		window.clear();
	}
	
	return 0;
}