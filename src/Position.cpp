#include <Position.hpp>

constexpr Position::Position()
	: _x(0), _y(0) {}

Position::Position(const int x, const int y)
	: _x(x), _y(y) {}

constexpr Position::Position(const Position& other)
	: _x(other._x), _y(other._y) {}

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

bool Position::operator==(const Position& other) const
{
	return other._x == _x && other._y == _y;
}

bool Position::operator!=(const Position& other) const
{
	return !(*this == other);
}

std::ostream& operator<<(std::ostream& ostream, const Position& _this)
{
	ostream << '[' << _this._x << ',' << _this._y << ']';
	return ostream;
}
