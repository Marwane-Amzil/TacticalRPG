#pragma once

#ifndef __SPRITE_MANAGER_H__
#define __SPRITE_MANAGER_H__

#include <unordered_map> // std::unordered_map
#include <string> // std::string

namespace sf
{
	class Texture;
}

namespace utils
{
	class TextureManager
	{
	public:

		TextureManager();

		~TextureManager() noexcept;

		void loadTextures();

		const sf::Texture* get(const std::string& type) const;

	private:

		std::unordered_map<std::string, sf::Texture*> _textures;
	};
}

#endif // !__SPRITE_MANAGER_H__