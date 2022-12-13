#pragma once

#ifndef __AXE_SKILL_H__
#define __AXE_SKILL_H__

#include <Skills/PhysicalSkill.hpp>

class AxeSkill : public PhysicalSkill
{
public:
	
	/**
	*
	*/
	explicit AxeSkill(int multiplier, int range, Effect* effect = nullptr);
	/**
	*
	*/
	inline ~AxeSkill() noexcept = default;
	/**
	*
	*/
	void activate(Character* character) const override;

private:

	typedef PhysicalSkill super;

private:
	
	const int base_damage = 15;
};

#endif // !__AXE_SKILL_H__ 
