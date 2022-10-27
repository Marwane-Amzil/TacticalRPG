#pragma once

#ifndef __OBSTACLE_H__
#define __OBSTACLE_H__

#include <Entity.hpp>

class Obstacle : public Entity
{
public:

	/**
	*
	*/
	Obstacle(const int x, const int y, const int hp);
	/**
	*
	*/
	~Obstacle();

private:

	/**
	*
	*/
	bool equals(const Entity& other) const;

private:

	typedef Entity super;
};

#endif // !__OBSTACLE_H__