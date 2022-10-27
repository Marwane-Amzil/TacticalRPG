#pragma once

#ifndef __POSITION_H__
#define __POSITION_H__

#include <ostream>

class Position
{
public:

	/**
	* 
	*/
	constexpr Position();
	/**
	*
	*/
	Position(const int x, const int y);
	/**
	* 
	*/
	constexpr Position(const Position& other);
	/**
	*
	*/
	constexpr Position(Position&&) = default;
	/**
	* 
	*/
	~Position() = default;
	/**
	* 
	*/
    int getX() const;
	/**
	*
	*/
    int getY() const;
	/**
	*
	*/
	void setX(const int x);
	/**
	* 
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