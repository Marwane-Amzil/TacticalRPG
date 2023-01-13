#include <systems/SpriteRenderer.hpp> // SpriteRenderer declarations
#include <SFML/Graphics/RenderWindow.hpp> // sf::RenderWindow
#include <entt/entity/registry.hpp> // entt::registry
#include <entt/entity/entity.hpp> // entt::entity
#include <components/SpriteComponent.hpp> // SpriteComponent
#include <components/PositionComponent.hpp> // PositionComponent

SpriteRenderer::SpriteRenderer(sf::RenderWindow& target, entt::registry& registry)
	: _window(target), _registry(registry) {}

void SpriteRenderer::render() const
{
	for (const auto& [entity, sprite, position] : _registry.group<SpriteComponent, PositionComponent>().each())
	{
		sprite.setPosition(sf::Vector2f(position.x, position.y));
		_window.draw(sprite);
	}
}
