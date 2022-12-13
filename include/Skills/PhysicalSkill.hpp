#pragma once

#ifndef __PHYSICAL_SKILL_H__
#define __PHYSICAL_SKILL_H__

#include <Skill.hpp>

class PhysicalSkill : public Skill
{
public:

	/**
	*
	*/
	explicit PhysicalSkill(int multiplier, int range, Effect* effect = nullptr);
	/**
	*
	*/
	inline virtual ~PhysicalSkill() noexcept = default;

private:
	
	/**
	*
	*/
	typedef Skill super;
};

#endif // !__MAGICAL_SKILL_H__