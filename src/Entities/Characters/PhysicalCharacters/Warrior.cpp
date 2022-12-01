#include <Entities/Characters/PhysicalCharacters/Warrior.hpp>
#include <Grid.hpp>

using namespace ::grid;

Warrior::Warrior(const int x, const int y, const char player)
	: super(x, y, 80, player, 100, 50, 25, 75) {}

std::vector<Position> Warrior::getPossibleMoves(const Grid& grid) const
{
	std::vector <Position> positions;

	for (int x = -4; x < 5; x++)
	{
		for (int y = -4; y < 5; y++)
		{
			if (abs(x) + abs(y) < 5 && x != 0 || y != 0)
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

std::vector<Position> Warrior::getPossibleActions(const Grid& grid) const
{
	std::vector <Position> positions;

	for (int x = -1; x < 2; x++)
	{
		for (int y = -1; y < 2; y++)
		{
			if (abs(x) + abs(y) < 1 && x != 0 || y != 0)
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

	return positions;
}

bool Warrior::equals(const Entity& other) const
{
	return false;
}
