#include <Skills/PhysicalSkills/AxeSkill.hpp>
#include <Entities/Character.hpp>

AxeSkill::AxeSkill(int multiplier, int range, Effect* effect)
	: super(multiplier, range, effect) {}

void AxeSkill::activate(Character* character) const
{
	int hp = character->getHp();
	int strength = character->getStrength();
	int res_strength = character->getResPhy();

	character->setHp(hp - (strength * (1 - (res_strength / 200))));
}