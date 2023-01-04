#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <GUI/ui/StateMachine.hpp>

class Application
{
public:
	void run();

private:
	StateMachine m_machine;
	sf::RenderWindow m_window;
};
