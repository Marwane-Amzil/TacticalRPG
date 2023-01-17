#include <iostream>
#include <memory>
#include <stdexcept>
#include <GUI/ui/States/PlayState.hpp>
#include <GUI/ui/StateMachine.hpp>
#include <GUI/ui/States/MenuState.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

PlayState::PlayState(StateMachine& machine, sf::RenderWindow& window, const bool replace)
: State{ machine, window, replace }
{
	if (!m_backgroundTexture.loadFromFile("assets/images/play.png"))
	{
		throw std::runtime_error{ "Was unable to load image 'img/play.png'" };
	}
	window.setSize(sf::Vector2u::Vector2(1000, 1000));
	window.setView(sf::View(sf::FloatRect(0, 0, 1000,1000)));
	window.setPosition(sf::Vector2i::Vector2(0, 0));
	window.display();


	m_background.setTexture(m_backgroundTexture, true);

	std::cout << "PlayState Init\n";
}

void PlayState::pause()
{
	std::cout << "PlayState Pause\n";
}

void PlayState::resume()
{
	std::cout << "PlayState Resume\n";
}

void PlayState::update()
{
	for (auto event = sf::Event{}; _window.pollEvent(event);)
	{
		switch (event.type)
		{
			case sf::Event::Closed:
				_machine.quit();
				break;

			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
					case sf::Keyboard::Escape:
						_machine.quit();
						break;

					case sf::Keyboard::M:
						m_next = StateMachine::build<MenuState>(_machine, _window, false);
						break;

					default:
						break;
				}
				break;

			default:
				break;
		}
	}
}

void PlayState::draw()
{
	// Clear the previous drawing
	_window.clear();
	
	
	int height = _window.getSize().x;
	int length = _window.getSize().y;
	sf::Texture t;
	t.loadFromFile("assets\\images\\background.png", sf::IntRect(0,0,50,50));
	sf::Sprite s;
	s.setTexture(t, true);
	

	for (int i = 0; i < 20; i ++) {
		for (int j = 0; j < 20; j ++) {
			s.setPosition(int(i*50),int(j*50));
			_window.draw(s);
			
		}
	}
	_window.display();
}
