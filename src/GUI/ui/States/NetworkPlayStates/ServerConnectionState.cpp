#include <GUI/ui/States/NetworkPlayStates/ServerConnectionState.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <GUI/ui/StateMachine.hpp>
#include <GUI/ui/States/NetworkPlayStates/NetworkCharacterChoice.hpp>
#include <GUI/ui/States/MenuState.hpp>
#include <network.hpp>

ServerConnectionState::ServerConnectionState(StateMachine& machine, sf::RenderWindow& window, gui::World& world, utils::TextureManager& texture_manager, iut::ClientSocket& client, const bool replace)
	: super(machine, window, world, texture_manager, client, replace), _background(), _message_box(), _message_box_texture(), _waiting_text(), _font(), _connection_thread(), _confirmation_thread(), _is_ready(false)
{
	auto [window_x, window_y] = _window.getSize();
	
	_background.setColor(sf::Color::Black);
	_font.loadFromFile("assets/ui/menu/font/Roboto-Bold.ttf");
	_font.setSmooth(true);
	_waiting_text.setString("Connecting to server...");
	_waiting_text.setFont(_font);
	_waiting_text.setCharacterSize(30);
	_message_box_texture.loadFromFile("assets/ui/menu/img/message_box.png");
	_message_box_texture.setSmooth(true);
	_message_box.setTexture(_message_box_texture);
	
	auto [message_box_x, message_box_y] = _message_box.getTexture()->getSize();
	auto [waiting_text_x, waiting_text_y] = _waiting_text.getGlobalBounds().getSize();
	auto [text_left, text_top, text_width, text_height] = _waiting_text.getLocalBounds();	
	
	_message_box.setPosition(window_x / static_cast<float>(2) - message_box_x / static_cast<float>(2), window_y / 2 - message_box_y / 2);
	_waiting_text.setPosition(window_x / static_cast<float>(2) - waiting_text_x / static_cast<float>(2), window_y / 2 - message_box_y / 2 + text_top);
	_waiting_text.setScale(message_box_x / waiting_text_x, message_box_y / waiting_text_y);
}

void ServerConnectionState::pause() {}

void ServerConnectionState::resume() {}

void ServerConnectionState::update()
{
	sf::Event event;

	while (_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			_window.close();
		}

		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				if (_client.isConnected())
				{
					_client.disconnect();
				}

				_machine.run(StateMachine::build<MenuState>(_machine, _window, _world, _texture_manager, _client, true));
			}
		}
	}

	if (!_client.isConnected() && !_connection_thread.joinable())
	{
		_connection_thread = std::thread(&ServerConnectionState::_connectToServer, this);
		_connection_thread.detach();
	}

	if (_client.isConnected() && !_confirmation_thread.joinable())
	{
		_confirmation_thread = std::thread(&ServerConnectionState::_receiveServerConfirmation, this);
		_confirmation_thread.detach();
	}

	if (_is_ready)
	{
		_machine.run(StateMachine::build<NetworkCharacterChoice>(_machine, _window, _world, _texture_manager, _client, _player, true));
	}
}

void ServerConnectionState::_connectToServer()
{
	try
	{
		_client.connect();
		_waiting_text.setString("Connected to server !");
		auto [window_x, window_y] = _window.getSize();
		auto [message_box_x, message_box_y] = _message_box.getTexture()->getSize();
		auto [waiting_text_x, waiting_text_y] = _waiting_text.getGlobalBounds().getSize();
		auto [text_left, text_top, text_width, text_height] = _waiting_text.getLocalBounds();
		_waiting_text.setPosition(window_x / static_cast<float>(2) - waiting_text_x / static_cast<float>(2), window_y / 2 - message_box_y / 2 + text_top);
		_waiting_text.setScale(message_box_x / waiting_text_x, message_box_y / waiting_text_y);
	}
	catch (const std::exception& exc)
	{
		_waiting_text.setString("Connection failed. Retrying...");
		auto [message_box_x, message_box_y] = _message_box.getTexture()->getSize();
		auto [waiting_text_x, waiting_text_y] = _waiting_text.getGlobalBounds().getSize();
		auto [text_left, text_top, text_width, text_height] = _waiting_text.getLocalBounds();
		_waiting_text.setPosition(_window.getSize().x / static_cast<float>(2) - waiting_text_x / static_cast<float>(2), _window.getSize().y / 2 - message_box_y / 2 + text_top);
		_waiting_text.setScale(message_box_x / waiting_text_x, message_box_y / waiting_text_y);
	}
}

void ServerConnectionState::_receiveServerConfirmation()
{
	while (_client.isConnected())
	{
		std::string server_response = _client.receive();

		if (server_response == "STARTCHOICEB" || server_response == "STARTCHOICER")
		{
			size_t size = server_response.size() - 1;
			_player = server_response.at(size);
			_is_ready = true;
		}
	}
}

void ServerConnectionState::draw()
{
	_window.clear();
	_window.draw(_background);
	_window.draw(_message_box);
	_window.draw(_waiting_text);
	_window.display();
}