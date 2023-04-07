

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include <array>
#include <GUI/ui/Button.hpp>
#include <GUI/ui/State.hpp>
#include <GUI/ui/States/NetworkPlayState.hpp>
#include <GUI/game/World.hpp>
#include <utils/TextureManager.hpp>


class StateMachine;

namespace sf
{
	class RenderWindow;
	class Font;
	class Texture;
	class Sprite;
	class Clock;
}

class NetworkCharacterChoice : public NetworkPlayState
{
public:
	explicit NetworkCharacterChoice(StateMachine& machine, sf::RenderWindow& window, gui::World& world, utils::TextureManager& texture_manager, const bool replace = true);

	void pause() override;
	void resume() override;

	void update() override;
	void draw() override;


private:

	typedef NetworkPlayState super;
	utils::AnimationManager _animationManager;
	utils::SpriteFactory _spriteFactory;
	sf::Texture _m_backgroundTexture;

	int count = 0;
	int color_looker = 2;
	int nb = 0;
	sf::Sprite _m_background;
	sf::Vector2i _pos_mouse;
	sf::Vector2f _mouse_coord;
	gui::EntitySprite* _CurrentCharacter;
	std::array<std::string, 5> _m_characterNames = { "warrior", "archer", "knight", "healer", "mage" };
	std::array<gui::EntitySprite, 5> m_characters_blue;
	std::array<gui::EntitySprite, 5> m_characters_red;

	sf::Clock _clock = sf::Clock();
};

