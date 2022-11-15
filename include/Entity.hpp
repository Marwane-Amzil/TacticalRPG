#pragma once

#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <Position.hpp>

// Entity might be a Character or an Obsactle. 

class Entity
{
public:

	/**
	*
	*/
	Entity(const int x, const int y, const int hp);
	/**
	*
	*/
	const Position& getPosition() const;
	/**
	*
	*/
	void setPosition(const Position& position);
	/**
	*
	*/
	int getHp() const;
	/**
	*
	*/
	void setHp(const int hp);
	/**
	* 
	*/
	bool operator==(const Entity& other) const;
	/**
	*
	*/
	bool operator!=(const Entity& other) const;
	/**
	*
	*/
	virtual ~Entity();

protected:

	/**
	* 
	*/
	virtual bool equals(const Entity& other) const = 0;

protected:

	Position _position;
	int _hp;
};

#endif // !__ENTITY_H__