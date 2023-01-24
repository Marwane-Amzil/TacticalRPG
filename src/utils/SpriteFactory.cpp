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
		// Load the textures and animations
		_texture_manager.loadTextures();
		_animation_manager.loadAnimations();
		
	}

	gui::EntitySprite* SpriteFactory::createCharacter(Character* character) const
	{
		
		gui::EntitySprite* sprite = new gui::EntitySprite(character);
		sprite->setTexture(_texture_manager.getTextureAt(character->getPlayer(), character->getClass()));
		size_t index = 0;

		for (const gui::Animation* animation : _animation_manager.getAnimations())
		{
			sprite->addAnimation(index, *animation);
			++index;
		}

		for (const auto& [name, animation] : _animation_manager.getSpecialAnimations(character->getClass()))
		{
			sprite->addAnimation(index, *animation);
			++index;
		}

		sprite->setTextureRect(0,64,50,60);
		sprite->setCurrentAnimation(5);
		sprite->playAnimation();

		_world.addEntity(sprite);
		
		return sprite;
	}
}
