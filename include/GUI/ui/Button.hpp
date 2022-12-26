#pragma once

#ifndef __BUTTON_H__
#define __BUTTON_H__

#include <SFML/Graphics/RoundedRectangleShape.hpp> // sf::RoundedRectangleShape
#include <array> // std::array

namespace sf
{
    class Texture;
}

namespace gui
{
    namespace State
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

		float getCornersRadius() const;
        
        const sf::Texture* getIdleTexture() const;

        const sf::Texture* getHoverTexture() const;
        
        const sf::Texture* getPressTexture() const;

        const sf::Vector2f& getPosition() const;

        const sf::Vector2f& getSize() const;

        bool isHovered() const;

        bool isPressed() const;

		void setCornerRadius(float radius);

		void setCornerPointCount(unsigned int count);

        void setIdleTexture(const sf::Texture* idle_texture);

        void setHoverTexture(const sf::Texture* hover_texture);

        void setPressTexture(const sf::Texture* press_texture);

        void setPosition(const sf::Vector2f& position);

        void setPosition(float x, float y);
        
        void setSize(const sf::Vector2f& size);

        void setSize(float width, float height);

		void setOutlineThickness(float thickness);

		void setOutlineColor(const sf::Color& color);

        void update(const sf::Vector2i& mouse_position);

        inline virtual ~Button() noexcept = default;

    private:

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    private:

        sf::RoundedRectangleShape _shape;
        std::array<const sf::Texture*, 3> _textures;
        uint8_t _state;
    };
}

#endif // !__BUTTON_H__
