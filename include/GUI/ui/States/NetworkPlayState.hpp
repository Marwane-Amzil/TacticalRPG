#pragma once

#include <utils/TextureManager.hpp>
#include <utils/SpriteFactory.hpp>
#include <utils/AnimationManager.hpp>
#include <GUI/game/EntitySprite.hpp>
#include <GUI/ui/State.hpp>
#include <array>
#include <GUI/game/World.hpp>
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")


class StateMachine;
namespace sf
{
	class RenderWindow;
}

/* @brief NetworkPlayState class is the base class for all the states of the game.
*  @details This class will theorethically allow all the NetworkPlayState classes to communicate the World.
*/
class NetworkPlayState : public State
{
public:
	/*	@brief Constructor of the NetworkPlayState class.
	*	@param machine The StateMachine that will be used to change the state of the game.
	*	@param window The window that will be used to display the game.
	*	@param replace If true, the current state will be replaced by the new one.
	*	@see StateMachine
	*	@see sf::RenderWindow
	*	@see State
	*	@see gui::World
	*	@see gui::EntitySprite
	*/
	explicit NetworkPlayState(StateMachine& machine, sf::RenderWindow& window, gui::World& world, utils::TextureManager& texture_manager, const bool replace = true);

private:

	/*	@brief The super class of the NetworkPlayState class.
	*	@details This is used to call the super class methods.
	*/
	typedef State super;
protected:

	gui::World& _world;
	utils::TextureManager& _textureManager;

public:
	SOCKET createSocket();
	bool connectSocket(SOCKET sockfd, const char* ip, const char* port);
	bool sendMessage(SOCKET sockfd, const char* message);
	char* receiveMessage(SOCKET sockfd, char* buffer, int buffer_size);
	char* intToChar(int i);
};