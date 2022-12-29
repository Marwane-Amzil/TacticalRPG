#include <Skills/PhysicalSkills/SwordSkill.hpp>
#include <Entities/Character.hpp>

SwordSkill::SwordSkill(int multiplier, int range,Character* character, Effect* effect)
	: super(multiplier, range,character, effect) {}

void SwordSkill::activate(Grid& grid, Character& character) const
{
	/*int hp = character.getHp();
	int strength = character.getStrength();
	int res_strength = character.getResPhy();
	character.setHp(hp - (strength * (1 - (res_strength / 200))));*/
	character.setHp(300);
	

}

std::vector<Position> SwordSkill::getPossibleZones(const Grid& grid) const
{
	return std::vector<Position>();
}
