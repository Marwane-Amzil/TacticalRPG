#include <utils/TextureManager.hpp>
#include <utils/AnimationManager.hpp>
#include <utils/SpriteManager.hpp>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!", sf::Style::Titlebar | sf::Style::Close);
	window.setVerticalSyncEnabled(true);
	SpriteManager sprite_manager;
	sprite_manager.load();

	SpriteComponent sprite = sprite_manager.get('B', "warrior");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(sprite);
		window.display();
	}
	
	return 0;
}