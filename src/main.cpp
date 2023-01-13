#include <utils/TextureManager.hpp>
#include <utils/AnimationManager.hpp>
#include <utils/SpriteManager.hpp>
#include <utils/EntityCreator.hpp>
#include <systems/AnimationSystem.hpp>
#include <systems/SpriteRenderer.hpp>
#include <components/PositionComponent.hpp>
#include <components/SpriteComponent.hpp>
#include <SFML/Graphics.hpp>
#include <entt/entt.hpp>
#include <iostream>
#include <chrono>

int main()
{
	entt::registry registry;
	sf::RenderWindow window(sf::VideoMode(1080, 780), "SFML works!", sf::Style::Titlebar | sf::Style::Close);
	SpriteManager sm;
	AnimationManager am;
	EntityCreator cr(registry);
	AnimationSystem as(registry);
	SpriteRenderer sr(window, registry);
	sf::Clock clock;

	window.setVerticalSyncEnabled(true);
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	sm.load();
	end = std::chrono::system_clock::now();
	am.load();

	std::chrono::duration<double> elapsed_seconds = end - start;
	std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

	std::vector<entt::entity> entities;
	
	for (int i = 0; i < 10; ++i)
	{
		entities.push_back(cr.create());
		registry.emplace<PositionComponent>(entities[i], 35 * i, 45 * i);
		registry.emplace<SpriteComponent>(entities[i], sm.get('B', "knight"));
	}

	for (auto entity : entities)
	{
		registry.emplace<AnimationComponent>(entity, am.getAnimations()[6]);
	}
	
	while (window.isOpen())
	{
		sf::Event event;
		sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear();
		sr.render();
		as.update(clock.restart());
		window.display();
	}

	return 0;
}