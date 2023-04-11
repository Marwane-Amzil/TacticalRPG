#include <GUI/ui/States/NetworkPlayStates/NetworkCharacterChoice.hpp>
#include <GUI/game/EntitySprite.hpp>
#include <Entities.hpp>
#include <iostream>
#include <GUI/ui/StateMachine.hpp>
#include <GUI/ui/States/MenuState.hpp>
#include <GUI/ui/States/NetworkPlayStates/NetworkChoosePlay.hpp>
#include <stdio.h>
#include <string.h>



NetworkCharacterChoice::NetworkCharacterChoice(StateMachine& machine, sf::RenderWindow& window, gui::World& world, utils::TextureManager& texture_manager, const bool replace)
	: super(machine, window, world, texture_manager, replace), _animationManager(), _spriteFactory(_world, texture_manager, _animationManager)
{


	_clock.restart();

	_animationManager.loadAnimations();
	//_spriteFactory.createCharacter(new Healer(2, 2, 'Rs'));

	float multiy = 0.83f;
	float multyx = 0.1f;

	auto [x, y] = _window.getSize();


	//met les différentes textures dans m_characters_blue/red
	for (auto characterName : _m_characterNames) {
		m_characters_blue[nb].setTexture(_textureManager.getTextureAt('B', characterName));
		m_characters_blue[nb].setPosition(multyx * x, multiy * y);
		m_characters_blue[nb].setTextureRect(sf::IntRect(70, 650, 50, 50));
		m_characters_blue[nb].setScale(2.8f, 2.8f);
		multiy = multiy - 0.2f;
		nb++;
	}

	multyx = 0.8f;
	multiy = 0.83f;
	nb = 0;
	for (auto characterName : _m_characterNames) {

		m_characters_red[nb].setTexture(_textureManager.getTextureAt('R', characterName));
		m_characters_red[nb].setPosition(multyx * x, multiy * y);
		m_characters_red[nb].setTextureRect(sf::IntRect(70, 650, 50, 50));
		m_characters_red[nb].setScale(2.8f, 2.8f);
		multiy = multiy - 0.2f;
		nb++;

	}
}

void NetworkCharacterChoice::pause()
{
	std::cout << "pause choice\n";
}

void NetworkCharacterChoice::resume()
{
	std::cout << "resume choice\n";
}

