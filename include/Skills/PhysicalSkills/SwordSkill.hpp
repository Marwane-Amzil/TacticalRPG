#pragma once
#ifndef __SWORDSKILL_H__
#define __SWORDSKILL_H__
#include <Skills/PhysicalSkill.hpp>

class Effect;
class SwordSkill : public PhysicalSkill
{
public:
	SwordSkill(int multiplier, int range, Effect* effect = nullptr);
	~SwordSkill();

	void activate(Character* character) const;
	

private:
	typedef SwordSkill super;
	const int baseDamage = 10;
};

#endif // !__SKILL_H__ 
