#pragma once

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <GUI/ui/State.hpp>
#include <GUI/game/World.hpp>
#include <utils/TextureManager.hpp>

class StateMachine;

namespace sf
{
	class RenderWindow;
}

namespace iut
{
	class ClientSocket;
}

class IntroState final : public State
{
public:
	
	explicit IntroState(StateMachine& machine, sf::RenderWindow& window, gui::World& world, utils::TextureManager& texture_manager, iut::ClientSocket& client, const bool replace = true);

	void pause() override;
	void resume() override;

	void update() override;
	void draw() override;

private:
	
	gui::World& _world;
	utils::TextureManager& _texture_manager;
	iut::ClientSocket& _client;
	sf::Texture m_backgroundTexture;
	sf::Sprite m_background;
	sf::RectangleShape m_fader;
	sf::Color m_alpha;
};
