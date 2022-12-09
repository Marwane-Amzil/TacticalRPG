#include <Entities/Obstacle.hpp>

Obstacle::Obstacle(const int x, const int y, const int hp)
	: super(x, y, hp) {}

std::string Obstacle::getClass() const
{
	return "obstacle";
}

bool Obstacle::equals(const Entity& other) const
{
	return false;
}
