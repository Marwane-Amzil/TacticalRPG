#pragma once

#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include <Entities/Characters/PhysicalCharacter.hpp>
#include <Constants.hpp>

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
	~Knight() = default;

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
	/**
	*
	*/
	std::string_view getClass() const override;

	void setNbMoves(const int nbMoves) override;

	void  resetNbMoves() override;

	int getNbMoves() const override;

	bool canMove(Grid& grid, int x, int y) const override;



private:

	typedef PhysicalCharacter super;
	int _nbMooves;
};

#endif // !__KNIGHT_H__