#include <Skills/PhysicalSkills/AxeSkill.hpp>
#include <Entities/Character.hpp>
#include <Grid.hpp>
#include <Constants.hpp>
#include <Position.hpp>

using namespace ::fireball;
using namespace ::grid;

AxeSkill::AxeSkill(int multiplier, int range,Character* character, Effect* effect)
	: super(multiplier, range, character,effect) {}

void AxeSkill::activate(Grid& grid, Character* character) const
{
	int hp = character->getHp();
	int strength = character->getStrength();
	int res_strength = character->getResPhy();
	character->setHp(hp - (strength * (1 - (res_strength / 200) ) ) );
	
}

std::vector<Position> AxeSkill::getPossibleZones(const Grid& grid) const {

	std::vector<Position> possibleZones;
	Position pos = getOwner()->getPosition();

	for (int x = NEG_RANGE; x < RANGE; x++)
	{
		for (int y = NEG_RANGE; y < RANGE; y++)
		{
			if (abs(x) + abs(y) < RANGE && x != 0 || y != 0)
			{
				if (pos.getX() + x < COLUMNS && pos.getY() + y < COLUMNS && pos.getX() + x >= 0 && pos.getY() + y >= 0)
				{
					if (!grid[pos.getX() + x][pos.getY() + y])
					{
						possibleZones.emplace_back(pos.getX() + x, pos.getY() + y);
					}
				}
			}
		}
	}
	return possibleZones;
}