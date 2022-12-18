#include <utils/SpriteFactory.hpp>
#include <utils/TextureManager.hpp>
#include <utils/AnimationManager.hpp>
#include <GUI/game/World.hpp>
#include <GUI/game/EntitySprite.hpp>
#include <Entity.hpp>

utils::SpriteFactory::SpriteFactory(gui::World& world, TextureManager& texture_manager, AnimationManager& animation_manager)
	: _world(world), _texture_manager(texture_manager), _animation_manager(animation_manager)
{
    _texture_manager.loadTextures();
    _animation_manager.loadAnimations();
}

gui::EntitySprite* utils::SpriteFactory::create(Entity* entity) const
{
    gui::EntitySprite* sprite = new gui::EntitySprite(entity);
    sprite->setTexture(_texture_manager.get(entity->getClass()));
	size_t index = 0;

	for (const auto& [name, animation] : _animation_manager.get(entity->getClass()))
	{
		sprite->addAnimation(index, *animation);
		index++;
	}

    _world.addEntity(sprite);

    return sprite;
}