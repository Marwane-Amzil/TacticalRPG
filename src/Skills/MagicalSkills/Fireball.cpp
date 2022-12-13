#include <Skills/MagicalSkills/Fireball.hpp>
#include <Entities/Character.hpp>

Fireball::Fireball(int multiplier, int range, Effect* effect)
	: super(multiplier, range, effect) {}

void Fireball::activate(Character* character) const
{
	int hp = character->getHp();
	int magic = character->getMagic();
	int res_magic = character->getResMag();
	hp = hp - (magic * (1 - (res_magic / 200)));
	character->setHp(hp);
}