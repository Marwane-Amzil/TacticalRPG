#pragma once
#ifndef __MAGICALSKILL_H__
#define __MAGICALSKILL__
#include <Skill.hpp>

class MagicalSkill : public Skill
{
public:
	MagicalSkill();
	~MagicalSkill();

	virtual void activate(MagicCharacter* character) const = 0;
	

private:
	typedef Skill super;
};
#endif // !__MAGICALSKILL_H__
