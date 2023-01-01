#include <Skills/PhysicalSkills/AxeSkill.hpp>
#include <Entities/Character.hpp>
#include <Grid.hpp>
#include <Constants.hpp>
#include <Position.hpp>
#include <iostream>

using namespace ::axeskill;
using namespace ::grid;

AxeSkill::AxeSkill(int multiplier, int range,Character* character, Effect* effect)
	: super(multiplier, range, character,effect) {}

void AxeSkill::activate(Grid& grid, Character& character) const
{
	Position pos = character.getPosition();
	int hp = character.getHp();
	int strength = character.getStrength();
	int res_strength = character.getResMag();
	std::vector<Position> possibleZones = getPossibleZones(grid);

	for (const Position& position : possibleZones) {
		if (pos == position) {
			for (size_t x = pos.getX(); x < (pos.getX() + RANGE_X); x++)
			{
				for (size_t y = pos.getY(); y < pos.getY() + RANGE_Y; y++)
				{
					if (x <= COLUMNS && y <= COLUMNS)
					{
						std::cout << x << ";" << y << std::endl;
						if (grid[x][y])
						{
							Entity* entity = grid[x][y];
							int damage = (strength * (1 - (res_strength / 200)));
							hp = entity->getHp() - damage;
							if (hp < 0)
							{
								hp = 0;
							}
							entity->setHp(hp);

						}
					}
				}
			}
		}
	}
	character.setHp(hp);
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