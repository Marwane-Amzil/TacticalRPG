#pragma once
#ifndef __AXEKILL_H__
#define __AXESKILL_H__
#include <Skills/PhysicalSkill.hpp>

class Effect;

class AxeSkill : public PhysicalSkill
{
public:
	AxeSkill(int multiplier, int range, Effect* effect = nullptr);
	~AxeSkill();

	void activate(PhysicalCharacter* character) const;

private:
	typedef AxeSkill super;
};

#endif // !__SKILL_H__ 
