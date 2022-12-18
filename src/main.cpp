#include <SFML/Graphics.hpp>
#include <GUI/game/World.hpp>
#include <GUI/game/EntitySprite.hpp>
#include <GUI/game/Game.hpp>
#include <GUI/game/Animation.hpp>
#include <utils/SpriteFactory.hpp>
#include <utils/TextureManager.hpp>
#include <Grid.hpp>
#include <Entities.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1080, 780), "SFML Window", sf::Style::Titlebar | sf::Style::Close);
	gui::World world;
	utils::TextureManager tm;
	utils::SpriteFactory sf(world, tm);
	sf::Vector2i mouse_position;
	sf::Image icon;
	gui::Animation animation;
	sf::Clock clock;

	icon.loadFromFile("assets/ui/buttons/index.jpg");
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	window.setVerticalSyncEnabled(true);
	animation.addFrame(0, 710, 50, 60);
	animation.addFrame(62, 710, 50, 60);
	auto k1 = sf.create(new Knight(1, 1, 'B'));
	auto k2 = sf.create(new Knight(5, 8, 'B'));
	auto k3 = sf.create(new Knight(8, 8, 'B'));
	k1->addAnimation(0, animation);
	k2->addAnimation(0, animation);
	k3->addAnimation(0, animation);
	k1->setCurrentAnimation(0);
	k2->setCurrentAnimation(0);
	k3->setCurrentAnimation(0);
	
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

		k1->playAnimation();
		k1->update(frame_time);

		k2->playAnimation();
		k2->update(frame_time);

		k3->playAnimation();
		k3->update(frame_time);
		
		window.draw(world);
		window.display();
		window.clear();
	}
	
	return 0;
}