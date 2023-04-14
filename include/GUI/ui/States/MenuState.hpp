#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include <array>
#include <GUI/ui/Button.hpp>
#include <GUI/ui/State.hpp>
#include <GUI/game/World.hpp>
#include <utils/TextureManager.hpp>

class StateMachine;

namespace sf
{
	class RenderWindow;
    class Font;
    class Texture;
    class Sprite;
}

namespace iut
{
	class ClientSocket;
}

class MenuState final : public State
{
public:
	
    explicit MenuState(StateMachine& machine, sf::RenderWindow& window, gui::World& world, utils::TextureManager& texture_manager, iut::ClientSocket& client, const bool replace = true);

	void pause() override;
	void resume() override;

	void update() override;
	void draw() override;

private:
    
    gui::World& _world;
	utils::TextureManager& _texture_manager;
	iut::ClientSocket& _client;
	sf::Texture m_backgroundTexture;
	// Constains the sprites of the menu
	sf::Sprite m_background;
    
    int _pos;
    bool _pressed, theselect;


    // Menu objects. That will be used in our menu.
    // Rectangle that will be the buttons
    sf::RectangleShape* _winclose;
    // The font used
    sf::Font* _font;
    // Contains the images
    sf::Texture* _image;
    // Contains the closing image
    sf::Texture* _closingImage;
    
    //sf::Vector2i (ou sf::Vector2<int>) est utile lorsqu'on a besoin d'une position en pixels par exemple (donc un nombre entier).
    //sf::Vector2u(ou sf::Vector2<unsigned>) est utile lorsqu'on a besoin d'une position de souris 
    //par exemple(la souris ne sort pas de l'�cran et aura donc toujours une position positive).
    sf::Vector2i _pos_mouse;
    
    sf::Vector2f _mouse_coord;

    // Array of buttons
	std::array<gui::Button, 4> _buttons;
    // Container the options
    std::vector<const char*> _options;
    // Container of the mouse coords
    std::vector<sf::Vector2f> _coords;
    // Container of the texts
    std::vector<sf::Text> _texts;
    // Container of the sizes
    std::vector<std::size_t> _sizes;

};
