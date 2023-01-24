#include <GUI/Application.hpp>
//#include <GUI/ui/States/IntroState.hpp>
//#include <GUI/ui/States/MenuState.hpp>
#include <GUI/ui/States/PlayStates/CharacterChoice.hpp>

void Application::run()
{
	// Create render window
	_window.create({ 1280, 720 }, "Engine Test v3.0", sf::Style::Titlebar | sf::Style::Close);
	_window.setFramerateLimit(30);

	// Initialize the engine
	_machine.run(StateMachine::build<CharacterChoice>(_machine, _window, true));

	// Main loop
	while (_machine.running())
	{
		//_machine.nextState();
		_machine.update();
		_machine.draw();
	}

	// Leaving the scope of 'Application' will cleanup the engine
}
