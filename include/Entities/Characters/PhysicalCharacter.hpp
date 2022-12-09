#pragma once

#ifndef __PHYSICAL_CHARACTER_H__
#define __PHYSICAL_CHARACTER_H__

#include <Entities/Character.hpp>

/**
* @brief
*/
class PhysicalCharacter : public Character
{
public:

	/**
	* @brief
	*/
	PhysicalCharacter(const int x, const int y, const int hp, const char player, const int will, const int res_phy, const int res_mag, const int strength);
	/**
	* @brief
	*/
	virtual ~PhysicalCharacter() = default;

protected:

	int _strength;

private:

	// Not mendatory. Reminds of Java calls to base class for the ease of writing.
	// For instance, super(...) calls the base class constructor with the specified parameters.
	// In fact, it calls "Character(...)".
	typedef Character super;
};

#endif // !__PHYSICAL_CHARACTER_H__