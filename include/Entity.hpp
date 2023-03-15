#pragma once

#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <Position.hpp> // Position class

/**
* @brief The Entity class represents any entity that might appear in the game. According to the rules,
* the entities are either an obstacle or a character. Despite both being entities, they have different
* behaviour depending on which derived class they are from.
*/
class Entity
{
public:

	/**
	* @brief Constructor taking 2 position values and a hp value.
	* Initialize an entity with a given position and a given hp value.
	* 
	* @param x: x position
	* @param y: y position
	* @param hp: hp of the entity
	*/
	Entity(const int x, const int y, const int hp);
	/**
	* @brief Method which returns the current position of the entity.
	* 
	* @return returns the position of the entity.
	*/
	const Position& getPosition() const;
	/**
	* @brief Method which sets the current position of the entity.
	* 
	* @param position: new position to set
	*/
	void setPosition(const Position& position);
	/**
	* @brief Method which returns the current hp of the entity.
	* 
	* @return returns the remaining hp of the entity
	*/

	void setPosition(const int _x, const int _y);

	int getHp() const;
	/**
	* @brief Method which sets the current hp of the entity.
	* 
	* @param hp: new hp value to set
	*/
	void setHp(const int hp);
	/**
	* @brief Overloaded == operator for the Entity class (which applies to its derived class).
	* Behaves the same as any == operator, it compares each member values of this instance of
	* the class and the parameter instance. To do so, it performs a call to the equals() method
	* marked as virtual so that every derived class may be compared.
	* 
	* @param other: entity to compare
	* 
	* @return Returns the equality of the 2 entities
	*/
	bool operator==(const Entity& other) const;
	/**
	* @brief Overloaded != operator for the Entity class (which applies to its derived class).
	* Behaves the same as any != operator, it compares each member values of this instance of
	* the class and the parameter instance. To do so, it performs a call to the equals() method
	* marked as virtual so that every derived class may be compared.
	*
	* @param other: entity to compare
	*
	* @return Returns the inequality of the 2 entities
	*/
	bool operator!=(const Entity& other) const;
	/**
	* @brief Entity destructor. Explicitly defaulted (~Grid() = default).
	* Marked as virtual to perform proper destruction when the current Entity is actually
	* an instance of one of the derived class.
	*/
	virtual ~Entity() = default;
	/**
	* @brief
	*/
	virtual std::string_view getClass() const = 0;

protected:

	/**
	* @brief Method which performs equality checks between 2 entities.
	* Marked as virtual to perform the same checks for every instance of
	* the derived classes.
	* 
	* @param other: entity to compare
	* 
	* @return Returns the equality of the 2 entities
	*/
	virtual bool equals(const Entity& other) const = 0;

protected:

	Position _position;
	int _hp;
};

#endif // !__ENTITY_H__