#pragma once
#ifndef __SWORDSKILL_H__
#define __SWORDSKILL_H__

class Effect;
class SwordSkill
{
public:
	SwordSkill(int multiplier, int range, Effect* effect = nullptr);
	~SwordSkill();
	int attack(int strenght, int res_strengh) const;
	

private:
	typedef SwordSkill super;
};

#endif // !__SKILL_H__ 
