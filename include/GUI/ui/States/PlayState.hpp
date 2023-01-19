#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <GUI/ui/State.hpp>
#include <utils/TextureManager.hpp>
#include <GUI/game/EntitySprite.hpp>
#include <array>

class StateMachine;

namespace sf
{
	class RenderWindow;
}

class PlayState final : public State
{
public:
	PlayState(StateMachine& machine, sf::RenderWindow& window, bool replace = true);

	void pause() override;
	void resume() override;

	void update() override;
	void draw() override;

private:

	sf::Texture m_backgroundTexture;
	sf::Sprite m_background;
	utils::TextureManager TM;

	int pos_in_list;

	sf::Texture background_texture;
	gui::EntitySprite background_sprite;

	gui::EntitySprite sprite_of_selected_character;

	gui::EntitySprite sknight;
	gui::EntitySprite sarcher;
	gui::EntitySprite shealer;
	gui::EntitySprite smage;
	gui::EntitySprite swarrior;

	std::array<gui::EntitySprite, 10> list_of_sprites;

	char color = 'B';

};
