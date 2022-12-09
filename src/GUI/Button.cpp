#include <GUI/Button.hpp>
#include <SFML/Graphics/RoundedRectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Mouse.hpp>

gui::Button::Button(const sf::Vector2f& size, const sf::Texture* idle_texture, const sf::Texture* hover_texture, const sf::Texture* const press_texture)
	: sf::Drawable(), _shape(size, 5.0f, 4), _idle_texture(idle_texture), _hover_texture(hover_texture), _press_texture(press_texture), _state(Style::Idle)
{
	_shape.setTexture(_idle_texture);
}

const sf::Texture* gui::Button::getIdleTexture() const
{
	return _idle_texture;
}

const sf::Texture* gui::Button::getHoverTexture() const
{
	return _hover_texture;
}

const sf::Texture* gui::Button::getPressTexture() const
{
	return _press_texture;
}

const sf::Vector2f& gui::Button::getPosition() const
{
	return _shape.getPosition();
}

const sf::Vector2f& gui::Button::getSize() const
{
	return _shape.getSize();
}

bool gui::Button::isHovered() const
{
	return _state == Style::Hovered;
}

bool gui::Button::isPressed() const
{
	return _state == Style::Pressed;
}

void gui::Button::setIdleTexture(const sf::Texture* idle_texture)
{
	_idle_texture = idle_texture;
}

void gui::Button::setHoverTexture(const sf::Texture* hover_texture)
{
	_hover_texture = hover_texture;
}

void gui::Button::setPressTexture(const sf::Texture* press_texture)
{
	_press_texture = press_texture;
}

void gui::Button::setSize(const sf::Vector2f& size)
{
	_shape.setSize(size);
}

void gui::Button::setSize(const int w, const int h)
{
	_shape.setSize(sf::Vector2f(w, h));
}

void gui::Button::setPosition(const sf::Vector2f& position)
{
	_shape.setPosition(position);
}

void gui::Button::setPosition(const int x, const int y)
{
	_shape.setPosition(x, y);
}

void gui::Button::update(const sf::Vector2i& mouse_position)
{
	_state = Style::Idle;
	_shape.setTexture(_idle_texture);

	if (_shape.getGlobalBounds().contains(mouse_position.x, mouse_position.y))
	{
		_state = Style::Hovered;
		_shape.setTexture(_hover_texture);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			_state = Style::Pressed;
			_shape.setTexture(_press_texture);
		}
	}
}

void gui::Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_shape, states);
}