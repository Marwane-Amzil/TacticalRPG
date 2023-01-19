#include <GUI/game/EntitySprite.hpp> // gui::EntitySprite
#include <GUI/game/Animation.hpp> // gui::Animation
#include <SFML/Graphics/Texture.hpp> // sf::Texture
#include <SFML/Graphics/RenderTarget.hpp> // sf::RenderTarget
#include <Entity.hpp> // Entity

namespace gui
{
	EntitySprite::EntitySprite(Entity* entity)
		: _vertices(), _texture(nullptr), _texture_rect(), _entity(entity), _animations(), _current_animation(_animations[0]) {}

	EntitySprite::EntitySprite(const EntitySprite& other)
		: sf::Transformable(other),  _vertices(other._vertices), _texture(other._texture), _texture_rect(other._texture_rect), _entity(other._entity), _animations(other._animations), _current_animation(other._current_animation) {}
		
	EntitySprite::EntitySprite(EntitySprite&& other) noexcept
		: _vertices(std::move(other._vertices)), _texture(std::move(other._texture)), _texture_rect(std::move(other._texture_rect)), _entity(other._entity), _animations(std::move(other._animations)), _current_animation(other._current_animation)
	{
		other._entity = nullptr;
	}

	Entity* EntitySprite::getEntity() const
	{
		return _entity;
	}

	const Animation& EntitySprite::getAnimation(size_t index) const
	{
		return _animations[index];
	}

	const Animation& EntitySprite::getCurrentAnimation() const
	{
		return _current_animation;
	}

	const sf::Texture* EntitySprite::getTexture() const
	{
		return _texture;
	}

	const sf::IntRect& EntitySprite::getTextureRect() const
	{
		return _texture_rect;
	}

	sf::FloatRect EntitySprite::getLocalBounds() const
	{
		return sf::FloatRect(0.f, 0.f, static_cast<float>(std::abs(_texture_rect.width)), static_cast<float>(std::abs(_texture_rect.height)));
	}

	sf::FloatRect EntitySprite::getGlobalBounds() const
	{
		return getTransform().transformRect(getLocalBounds());
	}

	void EntitySprite::addAnimation(size_t index, const Animation& animation)
	{
		_animations[index] = animation;
	}

	void EntitySprite::setCurrentAnimation(size_t index)
	{
		_current_animation = _animations[index];
	}

	void EntitySprite::setTexture(const sf::Texture* texture)
	{
		if (_texture != texture)
		{
			setTextureRect(sf::IntRect(0, 0, texture->getSize().x, texture->getSize().y));
			_texture = texture;
		}
	}

	void EntitySprite::setTextureRect(const sf::IntRect& texture_rect)
	{
		if (_texture_rect != texture_rect)
		{
			_texture_rect = texture_rect;

			_vertices[0].position = sf::Vector2f(0.f, 0.f);
			_vertices[1].position = sf::Vector2f(0.f, getLocalBounds().height);
			_vertices[2].position = sf::Vector2f(getLocalBounds().width, 0.f);
			_vertices[3].position = sf::Vector2f(getLocalBounds().width, getLocalBounds().height);

			_vertices[0].texCoords = sf::Vector2f(_texture_rect.left, _texture_rect.top);
			_vertices[1].texCoords = sf::Vector2f(_texture_rect.left, _texture_rect.top + _texture_rect.height);
			_vertices[2].texCoords = sf::Vector2f(_texture_rect.left + _texture_rect.width, _texture_rect.top);
			_vertices[3].texCoords = sf::Vector2f(_texture_rect.left + _texture_rect.width, _texture_rect.top + _texture_rect.height);
		}
	}

	void EntitySprite::setTextureRect(int x, int y, int width, int height)
	{
		setTextureRect(sf::IntRect(x, y, width, height));
	}

	void EntitySprite::loopCurrentAnimation(bool loop)
	{
		_current_animation.setLoop(loop);
	}

	void EntitySprite::playAnimation()
	{
		_current_animation.play();
	}

	void EntitySprite::stopAnimation()
	{
		_current_animation.stop();
	}

	void EntitySprite::update(sf::Time elapsed_time)
	{
		_current_animation.update(elapsed_time);
		setTextureRect(_current_animation.getCurrentFrame());
	}

	EntitySprite::~EntitySprite() noexcept
	{
		delete _entity;
	}

	void EntitySprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		if (_texture)
		{
			states.transform *= getTransform();
			states.texture = _texture;
			target.draw(_vertices.data(), 4, sf::TriangleStrip, states);
		}
	}

	EntitySprite& EntitySprite::operator=(const EntitySprite& other)
	{
		if (this != &other)
		{
			// copy the transform
			setPosition(other.getPosition());
			setRotation(other.getRotation());
			setScale(other.getScale());
			setOrigin(other.getOrigin());
			
			// copy the sprite's attributes
			_vertices = other._vertices;
			_texture = other._texture;
			_texture_rect = other._texture_rect;
			_entity = other._entity;
			_animations = other._animations;
			_current_animation = other._current_animation;
		}

		return *this;
	}

	EntitySprite& EntitySprite::operator=(EntitySprite&& other) noexcept
	{
		if (this != &other)
		{
			_vertices = std::move(other._vertices);
			_texture = other._texture;
			_texture_rect = other._texture_rect;
			_entity = other._entity;
			_animations = std::move(other._animations);
			_current_animation = std::move(other._current_animation);

			other._entity = nullptr;
		}

		return *this;
	}
}
