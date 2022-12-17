#pragma once

#ifndef __ENTITY_SPRITE_H__
#define __ENTITY_SPRITE_H__

#include <SFML/Graphics/Drawable.hpp> // sf::Drawable
#include <SFML/Graphics/Transformable.hpp> // sf::Transformable
#include <SFML/Graphics/Vertex.hpp> // sf::Vertex
#include <SFML/Graphics/Rect.hpp> // sf::IntRect, sf::FloatRect
#include <array> // std::array

class Entity;

namespace sf
{
	class Texture;
}

namespace gui
{
	class Animation;

	class EntitySprite : public sf::Drawable, public sf::Transformable
	{
	public:

		explicit EntitySprite(Entity* entity = nullptr);

		Entity* getEntity() const;

		const sf::Texture* getTexture() const;

		const sf::IntRect& getTextureRect() const;

		sf::FloatRect getLocalBounds() const;

		sf::FloatRect getGlobalBounds() const;

		void setTexture(const sf::Texture* texture);

		void setTextureRect(const sf::IntRect& texture_rect);

		void setTextureRect(int x, int y, int width, int height);

		virtual ~EntitySprite() noexcept;

	private:

		void updatePositions();

		void updateTexCoords();

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	private:

		std::array<sf::Vertex, 4> _vertices;   // The vertices of the sprite.
		const sf::Texture* _texture;		   // The texture of the sprite.
		sf::IntRect _texture_rect;			   // The sub-rectangle of the texture to display.
		Entity* _entity;					   // The entity that the sprite is representing.
		std::array<Animation*, 4> _animations; // The animations of the sprite.
	};
}

#endif // !__ENTITY_SPRITE_H__