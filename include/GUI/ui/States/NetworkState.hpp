#pragma once

#ifndef __NETWORK_STATE_H__
#define __NETWORK_STATE_H__

#include <GUI/ui/State.hpp>

class StateMachine;

namespace sf
{
	class RenderWindow;
}

namespace gui
{
	class World;
}

namespace utils
{
	class TextureManager;
}

namespace iut
{
	class ClientSocket;
}

class NetworkState : public State
{
public:
	
	explicit NetworkState(StateMachine& machine, sf::RenderWindow& window, gui::World& world, utils::TextureManager& texture_manager, iut::ClientSocket& client, const bool replace = true);
	
private:
	
	using super = State;

protected:

	gui::World& _world;
	
	utils::TextureManager& _texture_manager;

	iut::ClientSocket& _client;
};

#endif // !__NETWORK_STATE_H__