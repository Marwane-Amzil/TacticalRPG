#pragma once

#ifndef __ENTITY_CREATOR_H__
#define __ENTITY_CREATOR_H__

#include <entt/entity/registry.hpp> // entt::registry

using World = entt::registry;
using Entity = entt::entity;

class EntityCreator
{
public:
	
	EntityCreator(World& _World) noexcept;

	inline ~EntityCreator() noexcept = default;

	Entity create() noexcept;

	template<typename _Ty, typename... ComponentArgs>
	inline decltype(auto) emplace(const entt::entity _Entity, ComponentArgs&&... _Args) noexcept
	{
		return _world.emplace<_Ty>(_Entity, std::forward<ComponentArgs>(_Args)...);
	}
	
private:

	World& _world;
};

#endif // !__ENTITY_CREATOR_H__