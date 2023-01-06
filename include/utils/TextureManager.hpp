#pragma once

#ifndef __TEXTURE_MANAGER_H__
#define __TEXTURE_MANAGER_H__

#include <schemas/textures.hpp> // schema for texture flatbuffers deserialization
#include <SFML/Graphics/Texture.hpp> // sf::Texture
#include <map> // std::map
#include <string_view> // std::string_view
#include <string> // std::string

class TextureManager
{
public:
	
	inline TextureManager() = default;

	inline ~TextureManager() noexcept = default;

	void loadTextures() noexcept;

	const sf::Texture* get(const char player, std::string_view type) const;
	
private:

	std::map<char, std::map<std::string, std::unique_ptr<sf::Texture>>> _textures;
};

#endif // !__TEXTURE_MANAGER_H__