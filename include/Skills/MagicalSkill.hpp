#pragma once

#ifndef __MAGICAL_SKILL_H__
#define __MAGICAL_SKILL_H__

#include <Skill.hpp>

class MagicalSkill : public Skill
{
public:
	
	/**
	*
	*/
	explicit MagicalSkill(int multiplier, int range, Effect* effect = nullptr);
	/**
	*
	*/
	inline virtual ~MagicalSkill() noexcept = default;

private:
	
	/**
	*
	*/
	typedef Skill super;
};
#endif // !__MAGICAL_SKILL_H__
