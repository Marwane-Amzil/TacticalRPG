#include <utils/TextureManager.hpp>
#include <schemas/textures.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <fstream>

utils::TextureManager::TextureManager()
	: _textures() {}

void utils::TextureManager::loadTextures()
{
	std::ifstream infile("assets/data/textures.bin", std::ios::binary | std::ios::in);
	infile.seekg(0, std::ios::end);
	std::streampos length = infile.tellg();
	infile.seekg(0, std::ios::beg);
	char* buffer = new char[length];
	infile.read(buffer, length);
	infile.close();

	auto textures_list = GetTextureRoot(buffer)->textures();

	for (size_t i = 0; i < textures_list->size(); i++)
	{
		sf::Texture* texture = new sf::Texture;
		texture->loadFromFile(textures_list->Get(i)->path()->data());
		_textures[textures_list->Get(i)->type()->data()] = texture;
	}
	
	delete[] buffer;
}

const sf::Texture* utils::TextureManager::get(const std::string& type) const
{
	return _textures.at(type);
}
