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
	gui::Animation animation;
	sf::Clock clock;
	auto k1 = sf.create(new Knight(1, 1, 'B'));
	auto k2 = sf.create(new Knight(5, 8, 'B'));
	auto k3 = sf.create(new Knight(8, 8, 'B'));
	auto a1 = sf.create(new Archer(12, 8, 'B'));
	
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

		k1->playAnimation();
		k1->update(frame_time);
		k1->move(0.2f, 0.f);

		k2->playAnimation();
		k2->update(frame_time);
		k2->move(0.2f, 0.f);

		k3->playAnimation();
		k3->update(frame_time);
		k3->move(0.2f, 0.f);

		a1->playAnimation();
		a1->update(frame_time);
		a1->move(0.2f, 0.f);

		window.draw(world);
		window.display();
		window.clear();
	}
	
	return 0;
}