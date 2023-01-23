#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <GUI/ui/State.hpp>
#include <utils/TextureManager.hpp>
#include <GUI/game/EntitySprite.hpp>
#include <array>
#include <GUI/game/World.hpp>

class StateMachine;
namespace sf
{
	class RenderWindow;
}

class PlayState : public State
{
public:
	PlayState(StateMachine& machine, sf::RenderWindow& window, bool replace = true);
	
	gui::World getWorld() const;


private:
	typedef State super;
	
	gui::World _world;
};
