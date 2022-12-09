#pragma once

#ifndef __WARRIOR_H__
#define __WARRIOR_H__

#include <Entities/Characters/PhysicalCharacter.hpp>
#include <Constants.hpp>
class Warrior : public PhysicalCharacter
{
public:

	/**
	*
	*/
	Warrior(const int x, const int y, const char player);
	/**
	*
	*/
	~Warrior() = default;

private:

	/**
	*
	*/
	std::vector<Position> getPossibleMoves(const Grid& grid) const override;
	/**
	*
	*/
	std::vector<Position> getPossibleActions(const Grid& grid) const override;
	
	/**
	 * 
	 *
	*/
	void attack(const Position pos) const override;
	
	/**
	*
	*/
	bool equals(const Entity& other) const override;

private:

	typedef PhysicalCharacter super;
};

#endif // !__WARRIOR_H__