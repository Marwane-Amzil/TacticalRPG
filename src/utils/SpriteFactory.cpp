#include <utils/SpriteFactory.hpp>
#include <utils/TextureManager.hpp>
#include <GUI/game/World.hpp>
#include <GUI/game/EntitySprite.hpp>
#include <Entity.hpp>

utils::SpriteFactory::SpriteFactory(gui::World& world, TextureManager& texture_manager)
	: _world(world), _texture_manager(texture_manager)
{
    _texture_manager.loadTextures();
}

gui::EntitySprite* utils::SpriteFactory::create(Entity* entity) const
{
    gui::EntitySprite* sprite = new gui::EntitySprite(entity);

    sprite->setTexture(_texture_manager.get(entity->getClass()));
    _world.addEntity(sprite);

    return sprite;
}