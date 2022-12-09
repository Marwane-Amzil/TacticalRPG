#pragma once

#ifndef __MENU_H__
#define __MENU_H__

#include <SFML/Graphics.hpp>
#include <unordered_map>

namespace gui
{
    class Button;

    class Menu : public sf::Drawable
    {
    public:

        explicit Menu();

        void update();

        inline virtual ~Menu() noexcept;

    private:

        sf::RectangleShape _shape;
        std::unordered_map<gui::Button*, std::vector<sf::Texture*>> _buttons;
    };
}

#endif // !__MENU_H__