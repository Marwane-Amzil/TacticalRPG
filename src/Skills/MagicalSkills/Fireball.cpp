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

void Fireball::activate(Grid& grid, Character& target) const
{
	Position pos = target.getPosition();
	int hp = target.getHp();
	int magic = target.getMagic();
	int res_magic = target.getResMag();
	std::vector<Position> possibleZones = getPossibleZones(grid);
	
	for (const Position& position : possibleZones) {
		if (pos == position) 
		{
			for (int x = -(pos.getX()-1); x < (pos.getX() + AOE_RANGE_X); x++)
			{
				for (int y = -( pos.getY() - 1); y < (pos.getY() + AOE_RANGE_Y) ; y++)
				{
					if (x <= COLUMNS && y <= COLUMNS && x >= 0 && y >= 0)
					{

						if (grid[x][y])
						{
							std::cout << x << " ; " << y << std::endl;
							int damage = (magic * (1 - (res_magic / 200)));
							hp = grid[x][y]->getHp() - damage;
							if (hp < 0)
							{
								hp = 0;
							}
							grid[x][y]->setHp(hp);

						}
					}
				}
			}
		}
		else { // TODO, managing the no entity found. 
			std::cout << "entity " << std::endl;
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
					if (grid[pos.getX() + x][pos.getY() + y])
					{
						possibleZones.emplace_back(pos.getX() + x, pos.getY() + y);
					}
				}
			}
		}
	}
	return possibleZones;
}