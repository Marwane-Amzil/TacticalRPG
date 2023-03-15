#include <Entities/Characters/PhysicalCharacters/Knight.hpp>
#include <Skills/PhysicalSkills/SwordSkill.hpp>
#include <Grid.hpp>

using namespace grid;
using namespace knight;

Knight::Knight(const int x, const int y, const char player)
	: super(x,y, 100, player, 80, 100, 0, 150) 
{
	setFirstSkill(new SwordSkill(2, 3, this));
}

std::vector<Position> Knight::getPossibleMoves(const Grid& grid) const
{
	std::vector <Position> positions;

	for (int x = -6; x < 7; x++)
	{
		for (int y = -6; y < 7; y++)
		{
			if (abs(x) + abs(y) < 7 && (x != 0 || y != 0))
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

std::vector<Position> Knight::getPossibleActions(const Grid& grid) const
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
	for (int x = 3; x < 5; x++) 
	{
		if (getPosition().getX() + x < COLUMNS && getPosition().getX() + x >= 0 )
		{
			if (grid[getPosition().getX() + x][getPosition().getY()])
			{
				positions.emplace_back(getPosition().getX() + x, getPosition().getY());
			}
		}
		if (getPosition().getY() + x < COLUMNS  && getPosition().getY() + x >= 0)
		{
			if (grid[getPosition().getX()][getPosition().getY() + x])
			{
				positions.emplace_back(getPosition().getX(), getPosition().getY() + x);
			}
		}
	}

	return positions;
}

bool Knight::equals(const Entity& other) const
{
	return false;
}

std::string_view Knight::getClass() const
{
	return "knight";
}

bool Knight::canMove(Grid& grid, int x, int y) const
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