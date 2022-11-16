#pragma once

#ifndef __POSITION_H__
#define __POSITION_H__

#include <ostream> // std::ostream

/*
* @brief The position class represents the coordinates of an entity in the grid.
*/
class Position
{
public:

	/**
	* @brief Default constructor. Initialize a position with values (0,0).
	*/
	constexpr Position();
	/**
	* @brief Constructor taking 2 values. Initialize a position with the given values.
	* 
	* @param x: x value
	* @param y: y value
	*/
	Position(const int x, const int y);
	/**
	* @brief Copy constructor. Initialize a position with the values of an other position.
	* 
	* @param other: position to copy
	*/
	constexpr Position(const Position& other);
	/**
	* @brief Move constructor. Initialize a position with the values of an other position.
	*
	* @param other: position to move
	*/
	constexpr Position(Position&&) = default;
	/**
	* @brief Position destructor. Explicitly defaulted (~Position() = default).
	*/
	~Position() = default;
	/**
	* @brief Method which returns the x value of the position.
	*
	* @return returns the x value of the position
	*/
    int getX() const;
	/**
	* @brief Method which returns the y value of the position.
	*
	* @return returns the y value of the position
	*/
    int getY() const;
	/**
	* @brief Method which sets the current x value of the position.
	*
	* @param x: new x value to set
	*/
	void setX(const int x);
	/**
	* @brief Method which sets the current y value of the position.
	*
	* @param x: new y value to set
	*/
	void setY(const int y);
	/**
	*
	*/
	Position& operator=(const Position& other) = default;
	/**
	*
	*/
	bool operator==(const Position& other) const;
	/**
	*
	*/
	bool operator!=(const Position& other) const;
	/**
	*
	*/
	friend std::ostream& operator<<(std::ostream& ostream, const Position& _this);

private:

	int _x, _y;
};

#endif // !__POSITION_H__