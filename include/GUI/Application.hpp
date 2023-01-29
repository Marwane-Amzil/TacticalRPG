#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <GUI/ui/StateMachine.hpp>
#include <GUI/game/World.hpp>
#include <utils/TextureManager.hpp>

class Application
{
public:
	
	Application();

	void run();

private:
	StateMachine _machine;
	sf::RenderWindow _window;
	gui::World _world;
	utils::TextureManager _textureManager;
};
