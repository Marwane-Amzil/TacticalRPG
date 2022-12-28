#pragma once

#ifndef __SPRITE_MANAGER_H__
#define __SPRITE_MANAGER_H__

#include <map> // std::map
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

		const std::map<std::string, sf::Texture*>& getTextures(char player) const;

		const sf::Texture* getTextureAt(char player, std::string_view type) const;

	private:

		std::map<char, std::map<std::string, sf::Texture*>> _textures;
	};
}

#endif // !__SPRITE_MANAGER_H__