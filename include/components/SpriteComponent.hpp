#pragma once

#ifndef __SPRITE_H__
#define __SPRITE_H__

#include <SFML/Graphics/Sprite.hpp> // sf::Sprite
#include <SFML/Graphics/Texture.hpp> // sf::Texture
#include <SFML/Graphics/RenderTarget.hpp> // sf::RenderTarget

struct SpriteComponent
{	
	sf::Sprite sprite;
	const sf::Texture& texture;

	inline explicit SpriteComponent(const sf::Texture& _Texture) noexcept
		: texture(_Texture)
	{
		sprite.setTexture(texture);
	}

	inline operator const sf::Sprite&() const
	{
		return sprite;
	}
};

#endif // !__SPRITE_H__