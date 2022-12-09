#pragma once

#ifndef __OBSTACLE_H__
#define __OBSTACLE_H__

#include <Entity.hpp> // Entity class

/**
* @brief The Obstacle class represents any entity which are not playable by the player. According to the rules,
* while not being usable by the user, it still represents an entity which occupies a slot in the field, thus allowing
* the player to get rid of it to free some cases in the field.
*/
class Obstacle : public Entity
{
public:

	/**
	* @brief Constructor taking 2 position values and a hp value.
	* Initialize an obstacle with a given position and a given hp value.
	* To achieve this, it will call the base class constructor (Entity).
	*
	* @param x: x position
	* @param y: y position
	* @param hp: hp of the obstacle
	*/
	Obstacle(const int x, const int y, const int hp);
	/**
	* @brief Obstacle destructor. Explicitly defaulted (~Obstacle() = default).
	*/
	~Obstacle() = default;

private:

	/**
	* @brief Method which performs equality checks between 2 entities.
	*
	* @param other: entity to compare
	*
	* @return Returns the equality of the 2 entities
	*/
	bool equals(const Entity& other) const;

private:

	// Not mendatory. Reminds of Java calls to base class for the ease of writing.
	// For instance, super(...) calls the base class constructor with the specified parameters.
	// In fact, it calls "Entity(...)".
	typedef Entity super;
};

#endif // !__OBSTACLE_H__