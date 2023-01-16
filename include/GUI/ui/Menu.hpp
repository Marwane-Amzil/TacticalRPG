#pragma once

#ifndef __MENU_H__
#define __MENU_H__

#include <SFML/Graphics.hpp>
#include <iostream>

namespace gui
{   /**
    * @brief The Menu class.
    * The only way to navigate will be by keyboard
    * (Maybe later the possibility to naviguate by mouse will be added)
    * This class is the menu, the goal of the menu is to allow:
    *   - Get to the start a game page
    *   - Options
    *   - About Game
    *   - Leave / Exit
    */
    class Menu
    {

        int pos;
        bool pressed, theselect;


        // Menu objects. That will be used in our menu.
        // Rectangle that will be the buttons
        sf::RectangleShape* _winclose;
        // The font used
        sf::Font* _font;
        // Contains the images
        sf::Texture* _image;
        // Constains the sprites
        sf::Sprite* _bg;

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

    protected:

        /**
        * @brief Method that initialise all the different values.
        * Only creates the objects. Nothing else. It doesn't initialise anything.
        *
        */
        void set_values();
        void loop_events();
        void draw_all();

    public:
        /**
        * @brief Default Constructor
        * Only creates the objects. Nothing else. It doesn't initialise anything.
        *
        */
        Menu();
        /**
        * @brief Destructor
        * Deletes the object and it's objects.
        *
        */
        ~Menu();
        void run_menu();
    };
}

#endif // !__MENU_H__