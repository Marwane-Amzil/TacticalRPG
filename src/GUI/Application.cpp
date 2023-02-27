#include <GUI/Application.hpp>
#include <GUI/ui/States/IntroState.hpp>
#include <GUI/ui/States/MenuState.hpp>
#include <GUI/ui/States/PlayStates/CharacterChoice.hpp>

Application::Application()
	: _machine(), _window(sf::VideoMode::getDesktopMode(), "SFML Window", sf::Style::Fullscreen), _world(_window)
{
	_window.setVerticalSyncEnabled(true);
	_textureManager.loadTextures();
}

void Application::run()
{
	// Initialize the engine
	_machine.run(StateMachine::build<CharacterChoice>(_machine, _window, _world, _textureManager, true));

	// Main loop
	while (_machine.running())
	{
		//_machine.nextState();
		_machine.update();
		_machine.draw();
	}

	// Leaving the scope of 'Application' will cleanup the engine
}
