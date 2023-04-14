#include <GUI/ui/States/NetworkPlayStates/NetworkCharacterChoice.hpp>
#include <GUI/ui/StateMachine.hpp>
#include <GUI/ui/States/MenuState.hpp>
//#include <GUI/ui/States/NetworkPlayStates/NetworkChoosePlay.hpp>
#include <Entities.hpp>
#include <network.hpp>
#include <iostream>

NetworkCharacterChoice::NetworkCharacterChoice(StateMachine& machine, sf::RenderWindow& window, gui::World& world, utils::TextureManager& texture_manager, iut::ClientSocket& client, const char player, const bool replace)
	: super(machine, window, world, texture_manager, client, replace), _animationManager(), _spriteFactory(_world, texture_manager, _animationManager), _send_thread(), _receive_thread(), _player(player), _is_ready(false)
{
	_animationManager.loadAnimations();

	auto [x, y] = _window.getSize();

	float multiy = 0.83f;
	float multyx = 0.1f;
	
	if (_player == 'B')
	{
		for (const std::string& characterName : _m_characterNames)
		{
			m_characters[nb].setTexture(_texture_manager.getTextureAt('B', characterName));
			m_characters[nb].setPosition(multyx * x, multiy * y);
			m_characters[nb].setTextureRect(sf::IntRect(70, 650, 50, 50));
			m_characters[nb].setScale(2.8f, 2.8f);
			multiy = multiy - 0.2f;
			++nb;
		}
	}
	else
	{
		multyx = 0.8f;
		multiy = 0.83f;
		
		for (const std::string& characterName : _m_characterNames)
		{
			m_characters[nb].setTexture(_texture_manager.getTextureAt('R', characterName));
			m_characters[nb].setPosition(multyx * x, multiy * y);
			m_characters[nb].setTextureRect(sf::IntRect(70, 650, 50, 50));
			m_characters[nb].setScale(2.8f, 2.8f);
			multiy = multiy - 0.2f;
			++nb;
		}
	}

	nb = 0;
}

void NetworkCharacterChoice::pause() {}

void NetworkCharacterChoice::resume() {}

