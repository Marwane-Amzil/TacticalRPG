#pragma once

#ifndef __BUTTON_H__
#define __BUTTON_H__

#include <SFML/Graphics/RoundedRectangleShape.hpp>

namespace sf
{
    class Texture;
}

namespace gui
{
    namespace Style
    {
        enum : uint8_t
        {
            Idle = '0',
            Hovered = '1',
            Pressed = '2'
        };
    }

    class Button : public sf::Drawable
    {
    public:

        explicit Button(const sf::Vector2f& size = sf::Vector2f(150, 100), const sf::Texture* idle_texture = nullptr, const sf::Texture* hover_texture = nullptr, const sf::Texture* press_texture = nullptr);

        const sf::Texture* getIdleTexture() const;

        const sf::Texture* getHoverTexture() const;
        
        const sf::Texture* getPressTexture() const;

        const sf::Vector2f& getPosition() const;

        const sf::Vector2f& getSize() const;

        bool isHovered() const;

        bool isPressed() const;

        void setIdleTexture(const sf::Texture* idle_texture);

        void setHoverTexture(const sf::Texture* hover_texture);

        void setPressTexture(const sf::Texture* press_texture);

        void setSize(const sf::Vector2f& size);

        void setSize(const int w, const int h);

        void setPosition(const sf::Vector2f& position);

        void setPosition(const int x, const int y);

        void update(const sf::Vector2i& mouse_position);

        inline virtual ~Button() noexcept = default;

    private:

        void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const override;

    private:

        sf::RoundedRectangleShape _shape;
        const sf::Texture* _idle_texture;
        const sf::Texture* _hover_texture;
        const sf::Texture* _press_texture;
        uint8_t _state;
    };
}

#endif // !__BUTTON_H__
