#pragma once

#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include <Entities/Characters/PhysicalCharacter.hpp>

class Knight : public PhysicalCharacter
{
public:

	/**
	*
	*/
	Knight(const int x, const int y, const char player);
	/**
	*
	*/
	~Knight();

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

#endif // !__KNIGHT_H__