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
		: _world(world), _texture_manager(texture_manager), _animation_manager(animation_manager) {}

	gui::EntitySprite* SpriteFactory::createCharacter(Character* character) const
	{
		
		gui::EntitySprite* sprite = new gui::EntitySprite(character);
		
		int sprite_x = sprite->getEntity()->getPosition().getX() * 50+ (_world.getShape().getGlobalBounds().getPosition().x);
		int sprite_y = sprite->getEntity()->getPosition().getY() * 50+ (_world.getShape().getGlobalBounds().getPosition().y);
		
		sprite->setPosition(sprite_x,sprite_y);
		sprite->setTexture(_texture_manager.getTextureAt(character->getPlayer(), character->getClass()));
		sprite->setTextureRect(sf::IntRect(70, 650, 50, 50));
		
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

		_world.addEntity(sprite);
		
		return sprite;
	}
}
