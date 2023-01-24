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
: super{ machine, window, replace }, _world(_window), _spriteFactory(_world, _textureManager, _animationManager)
{
}