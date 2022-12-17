#include <SFML/Graphics.hpp>
#include <GUI/World.hpp>
#include <GUI/EntitySprite.hpp>
#include <utils/SpriteFactory.hpp>
#include <utils/TextureManager.hpp>
#include <Grid.hpp>
#include <Entities.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "SFML Window", sf::Style::Fullscreen);
	gui::World world;
	utils::TextureManager tm;
	utils::SpriteFactory sf(world, tm);
	sf::Vector2i mouse_position;
	sf::Image icon;
	
	icon.loadFromFile("assets/ui/buttons/index.jpg");
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	window.setVerticalSyncEnabled(true);

	// Cela ajoute à la fois un sprite dans le plateau graphique
	// et une entité dans le plateau logique
	sf.create(new Knight(1, 1, 'B'));
	sf.create(new Knight(4, 4, 'B'));
	sf.create(new Knight(17, 17, 'B'));
	
	std::cout << "BEFORE REMOVAL => memory location of knight at position [1,1]		   : " << world.getGrid()[1][1] << '\n';
	std::cout << "BEFORE REMOVAL => memory location of knight SPRITE at position [1,1] : " << world[1][1] << '\n';
	// Cela retire à la fois un sprite dans le plateau graphique
	// et une entité dans le plateau logique
	world.removeEntity(world[1][1]);

	std::cout << "AFTER REMOVAL  => memory location of knight at position [1,1]		   : " << world.getGrid()[1][1] << '\n';
	std::cout << "AFTER REMOVAL  => memory location of knight SPRITE at position [1,1] : " << world[1][1] << '\n';

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

		mouse_position = sf::Mouse::getPosition(window);

		window.draw(world);
		window.display();
		window.clear();
	}

	return 0;
}