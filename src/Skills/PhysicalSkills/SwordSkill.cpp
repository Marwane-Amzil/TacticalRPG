#include <Effect.hpp>
#include "./Skills/PhysicalSkills/SwordSkill.hpp"

SwordSkill::SwordSkill(int multiplier, int range, Effect* effect)
{
	super(multiplier, range, effect);
}

SwordSkill::~SwordSkill()
{
}

int SwordSkill::attack(int strenght, int res_strengh) const
{

	
	return 0;
}
