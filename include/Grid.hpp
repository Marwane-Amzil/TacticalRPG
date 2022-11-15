#pragma once

#ifndef __GRID_H__
#define __GRID_H__

#include <Entity.hpp>
#include <array>

constexpr int ROWS = 20;
constexpr int COLUMNS = 20;

// The grid is the Area where, Entities are going to be. 

class Grid
{
public:

	/**
	*
	*/
	Grid();
	/*
	*
	*/
	~Grid();
	/**
	*
	*/
	void addEntity(Entity* const entity);
	/**
	*
	*/
	void move(const int from_x, const int from_y, const int to_x, const int to_y);
	/**
	*
	*/
	const std::array<Entity*, COLUMNS>& operator[](const int index) const;
	/**
	*
	*/
	std::array<Entity*, COLUMNS>& operator[](const int index);

private:

	std::array<std::array<Entity*, ROWS>, COLUMNS> _grid;
};

#endif // !__GRID_H__