#pragma once

#ifndef __ANIMATION_SYSTEM_H__
#define __ANIMATION_SYSTEM_H__

#include <SFML/System/Time.hpp> // sf::Time
#include <entt/entity/registry.hpp> // entt::registry

class AnimationSystem
{
public:

	explicit AnimationSystem(entt::registry& registry);

	constexpr AnimationSystem(const AnimationSystem&) = delete;

	constexpr AnimationSystem(AnimationSystem&&) noexcept = delete;

	inline ~AnimationSystem() noexcept = default;

	void update(sf::Time elapsed_time) const;

	constexpr AnimationSystem& operator=(const AnimationSystem&) = delete;

	constexpr AnimationSystem& operator=(AnimationSystem&&) noexcept = delete;
	
private:
	
	entt::registry& _registry;
};

#endif // !__ANIMATION_SYSTEM_H__