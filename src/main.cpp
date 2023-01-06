#include <utils/SpriteManager.hpp>
#include <components/Position.hpp>
#include <components/Sprite.hpp>
#include <utils/EntityCreator.hpp>
#include <SFML/Graphics.hpp>
#include <components/Sprite.hpp>
#include <components/Position.hpp>
#include <components/characters/Knight.hpp>
#include <entt.hpp>
#include <iostream>

int main(int argc, char* argv[])
{
	entt::registry world;
	SpriteManager sprite_manager;
	sprite_manager.load();
	EntityCreator entity_creator(world);
	Position position(0, 0);
	Sprite sprite(sprite_manager.getSprite('B', "knight"));

	entity_creator.createEntity(position);

	return 0;
}