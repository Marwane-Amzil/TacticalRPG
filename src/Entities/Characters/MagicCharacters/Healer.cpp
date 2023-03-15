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
	std::vector <Position> new_positions;
	std::vector <Position> checked_positions;


	checked_positions.emplace_back(getPosition());

	for (int i = 0; i < 5; i++) {
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