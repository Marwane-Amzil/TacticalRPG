#pragma once

#ifndef __SPRITE_RENDERER_H__
#define __SPRITE_RENDERER_H__

#include <entt/entity/registry.hpp> // entt::registry

namespace sf
{
	class RenderWindow;
}

class SpriteRenderer
{
public:

	explicit SpriteRenderer(sf::RenderWindow& target, entt::registry& registry);

	constexpr SpriteRenderer(const SpriteRenderer&) = delete;

	constexpr SpriteRenderer(SpriteRenderer&&) noexcept = delete;

	inline ~SpriteRenderer() noexcept = default;

	void render() const;

	constexpr SpriteRenderer& operator=(const SpriteRenderer&) = delete;
	
	constexpr SpriteRenderer& operator=(SpriteRenderer&&) noexcept = delete;

private:

	sf::RenderWindow& _window;
	entt::registry& _registry;
};

#endif // !__SPRITE_RENDERER_H__