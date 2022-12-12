#pragma once
#ifndef __PHYSICALSKILL_H__
#define __PHYSICALSKILL__
#include <Skill.hpp>


class PhysicalSkill : public Skill
{
public:
	PhysicalSkill();
	~PhysicalSkill();
	
	virtual void activate(Character* character) const = 0;

private:
	typedef Skill super;
};
#endif // !__MAGICALSKILL_H__
