#pragma once

#ifndef __GRID_H__
#define __GRID_H__

#include <Entity.hpp>

constexpr int ROWS = 25;
constexpr int COLUMNS = 25;

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
	const Entity* const* operator[](const int index) const;
	/**
	*
	*/
	Entity** operator[](const int index);

private:

	Entity* _grid[25][25];
};

#endif // !__GRID_H__