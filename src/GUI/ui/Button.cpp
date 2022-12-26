#include <GUI/ui/Button.hpp> // Button
#include <SFML/Graphics/RoundedRectangleShape.hpp> // sf::RoundedRectangleShape
#include <SFML/Graphics/RenderTarget.hpp> // sf::RenderTarget
#include <SFML/Graphics/Texture.hpp> // sf::Texture
#include <SFML/Window/Mouse.hpp> // sf::Mouse

namespace gui
{
	Button::Button(const sf::Vector2f& size, const sf::Texture* idle_texture, const sf::Texture* hover_texture, const sf::Texture* press_texture)
		: _shape(size, 5.0f, 4), _textures(), _state(State::Idle)
	{
		_textures[0] = idle_texture;
		_textures[1] = hover_texture;
		_textures[2] = press_texture;
		_shape.setTexture(_textures[0]);
	}

	float Button::getCornersRadius() const
	{
		return _shape.getCornersRadius();
	}

	const sf::Texture* Button::getIdleTexture() const
	{
		return _textures[0];
	}

	const sf::Texture* Button::getHoverTexture() const
	{
		return _textures[1];
	}

	const sf::Texture* Button::getPressTexture() const
	{
		return _textures[2];
	}

	const sf::Vector2f& Button::getPosition() const
	{
		return _shape.getPosition();
	}

	const sf::Vector2f& Button::getSize() const
	{
		return _shape.getSize();
	}

	bool Button::isHovered() const
	{
		return _state == State::Hovered;
	}

	bool Button::isPressed() const
	{
		return _state == State::Pressed;
	}

	void Button::setCornerRadius(float radius)
	{
		_shape.setCornersRadius(radius);
	}

	void Button::setCornerPointCount(unsigned int count)
	{
		_shape.setCornerPointCount(count);
	}

	void Button::setIdleTexture(const sf::Texture* idle_texture)
	{
		_textures[0] = idle_texture;
	}

	void Button::setHoverTexture(const sf::Texture* hover_texture)
	{
		_textures[1] = hover_texture;
	}

	void Button::setPressTexture(const sf::Texture* press_texture)
	{
		_textures[2] = press_texture;
	}

	void Button::setPosition(const sf::Vector2f& position)
	{
		_shape.setPosition(position);
	}

	void Button::setPosition(float x, float y)
	{
		_shape.setPosition(x, y);
	}

	void Button::setSize(const sf::Vector2f& size)
	{
		_shape.setSize(size);
	}

	void Button::setSize(float width, float height)
	{
		_shape.setSize(sf::Vector2f(width, height));
	}

	void Button::setOutlineThickness(float thickness)
	{
		_shape.setOutlineThickness(thickness);
	}

	void Button::setOutlineColor(const sf::Color& color)
	{
		_shape.setOutlineColor(color);
	}

	void Button::update(const sf::Vector2i& mouse_position)
	{
		_state = State::Idle;
		_shape.setTexture(_textures[0]);

		if (_shape.getGlobalBounds().contains(mouse_position.x, mouse_position.y))
		{
			_state = State::Hovered;
			_shape.setTexture(_textures[1]);

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				_state = State::Pressed;
				_shape.setTexture(_textures[2]);
			}
		}
	}

	void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(_shape, states);
	}
}
