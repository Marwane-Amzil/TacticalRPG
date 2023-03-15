#include <Entities/Characters/MagicCharacters/Healer.hpp>
#include <Skills/MagicalSkills/HealerTemp.hpp>
#include <Grid.hpp>

using namespace ::grid;
using namespace ::healer;

Healer::Healer(const int x, const int y, const char player)
	: super(x, y, 60, player, 7, 25, 22, 48) {}

std::vector<Position> Healer::getPossibleMoves(const Grid& grid) const
{
	std::vector <Position> positions;

	for (int x = NEG_MOVES; x < MOVES; x++)
	{
		for (int y = NEG_MOVES; y < MOVES; y++)
		{
			if (abs(x) + abs(y) < MOVES && (x != 0 || y != 0))
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

std::vector<Position> Healer::getPossibleActions(const Grid& grid) const
{
	std::vector <Position> positions;

	for (int x = NEG_MOVES; x < MOVES; x++)
	{
		for (int y = NEG_MOVES; y < MOVES; y++)
		{
			if (abs(x) + abs(y) < MOVES && x != 0 || y != 0)
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

bool Healer::equals(const Entity& other) const
{
	return false;
}

std::string_view Healer::getClass() const
{
	return "healer";
}

bool Healer::canMove(Grid& grid, int x, int y) const
{
	Position pos = Position(x, y);
	std::vector<Position> possibleMoves = getPossibleMoves(grid);

	for (Position& move : possibleMoves)
	{
		if (move == pos)
		{
			return true;
		}
	}
	return false;

}