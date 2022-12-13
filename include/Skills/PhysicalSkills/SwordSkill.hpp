#pragma once

#ifndef __SWORD_SKILL_H__
#define __SWORD_SKILL_H__

#include <Skills/PhysicalSkill.hpp>

class SwordSkill : public PhysicalSkill
{
public:
	
	/**
	*
	*/
	explicit SwordSkill(int multiplier, int range, Effect* effect = nullptr);
	/**
	*
	*/
	inline ~SwordSkill() noexcept = default;

private:
	
	typedef PhysicalSkill super;
	
private:
	
	const int base_damage = 10;
};

#endif // !__SWORD_SKILL_H__ 
