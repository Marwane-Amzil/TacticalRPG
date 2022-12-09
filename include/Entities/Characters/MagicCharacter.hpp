#pragma once

#ifndef __MAGIC_CHARACTER_H__
#define __MAGIC_CHARACTER_H__

#include <Entities/Character.hpp>

/**
* @brief
*/
class MagicCharacter : public Character
{
public:

	/**
	* @brief
	*/
	MagicCharacter(const int x, const int y, const int hp, const char player, const int will, const int res_phy, const int res_mag, const int magic);
	/**
	* @brief
	*/
	virtual ~MagicCharacter() = default;

protected:

	int _magic;

private:

	// Not mendatory. Reminds of Java calls to base class for the ease of writing.
	// For instance, super(...) calls the base class constructor with the specified parameters.
	// In fact, it calls "Character(...)".
	typedef Character super;
};

#endif // !__MAGIC_CHARACTER_H__
