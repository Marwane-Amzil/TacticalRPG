#include "GUI/ui/States/PlayStates/ChoosePlay.hpp"




ChoosePlay::ChoosePlay(StateMachine& machine, sf::RenderWindow& window, gui::World& world, utils::TextureManager& texture_manager, const bool replace)
	: super(machine, window, world, texture_manager, replace), _animationManager(), _spriteFactory(_world, texture_manager, _animationManager)	
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
	
}

void ChoosePlay::draw()
{
	_window.clear();
	_window.draw(_world);
	_window.display();
}
