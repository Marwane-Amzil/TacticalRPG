#include <utils/TextureManager.hpp>
#include <utils/SpriteFactory.hpp>
#include <GUI/World.hpp>
#include <GUI/Button.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include <Entities.hpp>
#include <Grid.hpp>
#include <iostream>

int main(int argc, char* argv[])
{
	/*
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "SFML Window", sf::Style::Fullscreen);
	gui::World world;
	utils::TextureManager texture_manager;
	utils::SpriteFactory sprite_factory(&world, &texture_manager);
	sf::Music music;
	sf::Vector2i mouse_position;

	window.setVerticalSyncEnabled(true);
	music.openFromFile("./assets/sounds/rays_boss.ogg");
	music.setLoop(true);
	music.play();

	for (size_t i = 0; i < ::grid::ROWS; i++)
	{
		for (size_t j = 0; j < ::grid::COLUMNS; j++)
		{
			sprite_factory.create(new Knight(i, j, 'B'));
		}
	}

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

		mouse_position = sf::Mouse::getPosition(window);

		window.draw(world);
		window.display();
		window.clear();
	}
	*/

	Grid grid;

	grid.addEntity(new Knight(2, 4, 'B'));
	grid.addEntity(new Knight(3, 7, 'R'));
	grid.addEntity(new Knight(4, 8, 'B'));
	grid.addEntity(new Knight(5, 1, 'B'));
	grid.display();

	return 0;
}