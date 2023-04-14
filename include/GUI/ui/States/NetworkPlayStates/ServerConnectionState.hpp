#pragma once

#ifndef __SERVER_CONNECTION_STATE_H__
#define __SERVER_CONNECTION_STATE_H__

#include <GUI/ui/States/NetworkState.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <thread>

class StateMachine;

class ServerConnectionState final : public NetworkState
{
public:

	explicit ServerConnectionState(StateMachine& machine, sf::RenderWindow& window, gui::World& world, utils::TextureManager& texture_manager, iut::ClientSocket& client, const bool replace = true);

	void pause() override;

	void resume() override;

	void update() override;

	void draw() override;

private:

	void _connectToServer();

	void _receiveServerConfirmation();

private:
	
	using super = NetworkState;

private:

    sf::Sprite _background;

	sf::Sprite _message_box;

	sf::Texture _message_box_texture;

	sf::Text _waiting_text;

	sf::Font _font;

	std::thread _connection_thread;

	std::thread _confirmation_thread;

	char _player;

	bool _is_ready;
};

#endif // !__SERVER_CONNECTION_STATE_H__