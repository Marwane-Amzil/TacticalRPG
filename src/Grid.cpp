#include <Grid.hpp>

Grid::Grid()
	: _grid() {}

Grid::~Grid()
{
}

void Grid::addEntity(Entity* const entity)
{
}

void Grid::move(const int from_x, const int from_y, const int to_x, const int to_y)
{// This function simply switches the different positions between position(from_x,from_y) to another position(to_x,to_y)
	std::swap(_grid[from_x][from_y], _grid[to_x][to_y]);
}

const std::array<Entity*, COLUMNS>& Grid::operator[](const int index) const
{
	return _grid[index];
}

std::array<Entity*, COLUMNS>& Grid::operator[](const int index)
{
	return _grid[index];
}