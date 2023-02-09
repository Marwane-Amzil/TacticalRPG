#include <Entities/Characters/PhysicalCharacters/Archer.hpp>
#include <Skills/PhysicalSkills/BowShot.hpp>

#include <Grid.hpp>

using namespace ::grid;

Archer::Archer(const int x, const int y, const char player)
	: super(x, y, 100, player, 80, 25, 20, 30) 
{
	setFirstSkill(new BowShot(2, 3, this));
}

std::vector<Position> Archer::getPossibleMoves(const Grid& grid) const
{
	std::vector <Position> positions;

	for (int x = -3; x < 4; x++)
	{
		for (int y = -3; y < 4; y++)
		{
			if (abs(x) + abs(y) <4 && (x != 0 || y != 0))
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
	return positions;
}

bool Archer::equals(const Entity& other) const
{
	return false;
}

std::string_view Archer::getClass() const
{
	return "archer";
}


bool Archer::canMove(Grid& grid, int x, int y) const
{
	Position* pos = new Position(x, y);
	std::vector<Position> possibleMoves = getPossibleMoves(grid);

	for (Position& move : possibleMoves)
	{
		if (move == *pos)
		{
			return true;
		}
	}
	return false;

}