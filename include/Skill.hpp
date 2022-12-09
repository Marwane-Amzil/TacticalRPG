#pragma once
#ifndef __SKILL_H__
#define __SKILL_H__

class Effect;
class Skill
{
	public:
		Skill(int multiplier, int range, Effect *effect = nullptr);
		~Skill();

	private:
		int _multiplier;
		int _range;
		Effect *_effect;
};

#endif // !__SKILL_H__ 
