#pragma once

#ifndef __SPRITE_FACTORY_H__
#define __SPRITE_FACTORY_H__

namespace gui
{
	class EntitySprite;
	//class World;
}

class Character;
class Obstacle;

namespace utils
{
	class TextureManager;
	class AnimationManager;

	class SpriteFactory
	{
	public:

		explicit SpriteFactory(TextureManager& texture_manager, AnimationManager& animation_manager);

		inline ~SpriteFactory() noexcept = default;

		gui::EntitySprite* createCharacter(Character* character) const;

	private:

		//gui::World& _world;
		TextureManager& _texture_manager;
		AnimationManager& _animation_manager;
	};
}

#endif // !__SPRITE_FACTORY_H__