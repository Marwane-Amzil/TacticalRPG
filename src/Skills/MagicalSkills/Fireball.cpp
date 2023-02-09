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

void Fireball::activate(Grid& grid, Character* target) const
{
	Position posTarget = target->getPosition();
	int hp = target->getHp();
	int magic = _character->getMagic();
	int res_magic = target->getResMag();
	std::vector<Position> possibleZones = getPossibleZones(grid);
	
	for (const Position& position : possibleZones) {
		if (posTarget == position) 
		{
			for (int x = -(posTarget.getX()); x <= (posTarget.getX() + AOE_RANGE_X); x++)
			{
				for (int y = -( posTarget.getY()); y <= (posTarget.getY() + AOE_RANGE_Y) ; y++)
				{
					if (x <= COLUMNS && y <= COLUMNS && x >= 0 && y >= 0)
					{

						if (grid[x][y])
						{
						
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
			
		}
	}
}



std::vector<Position> Fireball::getPossibleZones(const Grid& grid) const{
	
	std::vector<Position> possibleZones;
	const Position& posOwner = getOwner()->getPosition();

	for (int x = NEG_RANGE_X ; x <= RANGE_X ; x++)
{
		for (int y = NEG_RANGE_Y; y <= RANGE_Y; y++)
		{
			if (abs(x) + abs(y) <= RANGE_X && x != 0 || y != 0)
			{
				if (posOwner.getX() + x <= COLUMNS && posOwner.getY() + y <= COLUMNS && posOwner.getX() + x >= 0 && posOwner.getY() + y >= 0)
				{
					if (grid[posOwner.getX() + x][posOwner.getY() + y])
					{
						possibleZones.emplace_back(posOwner.getX() + x, posOwner.getY() + y);
					}
				}
			}
		}
	}
	return possibleZones;
}

std::string Fireball::getName() const
{
	return "Fireball";
}
