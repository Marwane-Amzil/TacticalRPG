#pragma once

#ifndef __SPRITE_MANAGER_H__
#define __SPRITE_MANAGER_H__

#include <utils/TextureManager.hpp> // TextureManager
#include <components/Sprite.hpp> // Sprite

class SpriteManager
{
public:
	
	inline SpriteManager() = default;

	inline ~SpriteManager() noexcept = default;

	void load() noexcept;

	Sprite getSprite(const char player, std::string_view type) noexcept;

private:

	TextureManager _texture_manager;
};

#endif // !__SPRITE_MANAGER_H__