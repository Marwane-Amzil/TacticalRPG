#pragma once

#ifndef __PHYSICAL_SKILL_H__
#define __PHYSICAL_SKILL_H__

#include <Skill.hpp>

class PhysicalSkill : public Skill
{
public:

	/**
	*	@brief	Constructor for PhysicalSkill class with default values for effect and range parameters.
	*	@param	multiplier	The multiplier for the skill's damage.
	*	@param	character	The character that owns the skill.
	*	@param	effect		The effect that the skill will apply to the target.
	*/
	explicit PhysicalSkill(int multiplier, int range, Character* character, Effect* effect = nullptr);
	
	/**
	* @brief PhysicalSkill destructor. Explicitly defaulted (~PhysicalSkill() = default).
	*/
	inline virtual ~PhysicalSkill() noexcept = default;

private:
	
	/**
	*
	*/
	typedef Skill super;
};

#endif // !__MAGICAL_SKILL_H__