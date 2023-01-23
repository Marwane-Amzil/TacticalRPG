#include <GUI/ui/States/IntroState.hpp>
#include <GUI/ui/States/PlayStates/CharacterChoice.hpp>
#include <GUI/ui/StateMachine.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <memory>

IntroState::IntroState(StateMachine& machine, sf::RenderWindow& window, const bool replace)
: State{ machine, window, replace }
, m_alpha{ 0, 0, 0, 255 } // Start off opaque
{
	if (!m_backgroundTexture.loadFromFile("assets/images/intro.png"))
	{
		throw std::runtime_error{ "Was unable to load image 'img/intro.png'" };
	}

	m_background.setTexture(m_backgroundTexture, true);

	// Fill the fader surface with black
	m_fader.setFillColor(m_alpha);
	m_fader.setSize(static_cast<sf::Vector2f>(m_backgroundTexture.getSize()));

	std::cout << "IntroState Init\n";
}

void IntroState::pause()
{
	std::cout << "IntroState Pause\n";
}

void IntroState::resume()
{
	std::cout << "IntroState Resume\n";
}

void IntroState::update()
{
    for (auto event = sf::Event{}; _window.pollEvent(event);)
	{
		switch (event.type)
		{
            case sf::Event::Closed:
                _machine.quit();
                break;

            case sf::Event::KeyPressed:
            {
                switch (event.key.code)
                {
                    case sf::Keyboard::Space:
                        m_next = StateMachine::build<CharacterChoice>(_machine, _window, true);
                        break;

                    case sf::Keyboard::Escape:
                        _machine.quit();
                        break;

					default:
						break;
                }
                break;
            }

			default:
				break;
		}
	}

	if (m_alpha.a != 0)
	{
		m_alpha.a--;
	}

	m_fader.setFillColor(m_alpha);
}

void IntroState::draw()
{
	// Clear the previous drawing
	_window.clear();

	_window.draw(m_background);

	// No need to draw if it's transparent
	if (m_alpha.a != 0)
	{
		_window.draw(m_fader);
	}

	_window.display();
}
