#pragma once

#ifndef __Fireball_H__
#define __Fireball_H__

#include <Skills/MagicalSkill.hpp>

class Fireball : public MagicalSkill
{
public:

	/**
	*	@brief	Constructor for Fireball class with default values for effect and range parameters.
	*	@param	multiplier	The multiplier for the skill's damage.
	*	@param	character	The character that owns the skill.
	*/
	explicit Fireball(int multiplier, int range, Character* character,Effect* effect = nullptr);
	
	/**
	* @brief Fireball destructor. Explicitly defaulted (~Fireball() = default)
	*/
	inline ~Fireball() noexcept = default;
	
	/**
	*	@brief	method activate that activates the current skill (Fireball)
	*	@param	grid		The grid on which the skill will be activated.
	*	@param	target		The target is the character that is going to be targeted. 
	*	This methode also verifies if the skill can be launched on the character put in parametre.
	*	Indeed the verification is done throught the getPossibleZones method.
	*/
	void activate(Grid& grid, Character* target) const override;
	
	/**
	*	@brief	Returns a vector of positions that are in range of the skill.
	*	It is where the skill (Fireball) can be launched.
	*/
	std::vector<Position> getPossibleZones(const Grid& grid) const override;

	std::string getName() const override;

	bool canActivate(Grid& grid, Character* target) const override;


private:

	typedef MagicalSkill super;

private:
	
	const int _base_damage = 7;
};

#endif // !__Fireball_H__