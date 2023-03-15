#pragma once

#ifndef __MAGE_H__
#define __MAGE_H__

#include <Entities/Characters/MagicCharacter.hpp>
#include <Constants.hpp>

class Mage : public MagicCharacter
{
public:

	/**
	*
	*/
	Mage(const int x, const int y, const char player);
	/**
	*
	*/
	~Mage() = default;

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

	bool canMove(Grid& grid, int x, int y) const override;


private:

	typedef MagicCharacter super;
	int _nbMooves ;

};

#endif // !__MAGE_H__