#pragma once

#ifndef __MAGICAL_SKILL_H__
#define __MAGICAL_SKILL_H__

#include <Skill.hpp>

class MagicalSkill : public Skill
{
public:
	
	/**
	*	@brief	Constructor for MagicalSkill class with default values for effect and range parameters. 
	*	@param	multiplier	The multiplier for the skill's damage.
	*	@param	character	The character that owns the skill. 
	*	@param	effect		The effect that the skill will apply to the target.
	*/
	explicit MagicalSkill(int multiplier, int range, Character* character, Effect* effect = nullptr);
	
	/**
	* @brief MagicalSkill destructor. Explicitly defaulted (~MagicalSkill() = default)
	*/
	inline virtual ~MagicalSkill() noexcept = default;

private:
	
	/**
	*
	*/
	typedef Skill super;
};
#endif // !__MAGICAL_SKILL_H__