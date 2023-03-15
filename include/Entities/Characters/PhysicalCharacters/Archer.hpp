#pragma once

#ifndef __ARCHER_H__
#define __ARCHER_H__

#include <Entities/Characters/PhysicalCharacter.hpp>
#include <Constants.hpp>

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
	~Archer() = default;

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

	void setNbMoves(int nbMoves)  override;

	void  resetNbMoves()  override;

	int getNbMoves() const override;

	bool canMove(Grid& grid,int x, int y) const override;


private:

	typedef PhysicalCharacter super;
	int _nbMooves ;

};

#endif // !__ARCHER_H__