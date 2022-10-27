#pragma once

#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <Entity.hpp>
#include <vector>

class Grid;

class Character : public Entity
{
public:

	/**
	*
	*/
	Character(const int x, const int y, const int hp, const char player, const int will, const int res_phy, const int res_mag);
	/**
	*
	*/
	char getPlayer() const;
	/**
	*
	*/
	int getWill() const;
	/**
	*
	*/
	int getResPhy() const;
	/**
	*
	*/
	int getResMag() const;
	/**
	*
	*/
	void setWill(const int will);
	/**
	*
	*/
	void setResPhy(const int res_phy);
	/**
	*
	*/
	void setResMag(const int res_mag);
	/**
	*
	*/
	virtual ~Character();
	/**
	*
	*/
	virtual std::vector<Position> getPossibleMoves(const Grid& grid) const = 0;
	/**
	*
	*/
	virtual std::vector<Position> getPossibleActions(const Grid& grid) const = 0;

protected:

	char _player;
	int _will;
	int _res_phy;
	int _res_mag;

private:

	typedef Entity super;
};

#endif // !__CHARACTER_H__