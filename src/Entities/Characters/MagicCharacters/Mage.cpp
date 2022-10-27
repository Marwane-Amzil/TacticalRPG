#include <Entities/Characters/MagicCharacters/Mage.hpp>
#include <Grid.hpp>

Mage::Mage(const int x, const int y, const char player)
	: super(x, y, 60, player, 7, 25, 22, 48) {}

Mage::~Mage()
{
}

std::vector<Position> Mage::getPossibleMoves(const Grid& grid) const
{
	std::vector <Position> positions;

	for (int x = -2; x < 3; x++)
	{
		for (int y = -2; y < 3; y++)
		{
			if (abs(x) + abs(y) < 3 && x != 0 || y != 0)
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

std::vector<Position> Mage::getPossibleActions(const Grid& grid) const
{
	return std::vector<Position>();
}

bool Mage::equals(const Entity& other) const
{
	return false;
}
