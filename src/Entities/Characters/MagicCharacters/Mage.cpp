#include <Entities/Characters/MagicCharacters/Mage.hpp>
#include <Skills/MagicalSkills/FireBall.hpp>
#include <Grid.hpp>

using namespace ::grid;

Mage::Mage(const int x, const int y, const char player)
	: super(x, y, 60, player, 7, 25, 22, 48) 
{
	setFirstSkill(new Fireball(2, 3, this));
}

std::vector<Position> Mage::getPossibleMoves(const Grid& grid) const
{
	std::vector <Position> positions;
	std::vector <Position> new_positions;
	std::vector <Position> checked_positions;


	checked_positions.emplace_back(getPosition());

	for (int i = 0; i < 3; i++) {
		for (auto& pos : checked_positions) {
			for (int x = -1; x < 2; x++) {
				for (int y = -1; y < 2; y++) {
					if (abs(x) != abs(y)) {
						Position new_pos = Position(pos.getX() + x, pos.getY() + y);

						if (new_pos.getX() < COLUMNS && new_pos.getY() < COLUMNS && new_pos.getX() >= 0 && new_pos.getY() >= 0)
						{

							if (!grid[new_pos.getX()][new_pos.getY()])
							{
								new_positions.emplace_back(new_pos);
							}

						}
					}

				}
			}
		}

		for (auto& pos : checked_positions) {
			if (std::find(positions.begin(), positions.end(), pos) == positions.end())
				positions.emplace_back(pos);
		}
		checked_positions.clear();
		for (auto& pos : new_positions) {
			if (std::find(checked_positions.begin(), checked_positions.end(), pos) == checked_positions.end())
				checked_positions.emplace_back(pos);
		}

		new_positions.clear();
	}
	std::erase(positions, getPosition());


	return positions;
}



std::vector<Position> Mage::getPossibleActions(const Grid& grid) const
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

bool Mage::equals(const Entity& other) const
{
	return false;
}

std::string_view Mage::getClass() const
{
	return "mage";
}


bool Mage::canMove(Grid& grid, int x, int y) const
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