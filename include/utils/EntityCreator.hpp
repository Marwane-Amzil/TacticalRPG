#pragma once

#ifndef __ENTITY_CREATOR_H__
#define __ENTITY_CREATOR_H__

#include <entt.hpp> // entt::registry

using World = entt::registry;

class EntityCreator
{
public:
	
	EntityCreator(World& _World) noexcept;

	inline ~EntityCreator() noexcept = default;

	template <typename Component>
	inline entt::entity* createEntity(Component& _Component) noexcept
	{
		auto entity = _world.create();
		_world.emplace<Component>(entity, _Component);
		return &entity;
	}
	
private:

	World& _world;
};

#endif // !__ENTITY_CREATOR_H__