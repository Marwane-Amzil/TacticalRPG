#include <Entity.hpp>

Entity::Entity(const int x, const int y, const int hp)
	: _position(x, y), _hp(hp) {}

// ----------------------------------------------   Start  Getters / Setters    ------------------------------------------------------------

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
	this->_hp = hp;
}

// ----------------------------------------------   End  Getters / Setters    ------------------------------------------------------------

bool Entity::operator==(const Entity& other) const
{
	return false;
}

bool Entity::operator!=(const Entity& other) const
{
	return false;
}