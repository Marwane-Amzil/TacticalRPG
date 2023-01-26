#include <utils/SpriteFactory.hpp> // utils::SpriteFactory
#include <utils/TextureManager.hpp> // utils::TextureManager
#include <utils/AnimationManager.hpp> // utils::AnimationManager
#include <GUI/game/World.hpp> // gui::World
#include <GUI/game/EntitySprite.hpp> // gui::EntitySprite
#include <Entities/Character.hpp> // Character
#include <Entities/Obstacle.hpp> // Obstacle
#include <iostream>

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
		
		int sprite_x = sprite->getEntity()->getPosition().getX() * 50 + (0.24 * _world.getShape().getGlobalBounds().getPosition().x);
		int sprite_y = sprite->getEntity()->getPosition().getY() * 50 + (0.04 * _world.getShape().getGlobalBounds().getPosition().y);

		std::cout << "sprite_x : " << sprite_x << "   " << sprite_y << std::endl;
		
		sprite->setPosition(sprite_x,sprite_y);
		sprite->setTexture(_texture_manager.getTextureAt(character->getPlayer(), character->getClass()));
		size_t index = 0;

		/*
		for (const gui::Animation* animation : _animation_manager.getAnimations())
		{
			sprite->addAnimation(index, *animation);
			++index;
			std::cout << "index = " << index << std::endl;

		}
		for (const auto& [name, animation] : _animation_manager.getSpecialAnimations(character->getClass()))
		{
			sprite->addAnimation(index, *animation);
			++index;
			std::cout << "index = " << index << " name = " << name << std::endl;
		}

		sprite->setCurrentAnimation(2);
		sprite->playAnimation();
		sprite->loopCurrentAnimation(true);
		*/

		_world.addEntity(sprite);
		
		return sprite;
	}
}
