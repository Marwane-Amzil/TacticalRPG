#include <utils/SpriteFactory.hpp> // utils::SpriteFactory
#include <utils/TextureManager.hpp> // utils::TextureManager
#include <utils/AnimationManager.hpp> // utils::AnimationManager
#include <GUI/game/World.hpp> // gui::World
#include <GUI/game/EntitySprite.hpp> // gui::EntitySprite
#include <Entity.hpp> // Entity

namespace utils
{
	SpriteFactory::SpriteFactory(gui::World& world, TextureManager& texture_manager, AnimationManager& animation_manager)
		: _world(world), _texture_manager(texture_manager), _animation_manager(animation_manager)
	{
		_texture_manager.loadTextures();
		_animation_manager.loadAnimations();
	}

	gui::EntitySprite* SpriteFactory::create(Entity* entity) const
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
}
