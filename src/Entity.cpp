#include <Entity.hpp>

Entity::Entity(const int x, const int y, const int hp)
	: _position(x, y), _hp(hp) {}

const Position& Entity::getPosition() const
{
	return _position;
}

void Entity::setPosition(const Position& position)
{
	_position = position;
}

int Entity::getHp() const
{
	return _hp;
}

void Entity::setHp(const int hp)
{
	_hp = hp;
}

bool Entity::operator==(const Entity& other) const
{
	return false;
}

bool Entity::operator!=(const Entity& other) const
{
	return false;
}

Entity::~Entity()
{
}
