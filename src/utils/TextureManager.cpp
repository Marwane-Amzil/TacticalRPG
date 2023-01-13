#include <utils/TextureManager.hpp> // TextureManager declarations
#include <schemas/textures.hpp> // schema for texture flatbuffers deserialization
#include <fstream> // std::ifstream

void TextureManager::loadTextures() noexcept
{
	std::ifstream infile("assets/data/textures.bin", std::ios::binary | std::ios::in);
	infile.seekg(0, std::ios::end);
	std::streampos length = infile.tellg();
	infile.seekg(0, std::ios::beg);
	char* buffer = new char[length];
	infile.read(buffer, length);
	infile.close();

	const auto textures_packages = GetTextureRoot(buffer)->textures_sets();

	for (const Set* const& set : *textures_packages)
	{
		const char player = set->player()->data()[0];
		const auto textures = set->textures();

		for (const Texture* const& texture : *textures)
		{
			const char* const type = texture->type()->data();
			const char* const path = texture->path()->data();
			std::unique_ptr<sf::Texture> pTexture = std::make_unique<sf::Texture>();
			pTexture->loadFromFile(path);
			pTexture->setSmooth(true);
			_textures[player][type] = std::move(pTexture);
		}
	}

	delete[] buffer;
}

const sf::Texture* TextureManager::get(const char player, std::string_view type) const
{
	return _textures.at(player).at(type.data()).get();
}
