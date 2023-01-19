#include <iostream>
#include <memory>
#include <stdexcept>
#include <GUI/ui/States/PlayState.hpp>
#include <GUI/ui/StateMachine.hpp>
#include <GUI/ui/States/MenuState.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <GUI/game/EntitySprite.hpp>
#include <array>


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

	pos_in_list = 0;


	initSprite('B');










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
	
	if (pos_in_list < 11) {
		auto [x, y] = _window.getSize();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			_window.close();
		}



		auto [xcoord, ycoord] = sf::Mouse::getPosition();


		bool click_looker = false;
		while (!click_looker) {
			sf::Vector2i vector = sf::Mouse::getPosition();

			xcoord = vector.x;
			ycoord = vector.y;

			click_looker = (xcoord < static_cast<int>(0.93 * x)) && (xcoord > static_cast<int>(0.83 * x)) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				_window.close();
			}

		}
		click_looker = false;


		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

			if (ycoord < static_cast<int>(0.4 * y)) {

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
			click_looker = ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && (
				((xcoord > static_cast<int>(0.24 * x)) && (xcoord < static_cast<int>(0.76 * x))) &&
				((ycoord > static_cast<int>(0.04 * y)) && (ycoord < static_cast<int>(0.96 * y)))));
			;
		}
		click_looker = false;


		sf::Vector2i vector = sf::Mouse::getPosition();
		xcoord = vector.x;

		ycoord = vector.y;

		int pos_grille_x = static_cast<int>(((xcoord)-460) / 50) * 50 + 460;
		int pos_grille_y = static_cast<int>(((ycoord)-40) / 50) * 50 + 40;

		std::cout << "\n" << xcoord << "//" << pos_grille_x << "\n" << ycoord << "//" << pos_grille_y;



		sprite_of_selected_character.setPosition(sf::Vector2f(pos_grille_x, pos_grille_y));



		list_of_sprites[pos_in_list] = sprite_of_selected_character;

		list_of_sprites[pos_in_list].setScale(1, 1);


		std::cout << "\n" << list_of_sprites[0].getPosition().x << "////" << list_of_sprites[0].getPosition().y;




		//std::cout << "\ndrawn";
	//}

	//----------------
	/*for (auto event = sf::Event{}; _window.pollEvent(event);)
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
	}*/
	}
	else {

	auto [x, y] = _window.getSize();
		
	_window.clear();

	sf::Texture text_begin;
	text_begin.loadFromFile("assets/images/le_jeu_peut_commencer.png");

	sf::Sprite game_begin;
	game_begin.setTexture(text_begin);
	game_begin.setTextureRect(sf::IntRect(0, 0, x, y));

	_window.draw(game_begin);
	_window.display();

	std::cout << "\n le jeu peut commencer";

	bool click_looker = false;
	while (!click_looker);

	}
}

void PlayState::draw()
{
	// Clear the previous drawing
	_window.clear();


	if (pos_in_list++ < 5) {
		initSprite('B');
	}
	else {
		initSprite('R');
	}

	auto [x, y] = _window.getSize();
	float background_width = (1000.0 / 1920) * x;
	float background_height = (1000.0 / 1080) * y;

	//std::cout << "\nwidth : " << background_width << "						height : " << background_height;




	background_texture.loadFromFile("assets/images/background.png", sf::IntRect(0, 0, static_cast<int>(background_width / 20), static_cast<int>(background_height / 20)));
	background_sprite.setTexture(&background_texture);

	int basic_x_pos = static_cast<int>(0.24 * x);
	int basic_y_pos = static_cast<int>(0.04 * y);

	
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 20; ++j) {
			background_sprite.setPosition(i * static_cast<int>(background_width / 20) + basic_x_pos,
				j * static_cast<int>(background_height / 20) + basic_y_pos);

			_window.draw(background_sprite);
		}
	}


	

	for (int i = 0; i < list_of_sprites.size(); ++i) {
		std::cout << "\n" << i << "  :  " << list_of_sprites[i].getPosition().x << "////" << list_of_sprites[i].getPosition().y;
		
		_window.draw(list_of_sprites[i]);
	}




	_window.display();

		
}


void PlayState::initSprite(char color) {

	auto [x, y] = _window.getSize();


	swarrior.setTexture(TM.getTextureAt(color, "warrior"));
	swarrior.setPosition(static_cast<int>(0.83 * x), static_cast<int>(0.8 * y));
	swarrior.setTextureRect(sf::IntRect(70, 650, 50, 50));
	swarrior.setScale(3.84, 3.84);

	smage.setTexture(TM.getTextureAt(color, "mage"));
	smage.setPosition(static_cast<int>(0.83 * x), static_cast<int>(0.6 * y));
	smage.setTextureRect(sf::IntRect(70, 650, 50, 50));
	smage.setScale(3.84, 3.84);

	shealer.setTexture(TM.getTextureAt(color, "healer"));
	shealer.setPosition(static_cast<int>(0.83 * x), static_cast<int>(0.4 * y));
	shealer.setTextureRect(sf::IntRect(70, 650, 50, 50));
	shealer.setScale(3.84, 3.84);

	sarcher.setTexture(TM.getTextureAt(color, "archer"));
	sarcher.setPosition(static_cast<int>(0.83 * x), static_cast<int>(0.2 * y));
	sarcher.setTextureRect(sf::IntRect(70, 650, 50, 50));
	sarcher.setScale(3.84, 3.84);

	sknight.setTexture(TM.getTextureAt(color, "knight"));
	sknight.setPosition(static_cast<int>(0.83 * x), 0.0);
	sknight.setTextureRect(sf::IntRect(70, 650, 50, 50));
	sknight.setScale(3.84, 3.84);

	_window.draw(sknight);

	_window.draw(sarcher);

	_window.draw(shealer);

	_window.draw(smage);

	_window.draw(swarrior);

}