#include <Skills/MagicalSkills/Fireball.hpp>
#include <Entities/Character.hpp>
#include <Constants.hpp>
#include <Grid.hpp>
#include <iostream>
#include <Position.hpp>
#include <Entity.hpp>
using namespace ::fireball;
using namespace ::grid;

Fireball::Fireball(int multiplier, int range, Character* character, Effect* effect)
	: super(multiplier, range,character, effect) {}

void Fireball::activate(Grid& grid, Character& character) const
{
	Position pos = character.getPosition();
	int hp = character.getHp();
	int magic = character.getMagic();
	int res_magic = character.getResMag();
	std::vector<Position> possibleZones = getPossibleZones(grid);
	
	for (const Position& position : possibleZones) {
		if (pos == position) {
			
			for (size_t x = pos.getX(); x < (pos.getX() + AOE_RANGE_X); x++)
			{
				for (size_t y = pos.getY(); y < pos.getY() + AOE_RANGE_Y; y++)
				{
					if (x <= COLUMNS && y <= COLUMNS)
					{
						std::cout << x << ";" << y << std::endl;
						if (grid[x][y])
						{
							Entity* entity = grid[x][y];
							int damage = (magic * (1 - (res_magic / 200)));
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

			character.setHp(hp);
		}
		else {
			std::cout << "sheesh" << std::endl;
		}
	}
}


std::vector<Position> Fireball::getPossibleZones(const Grid& grid) const{
	
	std::vector<Position> possibleZones;
	Position pos = getOwner()->getPosition();

	for (int x = NEG_RANGE_X ; x < RANGE_X ; x++)
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