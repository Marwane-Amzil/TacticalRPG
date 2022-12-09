#pragma once

#ifndef __ENTITY_FACTORY_H__
#define __ENTITY_FACTORY_H__

namespace gui
{
	class World;
}

class Entity;

namespace utils
{
	class TextureManager;

	class SpriteFactory
	{
	public:

		explicit SpriteFactory(gui::World* world, TextureManager* texture_manager);

		inline ~SpriteFactory() noexcept = default;

		void create(Entity* entity) const;

	private:

		gui::World* _world;
		TextureManager* _texture_manager;
	};
}

#endif // !__ENTITY_FACTORY_H__