#pragma once
#ifndef __PHYSICALSKILL_H__
#define __PHYSICALSKILL__
#include <Skill.hpp>

class PhysicalSkill : public Skill
{
public:
	PhysicalSkill();
	~PhysicalSkill();

private:
	typedef Skill super;
};
#endif // !__MAGICALSKILL_H__
