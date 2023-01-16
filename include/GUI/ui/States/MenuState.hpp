#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include <GUI/ui/State.hpp>

class StateMachine;

namespace sf
{
	class RenderWindow;
    class Font;
    class Texture;
    class Sprite;
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
    
    int _pos;
    bool _pressed, theselect;


    // Menu objects. That will be used in our menu.
    // Rectangle that will be the buttons
    sf::RectangleShape* _winclose;
    // The font used
    sf::Font* _font;
    // Contains the images
    sf::Texture* _image;
    // Constains the sprites

    //sf::Vector2i (ou sf::Vector2<int>) est utile lorsqu'on a besoin d'une position en pixels par exemple (donc un nombre entier).
    //sf::Vector2u(ou sf::Vector2<unsigned>) est utile lorsqu'on a besoin d'une position de souris 
        //par exemple(la souris ne sort pas de l'écran et aura donc toujours une position positive).
    sf::Vector2i _pos_mouse;
    sf::Vector2f _mouse_coord;

    // Constainer the options
    std::vector<const char*> _options;
    // Container of the mouse coords
    std::vector<sf::Vector2f> _coords;
    // Container of the texts
    std::vector<sf::Text> _texts;
    // Container of the sizes
    std::vector<std::size_t> _sizes;

};
