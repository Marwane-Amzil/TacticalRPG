#include <GUI/game/EntitySprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <Entity.hpp>

gui::EntitySprite::EntitySprite(Entity* entity)
	: _vertices(), _texture(nullptr), _texture_rect(), _entity(entity), _animations() {}

Entity* gui::EntitySprite::getEntity() const
{
	return _entity;
}

const sf::Texture* gui::EntitySprite::getTexture() const
{
	return _texture;
}

const sf::IntRect& gui::EntitySprite::getTextureRect() const
{
	return _texture_rect;
}

sf::FloatRect gui::EntitySprite::getLocalBounds() const
{
	return sf::FloatRect(0.f, 0.f, static_cast<float>(std::abs(_texture_rect.width)), static_cast<float>(std::abs(_texture_rect.height)));
}

sf::FloatRect gui::EntitySprite::getGlobalBounds() const
{
	return getTransform().transformRect(getLocalBounds());
}

void gui::EntitySprite::setTexture(const sf::Texture* texture)
{
	if (_texture != texture)
	{
		setTextureRect(sf::IntRect(0, 0, texture->getSize().x, texture->getSize().y));
		_texture = texture;
	}
}

void gui::EntitySprite::setTextureRect(const sf::IntRect& texture_rect)
{
	if (_texture_rect != texture_rect)
	{
		_texture_rect = texture_rect;
		updatePositions();
		updateTexCoords();
	}
}

void gui::EntitySprite::setTextureRect(int x, int y, int width, int height)
{
	setTextureRect(sf::IntRect(x, y, width, height));
}

void gui::EntitySprite::updatePositions()
{
	_vertices[0].position = sf::Vector2f(0.f, 0.f);
	_vertices[1].position = sf::Vector2f(0.f, getLocalBounds().height);
	_vertices[2].position = sf::Vector2f(getLocalBounds().width, 0.f);
	_vertices[3].position = sf::Vector2f(getLocalBounds().width, getLocalBounds().height);
}

void gui::EntitySprite::updateTexCoords()
{
	_vertices[0].texCoords = sf::Vector2f(_texture_rect.left, _texture_rect.top);
	_vertices[1].texCoords = sf::Vector2f(_texture_rect.left, _texture_rect.top + _texture_rect.height);
	_vertices[2].texCoords = sf::Vector2f(_texture_rect.left + _texture_rect.width, _texture_rect.top);
	_vertices[3].texCoords = sf::Vector2f(_texture_rect.left + _texture_rect.width, _texture_rect.top + _texture_rect.height);
}

gui::EntitySprite::~EntitySprite() noexcept
{
	delete _entity;
}

void gui::EntitySprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (_texture)
	{
		states.transform *= getTransform();
		states.texture = _texture;
		target.draw(_vertices.data(), 4, sf::TriangleStrip, states);
	}
}