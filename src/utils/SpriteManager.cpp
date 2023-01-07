#include <utils/SpriteManager.hpp> // SpriteManager declarations

void SpriteManager::load() noexcept
{
	_texture_manager.loadTextures();
}

SpriteComponent SpriteManager::get(const char player, std::string_view type) noexcept
{
	return SpriteComponent(_texture_manager.get(player, type));
}
