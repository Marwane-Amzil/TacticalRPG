#include <Grid.hpp>
#include <Entity.hpp>

Grid::Grid()
	: _grid() {}

void Grid::addEntity(Entity* const entity)
{
	/*
	* Using the entity's position, we set the entity to its position.
	* This allows us to set a specific entity at a specific position without
	* explicitly indicating the position to the function.
	*/
	_grid[entity->getPosition().getX()][entity->getPosition().getY()] = entity;
}

void Grid::move(const int from_x, const int from_y, const int to_x, const int to_y)
{
	/*
	* std::swap can swap the emplacement of 2 objects of the same type.
	* Using pointers in this situation allows us to swap any entities in the grid,
	* which can be a character, an obstacle, even a nullptr.
	* In this case, it should swap the current entity with a nullptr since a movement
	* is only allowed in an empty case.
	*/
	std::swap(_grid[from_x][from_y], _grid[to_x][to_y]);
}

const std::array<Entity*, COLUMNS>& Grid::operator[](const size_t& index) const
{
	return _grid[index];
}

std::array<Entity*, COLUMNS>& Grid::operator[](const size_t& index)
{
	return _grid[index];
}