#pragma once

#ifndef __SPRITE_MANAGER_H__
#define __SPRITE_MANAGER_H__

#include <map>
#include <string>

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

		inline ~TextureManager() noexcept = default;

		void loadTextures();

		const sf::Texture& get(const std::string& type) const;

	private:

		std::map<std::string, sf::Texture*> _textures;
	};
}

#endif // !__SPRITE_MANAGER_H__