#include <iostream>
#include <memory>
#include <stdexcept>
#include <GUI/ui/States/PlayState.hpp>
#include <GUI/ui/StateMachine.hpp>
#include <GUI/ui/States/MenuState.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <GUI/game/EntitySprite.hpp>

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

	TM.loadTextures();

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
	float background_width = (1000.0 / 1920) * x;
	float background_height = (1000.0 / 1080) * y;

	std::cout << "\nwidth : " << background_width << "						height : " << background_height;




	sf::Texture t;
	t.loadFromFile("assets/images/background.png", sf::IntRect(0,0, static_cast<int>(background_width/20), static_cast<int>(background_height/20)));
	gui::EntitySprite s;
	s.setTexture(&t);

	int basic_x_pos = static_cast<int>(0.24 * x);
	int basic_y_pos = static_cast<int>(0.04 * y);

	for (int i = 0; i < 5; ++i) {
		_window.clear();

		for (int i = 0; i < 20; ++i) {
			for (int j = 0; j < 20; ++j) {
				s.setPosition(i * static_cast<int>(background_width / 20) + basic_x_pos,
					j * static_cast<int>(background_height / 20) + basic_y_pos);
				_window.draw(s);
			}
		}


		char color = 'B';

		for (int i = 0; i < 2; ++i) {

			//sf::Texture tknight;
			//tknight.loadFromFile("assets/images/characters/" + color + "/knight.png", sf::IntRect());
			gui::EntitySprite sknight;
			sknight.setTexture(TM.getTextureAt(color, "knight"));
			sknight.setPosition(static_cast<int>(0.83 * x), 0.0);
			sknight.setTextureRect(sf::IntRect(70, 650, 50, 50));
			sknight.setScale(3.84, 3.84);
			_window.draw(sknight);


			//sf::Texture tarcher;
			//tarcher.loadFromFile("assets/images/characters/" + color + "/archer.png", sf::IntRect());
			gui::EntitySprite sarcher;
			sarcher.setTexture(TM.getTextureAt(color, "archer"));
			sarcher.setPosition(static_cast<int>(0.83 * x), static_cast<int>(0.2 * y));
			sarcher.setTextureRect(sf::IntRect(70, 650, 50, 50));
			sarcher.setScale(3.84, 3.84);
			_window.draw(sarcher);

			//sf::Texture thealer;
			//thealer.loadFromFile("assets/images/characters/" + color + "/healer.png", sf::IntRect());
			gui::EntitySprite shealer;
			shealer.setTexture(TM.getTextureAt(color, "healer"));
			shealer.setPosition(static_cast<int>(0.83 * x), static_cast<int>(0.4 * y));
			shealer.setTextureRect(sf::IntRect(70, 650, 50, 50));
			shealer.setScale(3.84, 3.84);
			_window.draw(shealer);


			//sf::Texture tmage;
			//tmage.loadFromFile("assets/images/characters/" + color + "/mage.png", sf::IntRect());
			gui::EntitySprite smage;
			smage.setTexture(TM.getTextureAt(color, "mage"));
			smage.setPosition(static_cast<int>(0.83 * x), static_cast<int>(0.6 * y));
			smage.setTextureRect(sf::IntRect(70, 650, 50, 50));
			smage.setScale(3.84, 3.84);
			_window.draw(smage);

			//sf::Texture twarrior;
			//twarrior.loadFromFile("assets/images/characters/" + color + "/warrior.png", sf::IntRect());
			gui::EntitySprite swarrior;
			swarrior.setTexture(TM.getTextureAt(color, "warrior"));
			swarrior.setPosition(static_cast<int>(0.83 * x), static_cast<int>(0.8 * y));
			swarrior.setTextureRect(sf::IntRect(70, 650, 50, 50));
			swarrior.setScale(3.84, 3.84);
			_window.draw(swarrior);

			_window.display();



			for (int i = 0; i < 5; ++i) {
				_window.clear();
				std::cout << "cleared";

				for (int i = 0; i < 20; ++i) {
					for (int j = 0; j < 20; ++j) {
						s.setPosition(i * static_cast<int>(background_width / 20) + basic_x_pos,
							j * static_cast<int>(background_height / 20) + basic_y_pos);
						_window.draw(s);
					}
				}

				_window.draw(sknight);
				_window.draw(sarcher);
				_window.draw(shealer);
				_window.draw(smage);
				_window.draw(swarrior);





				auto [xcoord, ycoord] = sf::Mouse::getPosition();


				bool click_looker = false;
				while (!click_looker) {
					auto [xcoord, ycoord] = sf::Mouse::getPosition();
					click_looker = (xcoord < static_cast<int>(0.93 * x)) && (xcoord > static_cast<int>(0.83 * x)) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
				}

				click_looker = false;
				gui::EntitySprite sprite_of_selected_character;


				

				if ((xcoord < static_cast<int>(0.93 * x)) && (xcoord > static_cast<int>(0.83 * x))) {
					if (ycoord < static_cast<int>(0.2 * y)) {

						std::cout << "\nknight selected";
						sprite_of_selected_character = sknight;

					}
					else if ((ycoord < static_cast<int>(0.4 * y)) && (ycoord > static_cast<int>(0.2 * y))) {

						std::cout << "\narcher selected";
						sprite_of_selected_character = sarcher;

					}
					else if ((ycoord < static_cast<int>(0.6 * y)) && (ycoord > static_cast<int>(0.4 * y))) {
						
						std::cout << "\nhealer selected";
						sprite_of_selected_character = shealer;

					}
					else if ((ycoord < static_cast<int>(0.8 * y)) && (ycoord > static_cast<int>(0.6 * y))) {

						std::cout << "\nmage selected";
						sprite_of_selected_character = smage;

					}
					else if ((ycoord < y) && (ycoord > static_cast<int>(0.8 * y))) {

						std::cout << "\nwarrior selected";
						sprite_of_selected_character = swarrior;

					}
				}

				click_looker = false;
				while (!click_looker) {
					auto [xcoord, ycoord] = sf::Mouse::getPosition();
					std::cout << "wait";
					click_looker = ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && (
						((xcoord > static_cast<int>(0.24 * x)) && (xcoord < static_cast<int>(0.76 * x))) &&
						((ycoord > static_cast<int>(0.04 * y)) && (ycoord < static_cast<int>(0.96 * y)))));
							;
				}
				click_looker = false;


				sf::Vector2i vector =  sf::Mouse::getPosition();
				xcoord = vector.x;

				ycoord = vector.y;

				int pos_grille_x = static_cast<int>(((xcoord) - 460) / 50) * 50 + 460;
				int pos_grille_y = static_cast<int>(((ycoord) - 40) / 50) * 50 + 40;

				sprite_of_selected_character.setPosition(sf::Vector2f::Vector2(pos_grille_x, pos_grille_y));


			

				_window.draw(sprite_of_selected_character);
				_window.display();
				std::cout << "\ndrawn";
			}
			color = 'R';
		}
	}
}