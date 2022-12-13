#pragma once

#ifndef __SKILL_H__
#define __SKILL_H__

class Effect;
class Character;

class Skill
{
public:
		
	/**
	*
	*/
	explicit Skill(int multiplier, int range, Effect *effect = nullptr);
	/**
	*
	*/
	inline virtual ~Skill() noexcept = default;
	/**
	*
	*/
	int getMultiplier() const;
	/**
	*
	*/
	int getRange() const;
	/**
	*
	*/
	const Effect* getEffect() const;
	/**
	*
	*/
	virtual void activate(Character* character) const = 0;

private:
		
	int _multiplier;
	int _range;
	Effect *_effect;
};

#endif // !__SKILL_H__ 
