#include <utils/SpriteFactory.hpp> // utils::SpriteFactory
#include <utils/TextureManager.hpp> // utils::TextureManager
#include <utils/AnimationManager.hpp> // utils::AnimationManager
#include <GUI/game/World.hpp> // gui::World
#include <GUI/game/EntitySprite.hpp> // gui::EntitySprite
#include <Entities/Character.hpp> // Character
#include <Entities/Obstacle.hpp> // Obstacle

namespace utils
{
	SpriteFactory::SpriteFactory(gui::World& world, TextureManager& texture_manager, AnimationManager& animation_manager)
		: _world(world), _texture_manager(texture_manager), _animation_manager(animation_manager)
	{
		_texture_manager.loadTextures();
		_animation_manager.loadAnimations();
	}

	gui::EntitySprite* SpriteFactory::createCharacter(Character* character) const
	{
		gui::EntitySprite* sprite = new gui::EntitySprite(character);
		sprite->setTexture(_texture_manager.get(character->getPlayer(), character->getClass()));
		size_t index = 0;

		for (const gui::Animation* animation : _animation_manager.getAnimations())
		{
			sprite->addAnimation(index, *animation);
			++index;
		}

		sprite->addAnimation(index, _animation_manager.getSpecialAnimation(character->getClass()));

		_world.addEntity(sprite);
		
		return sprite;
	}
}
