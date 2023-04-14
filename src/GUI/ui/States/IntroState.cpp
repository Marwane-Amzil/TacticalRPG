#include <GUI/ui/States/IntroState.hpp>
#include <GUI/ui/States/MenuState.hpp>
#include <GUI/ui/StateMachine.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <memory>

IntroState::IntroState(StateMachine& machine, sf::RenderWindow& window, gui::World& world, utils::TextureManager& texture_manager, iut::ClientSocket& client, const bool replace)
	: State(machine, window, replace), _world(world), _texture_manager(texture_manager), _client(client)
, m_alpha{ 0, 0, 0, 255 } // Start off opaque
{
	if (!m_backgroundTexture.loadFromFile("./assets/ui/menu/img/menu-Play.png"))
	{
		throw std::runtime_error{ "Was unable to load image 'img/intro.png'" };
	}

	m_backgroundTexture.setSmooth(true);
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
						m_next = StateMachine::build<MenuState>(_machine, _window, _world, _texture_manager, _client, true);
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
	else
	{
		m_next = StateMachine::build<MenuState>(_machine, _window, _world, _texture_manager, _client, true);
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
