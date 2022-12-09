#pragma once

#ifndef __ENTITY_SPRITE_H__
#define __ENTITY_SPRITE_H__

#include <SFML/Graphics/Sprite.hpp>
#include <string>

class Entity;

namespace gui
{
	class EntitySprite : public sf::Sprite
	{
	public:

		explicit EntitySprite(Entity* entity = nullptr);

		inline virtual ~EntitySprite() noexcept = default;

		const Entity* getEntity() const;

	private:

		Entity* _entity;
	};
}

#endif // !__ENTITY_SPRITE_H__