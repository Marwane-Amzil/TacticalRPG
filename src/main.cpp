#include <GUI/Application.hpp>
#include <SFML/Graphics.hpp>
#include <GUI/ui/States/PlayStates/CharacterChoice.hpp>
#include <GUI/ui/StateMachine.hpp>
int main(int argc, char* argv[])
{
	/*
	while (_window.isOpen()) {
		sf::Event _event;
		while (_window.pollEvent(_event)) {
			if (_event.type == sf::Event::Closed) {
				_window.close();
			}
			_window.clear();
			_window.draw(test);
			_window.display();
		}
		
	}
	*/
	/*
	sf::RenderWindow _window(sf::VideoMode(1280, 720), "Menu SFML", sf::Style::Titlebar | sf::Style::Close);
	gui::World test(_window);
	//StateMachine _machine;
	//CharacterChoice _characterChoise(_machine, _window);
	
	while (_window.isOpen()) {
		sf::Event _event;
		while (_window.pollEvent(_event)) {
			if (_event.type == sf::Event::Closed) {
				_window.close();
			}
			_window.clear();
			_window.draw(test);
			_window.display();
		}

	}
	*/
	
	Application app;
	app.run();
	return 0;
	
}