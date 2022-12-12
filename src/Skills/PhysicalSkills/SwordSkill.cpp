#include <Effect.hpp>
#include "./Skills/PhysicalSkills/SwordSkill.hpp"
#include "./Entities/Characters/PhysicalCharacter.hpp"

SwordSkill::SwordSkill(int multiplier, int range, Effect* effect)
{
	super(multiplier, range, effect);
}

SwordSkill::~SwordSkill()
{
}

int SwordSkill::attack(PhysicalCharacter* character) const
{
	return 0;
}

void SwordSkill::attack(PhysicalCharacter *character) const
{
	int hp = character->getHp();
	int strength = character->getStrength();
	int res_strength = character->getResPhy();
	
	hp = hp - (strength * (1 - (res_strength / 200))
	
	return hp;
}
