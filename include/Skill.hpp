#pragma once
#ifndef __SKILL_H__
#define __SKILL_H__

class Effect;
class Character;

class Skill
{
	public:
		Skill(int multiplier, int range, Effect *effect = nullptr);
		~Skill();
		int getMultiplier() const;
		int getRange() const;
		Effect* getEffect() const;
	private:
		int _multiplier;
		int _range;
		Effect *_effect;
};

#endif // !__SKILL_H__ 
