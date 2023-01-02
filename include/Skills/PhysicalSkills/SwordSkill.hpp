#pragma once

#ifndef __SWORD_SKILL_H__
#define __SWORD_SKILL_H__

#include <Skills/PhysicalSkill.hpp>

class SwordSkill : public PhysicalSkill
{
public:
	
	/**
	*	@brief	Constructor for SwordSkill class with default values for effect and range parameters.
	*	@param	multiplier	The multiplier for the skill's damage.
	*	@param	character	The character that owns the skill.
	*/
	explicit SwordSkill(int multiplier, int range, Character* character, Effect* effect = nullptr);
	
	/**
	* @brief SwordSkill destructor. Explicitly defaulted (~SwordSkill() = default)
	*/
	inline ~SwordSkill() noexcept = default;
	
	/**
	*	@brief	method activate that activates the current skill (SwordSkill)
	*	@param	grid		The grid on which the skill will be activated.
	*	@param	target		The target is the character that is going to be targeted.
	*	This methode also verifies if the skill can be launched on the character put in parametre.
	*	Indeed the verification is done throught the getPossibleZones method.
	*/
	void activate(Grid& grid, Character& target) const override;

	/**
	*	@brief	Returns a vector of positions that are in range of the skill.
	*	It is where the skill (SwordSkill) can be launched.
	*/
	std::vector<Position> getPossibleZones(const Grid& grid) const override;


private:
	
	typedef PhysicalSkill super;
	
private:
	
	const int base_damage = 10;
};

#endif // !__SWORD_SKILL_H__ 
