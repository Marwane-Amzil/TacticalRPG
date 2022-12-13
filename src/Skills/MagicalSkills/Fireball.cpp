#include <Skills/MagicalSkills/Fireball.hpp>
#include <Entities/Character.hpp>

Fireball::Fireball(int multiplier, int range, Effect* effect)
	: super(multiplier, range, effect) {}

void Fireball::activate(Character* character) const
{
	int hp = character->getHp();
	int strength = character->getStrength();
	int res_strength = character->getResPhy();
	
	character->setHp(hp - (strength * (1 - (res_strength / 200))));
}