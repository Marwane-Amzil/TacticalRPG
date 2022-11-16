#pragma once

#ifndef __ARCHER_H__
#define __ARCHER_H__

#include <Entities/Characters/PhysicalCharacter.hpp>

class Archer : public PhysicalCharacter
{
public:

	/**
	*
	*/
	Archer(const int x, const int y, const char player);
	/**
	*
	*/
	~Archer();

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
	*/
	bool equals(const Entity& other) const override;

private:

	typedef PhysicalCharacter super;
};

#endif // !__ARCHER_H__