#pragma once

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <GUI/ui/State.hpp>

class StateMachine;

namespace sf
{
	class RenderWindow;
}

class MenuState final : public State
{
public:
	MenuState(StateMachine& machine, sf::RenderWindow& window, bool replace = true);

	void pause() override;
	void resume() override;

	void update() override;
	void draw() override;

private:
	sf::Texture m_backgroundTexture;
	sf::Sprite m_background;
};