void NetworkCharacterChoice::update()
{

	SOCKET socket = createSocket();
	connectSocket(socket, "192.168.43.19", "5000");


	char player_color[2];

	receiveMessage(socket, player_color, 2);

	std::string str_color;

	str_color.assign(player_color);


	int color;

	if (str_color.at(0) == '1') {
		color = 1;
	}
	else {
		color = 0;
	}

	sf::Event event;
	while (_window.pollEvent(event))
	{

		if (event.type == sf::Event::Closed)
			_window.close();
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				_world.clean();
				_machine.run(StateMachine::build<MenuState>(_machine, _window, _world, _textureManager, true));
			}

		}
	}



	auto [x, y] = _window.getSize();


	bool click_looker = false;
	// insert into ->j the id of the clicked character 
	int j = 0;
	while (!click_looker) {
		j = (j + 1) % 5;
		if (color == 0) {
			click_looker = (sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_characters_blue[j].getGlobalBounds().contains(sf::Mouse::getPosition(_window).x, sf::Mouse::getPosition(_window).y));
		}
		else if (color == 1) {
			click_looker = (sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_characters_red[j].getGlobalBounds().contains(sf::Mouse::getPosition(_window).x, sf::Mouse::getPosition(_window).y));

		}
		else {
			click_looker = 1;
		}

	}

	// 0 --> Blue 
	if ((m_characters_blue[j].getGlobalBounds().contains(sf::Mouse::getPosition(_window).x, sf::Mouse::getPosition(_window).y)) && (color == 0))
	{

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			click_looker = false;
			while (!click_looker) {
				int the_y = static_cast<int>(((sf::Mouse::getPosition(_window).y) - (0.04 * y)) / 50);
				if (the_y <= 5) {
					click_looker = ((_world.getShape().getGlobalBounds().contains(sf::Mouse::getPosition(_window).x, sf::Mouse::getPosition(_window).y)) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)));
				}
			}
			click_looker = false;

			// 460 -> espace a gauche grille bords �crans
			// 40 -> espace en haut grille bords �crans

			int pos_grid_x = static_cast<int>(((sf::Mouse::getPosition(_window).x) - (0.24 * x)) / 50);
			int pos_grid_y = static_cast<int>(((sf::Mouse::getPosition(_window).y) - (0.04 * y)) / 50);

			int pos_grille_x = pos_grid_x * 50 + (0.24 * x);
			int pos_grille_y = pos_grid_y * 50 + (0.04 * y);

			char str1;
			char str2;


			//creating message to give the choice made

			if (pos_grid_x < 10) {
				str1 = '0' + pos_grid_x + '/';
			}
			else {
				str1 = pos_grid_x + '/';
			}
			if (pos_grid_x < 10) {
				str2 = '0' + pos_grid_x + '/' + j;
			}
			else {
				str2 = pos_grid_x + '/' + j;
			}

			strcat(&str1, &str2);

			


			
			//sending the message

			switch (j)
			{
			case 0:
				_CurrentCharacter = _spriteFactory.createCharacter(new Warrior(pos_grid_x, pos_grid_y, 'B'));
				break;
			case 1:
				_CurrentCharacter = _spriteFactory.createCharacter(new Archer(pos_grid_x, pos_grid_y, 'B'));
				break;
			case 2:
				_CurrentCharacter = _spriteFactory.createCharacter(new Knight(pos_grid_x, pos_grid_y, 'B'));
				break;
			case 3:
				_CurrentCharacter = _spriteFactory.createCharacter(new Healer(pos_grid_x, pos_grid_y, 'B'));
				break;
			default:
				_CurrentCharacter = _spriteFactory.createCharacter(new Mage(pos_grid_x, pos_grid_y, 'B'));
				break;
			}

			sendMessage(socket, &str1);



			//_CurrentCharacter->update(_clock.getElapsedTime());
			//_clock.restart();
			char received_message[8];

			receiveMessage(socket, received_message, 8);
			std::string strx;
			char charx = received_message[0] + received_message[1];

			strx.assign(&charx);


			std::string stry;
			char chary = received_message[0] + received_message[1];

			stry.assign(&chary);


			pos_grid_x = atoi(strx.c_str());
			pos_grid_y = atoi(stry.c_str());

			j = received_message[6] - '0';

			switch (j)
				{
				case 0:
					_CurrentCharacter = _spriteFactory.createCharacter(new Warrior(pos_grid_x, pos_grid_y, 'R'));
					break;
				case 1:
					_CurrentCharacter = _spriteFactory.createCharacter(new Archer(pos_grid_x, pos_grid_y, 'R'));
					break;
				case 2:
					_CurrentCharacter = _spriteFactory.createCharacter(new Knight(pos_grid_x, pos_grid_y, 'R'));
					break;
				case 3:
					_CurrentCharacter = _spriteFactory.createCharacter(new Healer(pos_grid_x, pos_grid_y, 'R'));
					break;
				default:
					_CurrentCharacter = _spriteFactory.createCharacter(new Mage(pos_grid_x, pos_grid_y, 'R'));
					break;
				}



		}
	}


	// 1 --> Red
	if (m_characters_red[j].getGlobalBounds().contains(sf::Mouse::getPosition(_window).x, sf::Mouse::getPosition(_window).y) && color == 1)
	{


		char received_message[8];

		receiveMessage(socket, received_message, 8);
		std::string strx;
		char charx = received_message[0] + received_message[1];

		strx.assign(&charx);


		std::string stry;
		char chary = received_message[0] + received_message[1];

		stry.assign(&chary);


		int pos_grid_x = atoi(strx.c_str());
		int pos_grid_y = atoi(stry.c_str());

		j = received_message[6] - '0';


		switch (j)
		{
		case 0:
			_CurrentCharacter = _spriteFactory.createCharacter(new Warrior(pos_grid_x, pos_grid_y, 'B'));
			break;
		case 1:
			_CurrentCharacter = _spriteFactory.createCharacter(new Archer(pos_grid_x, pos_grid_y, 'B'));
			break;
		case 2:
			_CurrentCharacter = _spriteFactory.createCharacter(new Knight(pos_grid_x, pos_grid_y, 'B'));
			break;
		case 3:
			_CurrentCharacter = _spriteFactory.createCharacter(new Healer(pos_grid_x, pos_grid_y, 'B'));
			break;
		default:
			_CurrentCharacter = _spriteFactory.createCharacter(new Mage(pos_grid_x, pos_grid_y, 'B'));
			break;
		}




		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			bool click_looker = false;
			while (!click_looker) {
				int the_y = static_cast<int>(((sf::Mouse::getPosition(_window).y) - (0.04 * y)) / 50);
				if (the_y <= 19 && the_y >= 14) {
					click_looker = ((_world.getShape().getGlobalBounds().contains(sf::Mouse::getPosition(_window).x, sf::Mouse::getPosition(_window).y)) && sf::Mouse::isButtonPressed(sf::Mouse::Left));
				}
			}
			click_looker = false;

			// 460 -> espace � gauche grille bords �crans
			// 40 -> espace en haut grille bords �crans

			int pos_grille_x = static_cast<int>(((sf::Mouse::getPosition(_window).x) - (0.24 * x)) / 50) * 50 + (0.24 * x);
			int pos_grille_y = static_cast<int>(((sf::Mouse::getPosition(_window).y) - (0.04 * y)) / 50) * 50 + (0.04 * y);

			pos_grid_x = static_cast<int>(((sf::Mouse::getPosition(_window).x) - (0.24 * x)) / 50);
			pos_grid_y = static_cast<int>(((sf::Mouse::getPosition(_window).y) - (0.04 * y)) / 50);




			switch (j)
			{
			case 0:
				_CurrentCharacter = _spriteFactory.createCharacter(new Warrior(pos_grid_x, pos_grid_y, 'R'));
				break;
			case 1:
				_CurrentCharacter = _spriteFactory.createCharacter(new Archer(pos_grid_x, pos_grid_y, 'R'));
				break;
			case 2:
				_CurrentCharacter = _spriteFactory.createCharacter(new Knight(pos_grid_x, pos_grid_y, 'R'));
				break;
			case 3:
				_CurrentCharacter = _spriteFactory.createCharacter(new Healer(pos_grid_x, pos_grid_y, 'R'));
				break;
			default:
				_CurrentCharacter = _spriteFactory.createCharacter(new Mage(pos_grid_x, pos_grid_y, 'R'));
				break;
			}



			char str1;
			char str2;


			//creating message to give the choice made

			if (pos_grid_x < 10) {
				str1 = '0' + pos_grid_x + '/';
			}
			else {
				str1 = pos_grid_x + '/';
			}
			if (pos_grid_x < 10) {
				str2 = '0' + pos_grid_x + '/' + j;
			}
			else {
				str2 = pos_grid_x + '/' + j;
			}

			strcat(&str1, &str2);

			sendMessage(socket, &str1);

			//_CurrentCharacter->update(_clock.getElapsedTime());
			//_clock.restart();
		}
	}

	if (count == 3)
	{
		_machine.run(StateMachine::build<NetworkChoosePlay>(_machine, _window, _world, _textureManager, true));
	}

	count++;


}// End Update()



void NetworkCharacterChoice::draw()
{
	_window.clear();
	_window.draw(_world);
	for (auto character : m_characters_blue)
	{
		_window.draw(character);

	}
	for (auto character : m_characters_red)
	{
		_window.draw(character);

	}
	_window.display();
}
