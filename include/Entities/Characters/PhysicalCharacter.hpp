#pragma once

#ifndef __PHYSICAL_CHARACTER_H__
#define __PHYSICAL_CHARACTER_H__

#include <Entities/Character.hpp>

class PhysicalCharacter : public Character
{
public:

	/**
	*
	*/
	PhysicalCharacter(const int x, const int y, const int hp, const char player, const int will, const int res_phy, const int res_mag, const int strength);
	/*
	*
	*/
	virtual ~PhysicalCharacter();

	/**
	 * @brief 
	 * 
	 */
	void attack(const Position pos) const override;



	

private:

	typedef Character super;
};

#endif // !__PHYSICAL_CHARACTER_H__