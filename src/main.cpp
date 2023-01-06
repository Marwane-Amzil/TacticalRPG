#include <utils/SpriteManager.hpp>
#include <components/Position.hpp>
#include <components/Sprite.hpp>
#include <utils/EntityCreator.hpp>
#include <SFML/Graphics.hpp>
#include <components/Sprite.hpp>
#include <components/Position.hpp>
#include <components/characters/Knight.hpp>
#include <entt/entity/registry.hpp>
#include <iostream>

int main(int argc, char* argv[])
{
	entt::registry world;
	SpriteManager sm;
	sm.load();
	EntityCreator ec(world);
	Position position(0, 0);
	Sprite sprite(sm.getSprite('B', "knight"));

	auto entity = world.create();
	ec.emplace<Position>(entity, position);
	ec.emplace<Sprite>(entity, sprite);

	return 0;
}