#include <Skills/MagicalSkills/HealerTemp.hpp>
#include <Entities/Character.hpp>
#include <Grid.hpp>
#include <Constants.hpp>
#include <Position.hpp>
#include <iostream>

using namespace ::axeskill;
using namespace ::grid;

// AxeSkill constructor
HealerTemp::HealerTemp(int multiplier, int range,Character* character, Effect* effect)
	: super(multiplier, range, character,effect) {}

void HealerTemp::activate(Grid& grid, Character* target) const
{
	// Declaration 
	Position posTarget = target->getPosition();
	int hp = target->getHp();
	int strength = target->getStrength();
	int res_strength = target->getResMag();
	std::vector<Position> possibleZones = getPossibleZones(grid);

	// Processing
	for (const Position& position : possibleZones) {
		if (posTarget == position) {
			int damage = (strength * (1 - (res_strength / 200)));
			hp = target->getHp() - damage;
			if (hp < 0)
			{
				hp = 0;
			}
			target->setHp(hp);
		}
	}
}


std::vector<Position> HealerTemp::getPossibleZones(const Grid& grid) const {

	std::vector<Position> possibleZones;
	Position posOwner = getOwner()->getPosition();

	for (int x = NEG_RANGE_X; x <= RANGE_X; x++)
	{
		for (int y = NEG_RANGE_Y; y <= RANGE_Y; y++)
		{
			if (abs(x) + abs(y) <= RANGE_X && x != 0 || y != 0)
			{
				if (posOwner.getX() + x < COLUMNS && posOwner.getY() + y < COLUMNS && posOwner.getX() + x >= 0 && posOwner.getY() + y >= 0)
				{
					if (grid[posOwner.getX() + x][posOwner.getY() + y])
					{
						Character* target = dynamic_cast<Character*>(grid[posOwner.getX() + x][posOwner.getY() + y]);
						if (target->getPlayer() != getOwner()->getPlayer())
						{
							possibleZones.emplace_back(posOwner.getX() + x, posOwner.getY() + y);
						}
					}
				}
			}
		}
	}
	return possibleZones;
}

std::string HealerTemp::getName() const {
	return "HealerTemp";
}

bool HealerTemp::canActivate(Grid& grid, Character* target) const {
	Position posTarget = target->getPosition();
	std::vector<Position> possibleZones = getPossibleZones(grid);
	if (getOwner()->getPlayer() != target->getPlayer())
	{
		for (const Position& position : possibleZones) {
			if (posTarget == position) {
				return true;
			}
		}
	}
	return false;
}