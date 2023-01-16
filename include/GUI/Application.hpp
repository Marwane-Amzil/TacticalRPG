#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <GUI/ui/StateMachine.hpp>

class Application
{
public:
	void run();

private:
	StateMachine _machine;
	sf::RenderWindow _window;
};
