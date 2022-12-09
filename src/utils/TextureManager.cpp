#include <utils/TextureManager.hpp>
#include <schemas/textures.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <fstream>

utils::TextureManager::TextureManager()
	: _textures() {}

void utils::TextureManager::loadTextures()
{
	std::ifstream infile("./assets/data/textures.bin", std::ios::binary | std::ios::in);
	infile.seekg(0, std::ios::end);
	std::streampos length = infile.tellg();
	infile.seekg(0, std::ios::beg);
	char* buffer = new char[length];
	infile.read(buffer, length);
	infile.close();

	textures_rootT* textures_r = Gettextures_root(buffer)->UnPack();

	for (const std::unique_ptr<textureT>& texture_pack : textures_r->textures)
	{
		sf::Texture* texture = new sf::Texture;
		texture->loadFromFile(texture_pack->path);
		_textures[texture_pack->type] = texture;
	}

	delete[] buffer;
}

const sf::Texture& utils::TextureManager::get(const std::string& type) const
{
	return *_textures.at(type);
}
