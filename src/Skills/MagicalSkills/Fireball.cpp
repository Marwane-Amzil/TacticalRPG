#include <Skills/MagicalSkills/Fireball.hpp>
#include <Entities/Character.hpp>
#include <Constants.hpp>
#include <Grid.hpp>

using namespace ::fireball;
using namespace ::grid;

Fireball::Fireball(int multiplier, int range, Character* character, Effect* effect)
	: super(multiplier, range,character, effect) {}

void Fireball::activate(Grid& grid, Character& character) const
{
	int hp = character.getHp();
	int magic = character.getMagic();
	int res_magic = character.getResMag();
	
	std::vector<Position> possibleZones = getPossibleZones(grid);
	for (size_t i = 0; i < possibleZones.size(); i++)
	{
		if (grid[possibleZones[i].getX()][possibleZones[i].getY()] = &character)
		{
			/*hp = hp - (magic * (1 - (res_magic / 200)));
			if (hp < 0)
			{
				hp = 0;
			}*/
		}
	}
	
	
	character.setHp(100);

}


std::vector<Position> Fireball::getPossibleZones(const Grid& grid) const{
	
	std::vector<Position> possibleZones;
	Position pos = getOwner()->getPosition();

	for (int x = NEG_RANGE ; x < RANGE ; x++)
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