#pragma once

#include <utils/TextureManager.hpp>
#include <utils/SpriteFactory.hpp>
#include <utils/AnimationManager.hpp>
#include <GUI/game/EntitySprite.hpp>
#include <GUI/ui/State.hpp>
#include <array>
#include <GUI/game/World.hpp>

class StateMachine;
namespace sf
{
	class RenderWindow;
}

/* @brief PlayState class is the base class for all the states of the game. 
*  @details This class will theorethically allow all the PlayState classes to communicate the World. 
*/
class PlayState : public State
{
public:
	/*	@brief Constructor of the PlayState class.
	*	@param machine The StateMachine that will be used to change the state of the game.
	*	@param window The window that will be used to display the game.
	*	@param replace If true, the current state will be replaced by the new one.
	*	@see StateMachine
	*	@see sf::RenderWindow
	*	@see State
	*	@see gui::World
	*	@see gui::EntitySprite
	*/
	PlayState(StateMachine& machine, sf::RenderWindow& window, bool replace = true);

private:

	/*	@brief The super class of the PlayState class.
	*	@details This is used to call the super class methods.
	*/
	typedef State super;
protected:

	gui::World _world;
	utils::TextureManager _textureManager;
	utils::AnimationManager _animationManager;
	utils::SpriteFactory _spriteFactory;
	
};
