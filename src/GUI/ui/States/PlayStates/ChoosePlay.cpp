#include "GUI/ui/States/PlayStates/ChoosePlay.hpp"
#include <GUI/game/EntitySprite.hpp>
#include <Skill.hpp>
#include <Entities.hpp>
#include <iostream>
#include <GUI/ui/StateMachine.hpp>
#include <GUI/ui/States/MenuState.hpp>
#include <GUI/ui/States/PlayStates/CharacterChoice.hpp>


ChoosePlay::ChoosePlay(StateMachine& machine, sf::RenderWindow& window, gui::World& world, utils::TextureManager& texture_manager, const bool replace )
	: super(machine, window, world, texture_manager, replace), _animationManager(),_actions(window), _movements(window), _spriteFactory(_world, texture_manager, _animationManager)
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



		// If we have selected a character.
		if (_m_isCharacterSelected)
		{
			// For each action button
			for (int i = 0; i < _actions.getSprites().size(); i++)
			{
				// If we click on an action button
				if (_actions.getSprites()[i]->getGlobalBounds().contains(mouse_x, mouse_y))
				{
					// We put The Boolean to true, because we have selected an action.
					_m_isCharacterSelected = true;
					// If we have clicked on Moove.
					if (i == 0) // Moove
					{
						// Drawing the zones where the character can go.
						_movements.showMovingZones(_window,(dynamic_cast<Character*>(currentEntity)), _world.getGrid());
						_m_isMoovement = true;
						this->draw();

						// Click Looker. 
						// Checking for a click on the grid.	
						bool wait = false;
						while (!wait) {
							sf::Vector2i vector = sf::Mouse::getPosition();
							wait = ((_world.getShape().getGlobalBounds().contains(sf::Mouse::getPosition(_window).x, sf::Mouse::getPosition(_window).y))) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
						}
						wait = false;
						// End Click Looker
						// Getting the position of the click on the grid.
						
						Character* currentCharacter = dynamic_cast<Character*>(currentEntity);
						// If we can move to the position we clicked on.

						pos_grid_x = static_cast<int>(((sf::Mouse::getPosition(_window).x) - (0.24 * x)) / 50);
						pos_grid_y = static_cast<int>(((sf::Mouse::getPosition(_window).y) - (0.04 * y)) / 50);

						if ((dynamic_cast<Character*>(currentEntity)->canMove(_world.getGrid(),pos_grid_x,pos_grid_y) ))
						{

							int pos_X_Init = window_click_x ;
							int pos_Y_Init = window_click_y;

							std::cout << "pos_X_Init : " << pos_X_Init << "pos_Y_Init : " << pos_Y_Init << std::endl;
							// Moving the character.
							int pos_arrival_x = static_cast<int>(((sf::Mouse::getPosition(_window).x)));
							int pos_arrival_y = static_cast<int>(((sf::Mouse::getPosition(_window).y)));
							/*
							int pos_X_arrival = pos_grid_x * 50 + (0.24 * x);
							int pos_Y_arrival = pos_grid_y * 50 + (0.04 * y);
							*/
							std::cout << " pos_grille_x " << pos_arrival_x << "pos_grille_y" << pos_arrival_y << std::endl;
							_world.getGrid().move(currentCharacter->getPosition().getX(), currentCharacter->getPosition().getY(), pos_grid_x, pos_grid_y);
							
							_world[currentCharacter->getPosition().getX()][currentCharacter->getPosition().getY()]->move(sf::Vector2f( pos_arrival_x - pos_X_Init, pos_arrival_y - pos_Y_Init));//.move(pos_X_Init - pos_X_arrival, pos_Y_Init - pos_Y_arrival);
							std::cout << "Move" << std::endl;
							_m_isMoovement = false;
						}
						else
						{
							_m_isMoovement = false;
						}
						
					}
					if (i == 2) // First Attack
					{
						//Getting the current character as a character Class, and not an Entity. 
						Character* currentCharacter = dynamic_cast<Character*>(currentEntity);
						// Getting the first skill of the character.
						characterSkill = currentCharacter->getFirstSkill();


						// Drawing the zones where the character can attack.
						_movements.showAttackZones(_window,characterSkill, _world.getGrid());
						_m_isAttack = true;
						
						//this->draw();


						// Click Looker. 
						// Checking for a click on the grid.
						bool wait = false;
						while (!wait) {
							sf::Vector2i vector = sf::Mouse::getPosition();
							wait = ((_world.getShape().getGlobalBounds().contains(sf::Mouse::getPosition(_window).x, sf::Mouse::getPosition(_window).y))) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
						}
						wait = false;

						// End Click Looker
						// Getting the position of the click on the grid.
						int Attack_click_x = static_cast<int>(((sf::Mouse::getPosition(_window).x) - (0.24 * x)) / 50);
						int Attack_click_y = static_cast<int>(((sf::Mouse::getPosition(_window).y) - (0.04 * y)) / 50);
						// Checking if there is a character on the grid.
						if (_world.getGrid()[Attack_click_x][Attack_click_y])
						{
							// Getting the target character on the grid as a character class, and not an Entity.
							Character* characterTarget = dynamic_cast<Character*>(_world.getGrid()[Attack_click_x][Attack_click_y]);
							
							if (currentCharacter->getFirstSkill()->canActivate(_world.getGrid(), characterTarget))
							{	
								std::cout << "You attack" << std::endl;
								currentCharacter->getFirstSkill()->activate(_world.getGrid(), characterTarget);
								_m_isAttack = false;
							}
							else
							{
								std::cout << "You can't attack your own character" << std::endl;
							}
						}
						else
						{
							std::cout << "You can't attack an empty case" << std::endl;
							_m_isAttack = false;
						}
					}// end Moove 2

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

				window_click_x = static_cast<int>(((sf::Mouse::getPosition(_window).x)));
				window_click_y = static_cast<int>(((sf::Mouse::getPosition(_window).y)));

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

	if (_m_isMoovement || _m_isAttack)
	{
		_window.draw(_movements);
	}

	_window.display();
}
