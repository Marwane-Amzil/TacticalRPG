#include <GUI/Application.hpp>
#include <GUI/ui/States/IntroState.hpp>

void Application::run()
{
	// Create render window
	_window.create({ 640, 480 }, "Engine Test v3.0", sf::Style::Titlebar | sf::Style::Close);
	_window.setFramerateLimit(30);

	// Initialize the engine
	_machine.run(StateMachine::build<IntroState>(_machine, _window, true));

	// Main loop
	while (_machine.running())
	{
		_machine.nextState();
		_machine.update();
		_machine.draw();
	}

	// Leaving the scope of 'Application' will cleanup the engine
}