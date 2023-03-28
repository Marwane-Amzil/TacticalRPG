#pragma once

#ifndef __GRID_H__
#define __GRID_H__

#include <array> // std::array
#include <vector> // std::vector
#include <Constants.hpp> // Constant values

/**
* @brief The Entity class. Forward declared to avoid recursive includes in some files when it's not needed.
* Since our use of entities require polymorphism, we need to use pointers to entities instead of
* actual entity objects. This allows the forward declaration since it is not required to know the implementation
* of an object to use a pointer to this object. A pointer is still an integer no matter which type
* it is pointing to.
*/ 
class Entity;
class Position;
/*
* @brief The Grid class represents the field of the game and it will store entities.
*/
class Grid
{
public:

	/**
	* @brief Default constructor. Initialize an empty grid of entities.
	*/
	Grid();
	/*
	* @brief Grid destructor. Explicitly defaulted (~Grid() = default)
	*/
	~Grid() = default;
	/**
	* @brief Method which adds an entity in the grid. The entity's position will be used
	* to determine where to add the entity in the grid. Since it uses the entity's position,
	* assigning a nullptr to this function will result in undefinied behaviour or even a crash.
	* 
	* @param entity: entity to add
	*/
	void addEntity(Entity* const entity);
	/**
	* @brief Method which moves an entity from its position to a given position. Since
	* the movement of a character is restricted to cases where there's nothing (nullptr),
	* it just performs a swap of 2 cases.
	* 
	* @param from_x: starting x position
	* @param from_y: starting y position
	* @param to_x: final x position
	* @param to_y: final y position
	*/
	void move(const int from_x, const int from_y, const int to_x, const int to_y);
	/**
	* @brief Method which display the grid and its contents inside the console.
	* It is mainly used for debugging process in case we would need a vision of what is going on.
	*/
	void display() const;
	/**
	* @brief Overloaded [] operator for the Grid class. Behaves the same as any
	* [] operator in a standard container such a C-style array of std::vector.
	* This one is the const version of the operator to be able to use it with Grid
	* marked as const.
	* 
	* @param index: row to select an element from
	* 
	* @return returns the asked row
	*/

	std::vector<Entity*> getRedEntities();

	std::vector<Entity*> getBlueEntities();

	/**
	* Method wich returns the entity at a given position. If the position is out of bounds or is there is no entity, 
	*	The method will return nullptr.
	*/
	const std::vector<Entity*> getEntitys();
	
	const std::array<Entity*, ::grid::COLUMNS>& operator[](const size_t& index) const;

	
	
	
	/**
	* @brief Overloaded [] operator for the Grid class. Behaves the same as any
	* [] operator in a standard container such a C-style array of std::vector.
	* This one is the non-const version of the operator to be able to insert or modify
	* element within the grid.
	*
	* @param index: row to select an element from
	*
	* @return returns the asked row
	*/
	std::array<Entity*, ::grid::COLUMNS>& operator[](const size_t& index);

private:

	std::array<std::array<Entity*, ::grid::ROWS>, ::grid::COLUMNS> _grid;
};

#endif // !__GRID_H__