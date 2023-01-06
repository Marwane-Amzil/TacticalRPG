#include <utils/SpriteManager.hpp>
#include <components/Sprite.hpp>

void SpriteManager::load() noexcept
{
	_texture_manager.loadTextures();
}

Sprite SpriteManager::getSprite(const char player, std::string_view type) noexcept
{
	Sprite sprite(_texture_manager.get(player, type));
	return sprite;
}
