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
	window.create(sf::VideoMode::getDesktopMode(), "fenetre", sf::Style::Fullscreen);
	//sf::Vector2u screenSize
	auto [x, y] = window.getSize();
	window.setView(sf::View(sf::FloatRect(0, 0, x, y)));
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
	
	auto [x, y] = _window.getSize();
	float background_width = (1000.0 / 1920)*x;
	float background_height = (1000.0 / 1080)*y;

	std::cout << "\nwidth : " << background_width << "						height : " << background_height;




	sf::Texture t;
	t.loadFromFile("assets/images/background.png", sf::IntRect(0,0, static_cast<int>(background_width/20), static_cast<int>(background_height/20)));
	sf::Sprite s;
	s.setTexture(t);

	int basic_x_pos = static_cast<int>(0.24 * x);
	int basic_y_pos = static_cast<int>(0.04 * y);

	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 20; ++j) {
			s.setPosition(i* static_cast<int>(background_width / 20) + basic_x_pos, 
						  j * static_cast<int>(background_height / 20) + basic_y_pos);

			_window.draw(s);
		}
	}
	
	std::string color = "blue";

	//for (int i = 0; i < 2; ++i) {
		sf::Texture tknight;
		tknight.loadFromFile("assets/images/characters/" + color + "/knight.png", sf::IntRect());
		sf::Sprite sknight;
		sknight.setTexture(tknight);
		sknight.setPosition(static_cast<int>(0.83*x), 0.0);
		sknight.setTextureRect(sf::IntRect(70, 650, 50, 50));
		sknight.setScale(3.84, 3.84);
		_window.draw(sknight);

		std::cout << "assets/images/characters/" + color + "/knight.png";

		sf::Texture tarcher;
		tarcher.loadFromFile("assets/images/characters/" + color + "/archer.png", sf::IntRect());
		sf::Sprite sarcher;
		sarcher.setTexture(tarcher);
		sarcher.setPosition(static_cast<int>(0.83 * x), static_cast<int>(0.2 * y));
		sarcher.setTextureRect(sf::IntRect(70, 650, 50, 50));
		sarcher.setScale(3.84, 3.84);
		_window.draw(sarcher);

		sf::Texture thealer;
		thealer.loadFromFile("assets/images/characters/" + color + "/healer.png", sf::IntRect());
		sf::Sprite shealer;
		shealer.setTexture(thealer);
		shealer.setPosition(static_cast<int>(0.83 * x), static_cast<int>(0.4 * y));
		shealer.setTextureRect(sf::IntRect(70, 650, 50, 50));
		shealer.setScale(3.84, 3.84);
		_window.draw(shealer);


		sf::Texture tmage;
		tmage.loadFromFile("assets/images/characters/" + color + "/mage.png", sf::IntRect());
		sf::Sprite smage;
		smage.setTexture(tmage);
		smage.setPosition(static_cast<int>(0.83 * x), static_cast<int>(0.6 * y));
		smage.setTextureRect(sf::IntRect(70, 650, 50, 50));
		smage.setScale(3.84, 3.84);
		_window.draw(smage);

		sf::Texture twarrior;
		twarrior.loadFromFile("assets/images/characters/" + color + "/warrior.png", sf::IntRect());
		sf::Sprite swarrior;
		swarrior.setTexture(twarrior);
		swarrior.setPosition(static_cast<int>(0.83 * x), static_cast<int>(0.8 * y));
		swarrior.setTextureRect(sf::IntRect(70,650, 50, 50));
		swarrior.setScale(3.84,3.84);
		_window.draw(swarrior);

	//	color = "red";
	//}
		_window.display();
}