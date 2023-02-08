#pragma once

#ifndef __BOW_SHOT_H__
#define __BOW_SHOT_H__

#include <Skills/PhysicalSkill.hpp>

class BowShot : public PhysicalSkill
{
public:

	/**
	*	@brief	Constructor for AxeSkill class with default values for effect and range parameters.
	*	@param	multiplier	The multiplier for the skill's damage.
	*	@param	character	The character that owns the skill.
	*/
	explicit BowShot(int multiplier, int range, Character* character, Effect* effect = nullptr);

	/**
	* @brief AxeSkill destructor. Explicitly defaulted (~AxeSkill() = default)
	*/
	inline ~BowShot() noexcept = default;

	/**
	*	@brief	method activate that activates the current skill (AxeSkill)
	*	@param	grid		The grid on which the skill will be activated.
	*	@param	target		The target is the character that is going to be targeted.
	*	This methode also verifies if the skill (AxeSkill) can be launched on the character put in parametre.
	*	Indeed the verification is done throught the getPossibleZones method.
	*/
	void activate(Grid& grid, Character* target) const override;

	/**
	*	@brief	Returns a vector of positions that are in range of the skill (AxeSKill).
	*	It is where the skill can be launched.
	*/
	std::vector<Position> getPossibleZones(const Grid& grid) const override;

	std::string getName() const override;



private:

	typedef PhysicalSkill super;

private:

	const int base_damage = 15;
};

#endif // !__AXE_SKILL_H__ 