void NetworkCharacterChoice::update()
{
	sf::Event event;

	while (_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			_window.close();
		}

		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				_world.clean();
				_machine.run(StateMachine::build<MenuState>(_machine, _window, _world, _texture_manager, _client, true));
			}
		}
	}

	if (!_is_ready)
	{
		if (!_receive_thread.joinable())
		{
			_receive_thread = std::thread(&NetworkCharacterChoice::_receiveCharacter, this);
			_receive_thread.detach();
		}

		auto [x, y] = _window.getSize();
		bool click_looker = false;
		int j = 0;

		while (!click_looker)
		{
			j = (j + 1) % 5;

			click_looker = (sf::Mouse::isButtonPressed(sf::Mouse::Left) && m_characters[j].getGlobalBounds().contains(sf::Mouse::getPosition(_window).x, sf::Mouse::getPosition(_window).y));
		}

		if (m_characters[j].getGlobalBounds().contains(sf::Mouse::getPosition(_window).x, sf::Mouse::getPosition(_window).y))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				click_looker = false;

				while (!click_looker)
				{
					int the_y = static_cast<int>(((sf::Mouse::getPosition(_window).y) - (0.04 * y)) / 50);

					if (_player == 'B')
					{
						if (the_y < 5)
						{
							click_looker = ((_world.getShape().getGlobalBounds().contains(sf::Mouse::getPosition(_window).x, sf::Mouse::getPosition(_window).y)) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)));
						}
					}
					else
					{
						if (the_y < 20 && the_y > 13)
						{
							click_looker = ((_world.getShape().getGlobalBounds().contains(sf::Mouse::getPosition(_window).x, sf::Mouse::getPosition(_window).y)) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)));
						}
					}
				}

				click_looker = false;

				int pos_grid_x = static_cast<int>(((sf::Mouse::getPosition(_window).x) - (0.24 * x)) / 50);
				int pos_grid_y = static_cast<int>(((sf::Mouse::getPosition(_window).y) - (0.04 * y)) / 50);

				if (!_send_thread.joinable())
				{
					_send_thread = std::thread(&NetworkCharacterChoice::_sendCharacter, this);
					_send_thread.detach();
				}

				switch (j)
				{
				case 0:
					_CurrentCharacter = _spriteFactory.createCharacter(new Warrior(pos_grid_x, pos_grid_y, _player));
					_team += "W/" + std::to_string(pos_grid_x) + '/' + std::to_string(pos_grid_y);
					break;
				case 1:
					_CurrentCharacter = _spriteFactory.createCharacter(new Archer(pos_grid_x, pos_grid_y, _player));
					_team += "A/" + std::to_string(pos_grid_x) + '/' + std::to_string(pos_grid_y);
					break;
				case 2:
					_CurrentCharacter = _spriteFactory.createCharacter(new Knight(pos_grid_x, pos_grid_y, _player));
					_team += "K/" + std::to_string(pos_grid_x) + '/' + std::to_string(pos_grid_y);
					break;
				case 3:
					_CurrentCharacter = _spriteFactory.createCharacter(new Healer(pos_grid_x, pos_grid_y, _player));
					_team += "H/" + std::to_string(pos_grid_x) + '/' + std::to_string(pos_grid_y);
					break;
				default:
					_CurrentCharacter = _spriteFactory.createCharacter(new Mage(pos_grid_x, pos_grid_y, _player));
					_team += "M/" + std::to_string(pos_grid_x) + '/' + std::to_string(pos_grid_y);
					break;
				}

				++_count;
			}
		}
	}

	if (_is_ready)
	{
		_world.clean();
		//_machine.run(StateMachine::build<NetworkChoosePlay>(_machine, _window, _world, _texture_manager, _client, _player, _team));
	}
}

void NetworkCharacterChoice::draw()
{
	_window.clear();
	_window.draw(_world);
	
	for (const auto& character : m_characters)
	{
		_window.draw(character);
	}
	
	_window.display();
}

void NetworkCharacterChoice::_sendCharacter()
{
	_client.send(_team.data());
	_team.clear();
	++_count;

	if (_count == 5)
	{
		_is_ready = true;
	}
}

void NetworkCharacterChoice::_receiveCharacter()
{
	std::string opponent_character = _client.receive();

	char _opponent_character_type = opponent_character[0];
	size_t index = opponent_character.find('/');
	std::string _opponent_character_x = opponent_character.substr(index + 1, opponent_character.find('/', index + 1) - index - 1);
	std::string _opponent_character_y = opponent_character.substr(opponent_character.find('/', index + 1) + 1, opponent_character.length() - opponent_character.find('/', index + 1) - 1);

	switch (_opponent_character_type)
	{
	case 'W':
		_spriteFactory.createCharacter(new Warrior(std::stoi(_opponent_character_x), std::stoi(_opponent_character_y), _player == 'B' ? 'R' : 'B'));
		break;

	case 'A':
		_spriteFactory.createCharacter(new Archer(std::stoi(_opponent_character_x), std::stoi(_opponent_character_y), _player == 'B' ? 'R' : 'B'));
		break;

	case 'K':
		_spriteFactory.createCharacter(new Knight(std::stoi(_opponent_character_x), std::stoi(_opponent_character_y), _player == 'B' ? 'R' : 'B'));
		break;

	case 'H':
		_spriteFactory.createCharacter(new Healer(std::stoi(_opponent_character_x), std::stoi(_opponent_character_y), _player == 'B' ? 'R' : 'B'));
		break;

	case 'M':
		_spriteFactory.createCharacter(new Mage(std::stoi(_opponent_character_x), std::stoi(_opponent_character_y), _player == 'B' ? 'R' : 'B'));
		break;
	}
}