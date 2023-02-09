#include "GUI/ui/States/PlayStates/ChoosePlay.hpp"
#include <GUI/game/EntitySprite.hpp>
#include <Skill.hpp>
#include <Entities.hpp>
#include <iostream>
#include <GUI/ui/StateMachine.hpp>
#include <GUI/ui/States/MenuState.hpp>
#include <GUI/ui/States/PlayStates/CharacterChoice.hpp>


ChoosePlay::ChoosePlay(StateMachine& machine, sf::RenderWindow& window, gui::World& world, utils::TextureManager& texture_manager, const bool replace )
	: super(machine, window, world, texture_manager, replace), _animationManager(),_actions(window), _zones(window), _spriteFactory(_world, texture_manager, _animationManager)
{
	for (auto& row : _world.getSprites())
	{
		for (auto& sprite : row)
		{
			if (sprite)
			{
				sprite->setCurrentAnimation(7);
				sprite->loopCurrentAnimation(true);
				sprite->playAnimation();
			}
		}
	}
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
					_m_isCharacterSelected = true;
					std::cout << currentEntity->getHp() << std::endl;
					if (i == 0)
					{
						_zones.setZones((dynamic_cast<Character*>(currentEntity)), _world.getGrid());
						_m_isMoovement = true;
						
					}
					if (i == 2)
					{
						bool wait = false;
						Character* currentCharacter = dynamic_cast<Character*>(currentEntity);
						characterSkill = currentCharacter->getFirstSkill();

						while (!wait) {
							sf::Vector2i vector = sf::Mouse::getPosition();
							wait = ((_world.getShape().getGlobalBounds().contains(sf::Mouse::getPosition(_window).x, sf::Mouse::getPosition(_window).y))) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
						}
						wait = false;
						pos_grid_x = static_cast<int>(((sf::Mouse::getPosition(_window).x) - (0.24 * x)) / 50);
						pos_grid_y = static_cast<int>(((sf::Mouse::getPosition(_window).y) - (0.04 * y)) / 50);
						
						if (_world.getGrid()[pos_grid_x][pos_grid_y])
						{
							Character* characterTarget = dynamic_cast<Character*>(_world.getGrid()[pos_grid_x][pos_grid_y]);
							
							if (characterTarget->getPlayer() != currentCharacter->getPlayer())
							{
								std::cout << "You attack" << std::endl;
								std::cout << "HP before : " << characterTarget->getHp() << std::endl;
								currentCharacter->getFirstSkill()->activate(_world.getGrid(), characterTarget);
								std::cout << "HP after : " << characterTarget->getHp() << std::endl;
							}
							else
							{
								std::cout << "You can't attack your own character" << std::endl;
							}
						}
						else
						{
							std::cout << "You can't attack an empty case" << std::endl;

						}
					}

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
				currentEntity = _world.getGrid()[pos_grid_x][pos_grid_y];
				currentCharacterName = _world.getGrid()[pos_grid_x][pos_grid_y]->getClass();
				_actions.setText(dynamic_cast<Character*>(currentEntity));


				_m_isCharacterSelected = true;
			}
		}
	}

	for (auto& row : _world.getSprites())
	{
		for (auto& sprite : row)
		{
			if (sprite)
			{
				sprite->update(_clock.getElapsedTime());
			}
		}
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

	if (_m_isMoovement)
	{
		_window.draw(_zones);
	}
	
	_window.display();
}
