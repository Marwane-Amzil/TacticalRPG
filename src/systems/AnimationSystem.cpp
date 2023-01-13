#include <systems/AnimationSystem.hpp> // AnimationSystem declarations
#include <entt/entity/registry.hpp> // entt::registry
#include <entt/entity/entity.hpp> // entt::entity
#include <components/SpriteComponent.hpp> // SpriteComponent
#include <components/AnimationComponent.hpp> // AnimationComponent

AnimationSystem::AnimationSystem(entt::registry& registry)
	: _registry(registry) {}

void AnimationSystem::update(sf::Time elapsed_time) const
{
	for (const auto& [entity, sprite, animation] : _registry.view<SpriteComponent, AnimationComponent>().each())
	{
		if (animation.is_playing)
		{
			animation.current_time += elapsed_time;

			if (animation.current_time >= animation.frame_time)
			{
				animation.current_time = sf::Time::Zero;
				++animation.current_frame;
				
				if (animation.current_frame >= animation.frames.size())
				{
					if (animation.is_looping)
					{
						animation.current_frame = 1;
					}
					else
					{
						animation.is_playing = false;
						animation.current_frame = 0;
					}
				}
			}
		}

		sprite.sprite.setTextureRect(animation.frames[animation.current_frame]);
	}
}