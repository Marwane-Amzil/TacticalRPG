#include "GUI/ui/States/PlayStates/ChoosePlay.hpp"
#include <GUI/game/EntitySprite.hpp>
#include <Entities.hpp>
#include <iostream>
#include <GUI/ui/StateMachine.hpp>
#include <GUI/ui/States/MenuState.hpp>
#include <GUI/ui/States/PlayStates/CharacterChoice.hpp>


ChoosePlay::ChoosePlay(StateMachine& machine, sf::RenderWindow& window, gui::World& world, utils::TextureManager& texture_manager, const bool replace )
	: super(machine, window, world, texture_manager, replace), _animationManager(),_actions(window), _spriteFactory(_world, texture_manager, _animationManager)
{
	
}

void ChoosePlay::pause()
{
}

void ChoosePlay::resume()
{
}

void ChoosePlay::update()
{
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
	//_m_isCharacterSelected = false;

	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		int mouse_x = sf::Mouse::getPosition(_window).x;
		int mouse_y = sf::Mouse::getPosition(_window).y;
		int pos_grille_x = static_cast<int>(((sf::Mouse::getPosition(_window).x) - (0.24 * x)) / 50) * 50 + (0.24 * x);
		int pos_grille_y = static_cast<int>(((sf::Mouse::getPosition(_window).y) - (0.04 * y)) / 50) * 50 + (0.04 * y);
		
		int pos_grid_x = static_cast<int>(((sf::Mouse::getPosition(_window).x) - (0.24 * x)) / 50);
		int pos_grid_y = static_cast<int>(((sf::Mouse::getPosition(_window).y) - (0.04 * y)) / 50);
		
		
		
		
		if (_m_isCharacterSelected)
		{
			for (int i = 0; i < _actions.getSprites().size(); i++)
			{
				if (_actions.getSprites()[i]->getGlobalBounds().contains(mouse_x, mouse_y))
				{
					std::cout << "Sprite " << i << std::endl;
					_m_isCharacterSelected = true;
					std::cout << currentCharacterName << std::endl;
					break;

				}
				else {
					_m_isCharacterSelected = false;
				}
			}
		}
		if (0 <= pos_grid_x && pos_grid_x < 20 && 0 <= pos_grid_y && pos_grid_y < 20)
		{
			if (_world.getGrid()[pos_grid_x][pos_grid_y])
			{
				currentCharacter = _world.getGrid()[pos_grid_x][pos_grid_y];
				currentCharacterName = _world.getGrid()[pos_grid_x][pos_grid_y]->getClass();
				_actions.setText(dynamic_cast<Character*>(currentCharacter));
				_m_isCharacterSelected = true;
			}
		}

		std::cout << _m_isCharacterSelected << std::endl;
		
	}
}


void ChoosePlay::draw()
{
	_window.clear();
	_window.draw(_world);
	if (_m_isCharacterSelected)
	{
		_window.draw(_actions);
	}

	_window.display();
}
