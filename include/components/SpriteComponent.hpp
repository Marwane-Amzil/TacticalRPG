#pragma once

#ifndef __SPRITE_H__
#define __SPRITE_H__

#include <SFML/Graphics/Sprite.hpp> // sf::Sprite
#include <SFML/Graphics/Texture.hpp> // sf::Texture

struct SpriteComponent
{	
	sf::Sprite sprite;
	const sf::Texture* texture;

	inline explicit SpriteComponent(const sf::Texture* _Texture = nullptr, const sf::IntRect _Rect = sf::IntRect(0, 645, 60, 65))
		: texture(_Texture)
	{
		if (_Texture)
		{
			sprite.setTexture(*texture);
		}
		sprite.setTextureRect(_Rect);
	}

	inline void setPosition(const sf::Vector2f& _Position)
	{
		sprite.setPosition(_Position);
	}

	inline operator const sf::Sprite&() const
	{
		return sprite;
	}
};

#endif // !__SPRITE_H__