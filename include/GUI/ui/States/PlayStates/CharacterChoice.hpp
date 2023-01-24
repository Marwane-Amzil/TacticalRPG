

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include <array>
#include <GUI/ui/Button.hpp>
#include <GUI/ui/State.hpp>
#include <GUI/ui/States/PlayState.hpp>


class StateMachine;

namespace sf
{
	class RenderWindow;
	class Font;
	class Texture;
	class Sprite;
}
class CharacterChoice : public PlayState
	{
public:
	CharacterChoice(StateMachine& machine, sf::RenderWindow& window, bool replace = true);

	void pause() override;
	void resume() override;

	void update() override;
	void draw() override;

private:
	typedef PlayState super;


	
	sf::Texture _m_backgroundTexture;
	sf::Sprite _m_background;
		
	sf::Vector2i _pos_mouse;
	sf::Vector2f _mouse_coord;
	std::array<gui::EntitySprite*, 4> m_characters;
		
};

