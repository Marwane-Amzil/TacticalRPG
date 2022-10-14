#include <Position.hpp>
#include <iostream>

Position::Position()
	: _x(0), _y(0) {}

Position::Position(const int x, const int y)
	: _x(x), _y(y) {}

Position::Position(const Position& autre)
	: _x(autre._x), _y(autre._y) {}

Position::~Position() {}

int Position::getX() const
{
	return _x;
}

int Position::getY() const
{
	return _y;
}

void Position::setX(const int x)
{
	_x = x;
}

void Position::setY(const int y)
{
	_y = y;
}

void Position::setPosition(const int x, const int y)
{
	_x = x;
	_y = y;
}

void Position::PositionToPx()
{
	_x = _x * 50 + 12.5;
	_y = _y * 50;
}

void Position::PxToPosition()
{
	_x = (_x - 12.5) / 50;
	_y = _y / 50;
}

bool Position::operator==(const Position& autre) const
{
	return (autre._x == _x && autre._y == _y);
}

bool Position::operator!=(const Position& autre) const
{
	return !(*this == autre);
}

std::ostream& operator<<(std::ostream& ostream, const Position& position)
{
	ostream << '[' << position._x << ',' << position._y << ']';
	return ostream;
}
