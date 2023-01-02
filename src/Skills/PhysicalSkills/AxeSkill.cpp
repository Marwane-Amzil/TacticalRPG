#include <Skills/PhysicalSkills/AxeSkill.hpp>
#include <Entities/Character.hpp>
#include <Grid.hpp>
#include <Constants.hpp>
#include <Position.hpp>
#include <iostream>

using namespace ::axeskill;
using namespace ::grid;

// AxeSkill constructor
AxeSkill::AxeSkill(int multiplier, int range,Character* character, Effect* effect)
	: super(multiplier, range, character,effect) {}

void AxeSkill::activate(Grid& grid, Character& target) const
{
	// Declaration 
	Position pos = target.getPosition();
	int hp = target.getHp();
	int strength = target.getStrength();
	int res_strength = target.getResMag();
	std::vector<Position> possibleZones = getPossibleZones(grid);

	// Processing
	for (const Position& position : possibleZones) {
		if (pos == position) {
			int damage = (strength * (1 - (res_strength / 200)));
			hp = target.getHp() - damage;
			if (hp < 0)
			{
				hp = 0;
			}
			target.setHp(hp);
		}

	}
}

std::vector<Position> AxeSkill::getPossibleZones(const Grid& grid) const {

	std::vector<Position> possibleZones;
	Position pos = getOwner()->getPosition();

	for (int x = NEG_RANGE_X; x < RANGE_X; x++)
	{
		for (int y = NEG_RANGE_Y; y < RANGE_Y; y++)
		{
			if (abs(x) + abs(y) < RANGE_X && x != 0 || y != 0)
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