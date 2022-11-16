#include "Entities\Characters\PhysicalCharacters\Archer.hpp"
#include "Grid.hpp"

Archer::Archer(const int x, const int y, const char player)
	: super(x, y, 100, player, 80, 25, 20, 30) {}

Archer::~Archer()
{
}

std::vector<Position> Archer::getPossibleMoves(const Grid& grid) const
{
	std::vector <Position> positions;

	for (int x = -3; x < 4; x++)
	{
		for (int y = -3; y < 4; y++)
		{
			if (abs(x) + abs(y) <4 && x != 0 || y != 0)
			{
				if (getPosition().getX() + x < COLUMNS && getPosition().getY() + y < COLUMNS && getPosition().getX() + x >= 0 && getPosition().getY() + y >= 0)
				{
					if (!grid[getPosition().getX() + x][getPosition().getY() + y])
					{
						positions.emplace_back(getPosition().getX() + x, getPosition().getY() + y);
					}
				}
			}
		}
	}

	return positions;
}

std::vector<Position> Archer::getPossibleActions(const Grid& grid) const
{
	std::vector <Position> positions;

	for (int x = -2; x < 3; x++)
	{
		for (int y = -2; y < 3; y++)
		{
			if (abs(x) + abs(y) < 2 && x != 0 || y != 0)
			{
				if (getPosition().getX() + x < COLUMNS && getPosition().getY() + y < COLUMNS && getPosition().getX() + x >= 0 && getPosition().getY() + y >= 0)
				{
					if (grid[getPosition().getX() + x][getPosition().getY() + y])
					{
						positions.emplace_back(getPosition().getX() + x, getPosition().getY() + y);
					}
				}
			}
		}
	}
	return positions
}

bool Archer::equals(const Entity& other) const
{
	return false;
}
