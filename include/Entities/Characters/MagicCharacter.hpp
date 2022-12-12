#pragma once

#ifndef __MAGIC_CHARACTER_H__
#define __MAGIC_CHARACTER_H__

#include <Entities/Character.hpp>

class MagicCharacter : public Character
{
public:

	/**
	*
	*/
	MagicCharacter(const int x, const int y, const int hp, const char player, const int will, const int res_phy, const int res_mag, const int magic);
	/**
	*
	*/
	virtual ~MagicCharacter();

	/**
	 * @brief
	 *
	 *
	*/
	int getMagic();

	/**
	 * @brief
	 *
	 */


private:

	typedef Character super;
};

#endif // !__MAGIC_CHARACTER_H__
