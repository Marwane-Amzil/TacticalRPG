#include <utils/TextureManager.hpp>
#include <schemas/textures.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <fstream>

utils::TextureManager::TextureManager()
	: _textures() {}

utils::TextureManager::~TextureManager() noexcept
{
	for (auto& [type, texture] : _textures)
	{
		delete texture;
	}
}

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
		
		if (texture->loadFromFile(textures_list->Get(i)->path()->data()))
		{
			_textures[textures_list->Get(i)->type()->data()] = texture;
		}
		else
		{
			_textures[textures_list->Get(i)->type()->data()] = nullptr;
		}
	}
	
	delete[] buffer;
}

const sf::Texture* utils::TextureManager::get(const std::string& type) const
{
	return _textures.at(type);
}
