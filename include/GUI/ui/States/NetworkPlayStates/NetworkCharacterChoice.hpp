#pragma once

#ifndef __NETWORK_CHARACTER_CHOICE_H__
#define __NETWORK_CHARACTER_CHOICE_H__

#include <GUI/ui/States/NetworkState.hpp>
#include <GUI/game/EntitySprite.hpp>
#include <utils/AnimationManager.hpp>
#include <utils/SpriteFactory.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <array>
#include <thread>

class StateMachine;

namespace sf
{
	class RenderWindow;
	class Font;
}

namespace gui
{
	class World;
	class EntitySprite;
}

namespace utils
{
	class TextureManager;
}

class NetworkCharacterChoice : public NetworkState
{
public:

	explicit NetworkCharacterChoice(StateMachine& machine, sf::RenderWindow& window, gui::World& world, utils::TextureManager& texture_manager, iut::ClientSocket& client, const char player, const bool replace = true);

	void pause() override;

	void resume() override;

	void update() override;

	void draw() override;

private:

	void _sendCharacter();

	void _receiveCharacter();
	
private:

	using super = NetworkState;
	
private:
	
	utils::AnimationManager _animationManager;
	
	utils::SpriteFactory _spriteFactory;
	
	sf::Texture _m_backgroundTexture;
	
	uint32_t _count = 0;
	
	int nb = 0;
	
	sf::Sprite _m_background;
	
	sf::Vector2i _pos_mouse;
	
	sf::Vector2f _mouse_coord;
	
	gui::EntitySprite* _CurrentCharacter;
	
	std::array<std::string, 5> _m_characterNames = { "warrior", "archer", "knight", "healer", "mage" };
	
	std::array<gui::EntitySprite, 5> m_characters;

	std::thread _send_thread;

	std::thread _receive_thread;

	char _player;

	std::string _team;

	bool _is_ready;
};

#endif // !__NETWORK_CHARACTER_CHOICE_H__