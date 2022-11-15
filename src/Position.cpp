#include <Position.hpp>

constexpr Position::Position()
	: _x(0), _y(0) {}

// Default constructor
Position::Position(const int x, const int y) : _x(x), _y(y) 
// Double dot, is for the initialisation of _x and _y. When doing _x(x),_y(y). Those variables get the value of x , y
{
}

// Copy constructor 
constexpr Position::Position(const Position& other)
//Same usage here as the top Constructor. 

	: _x(other._x), _y(other._y) {}

// ----------------------------------------------   Start  Getters / Setters    ------------------------------------------------------------

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
// ----------------------------------------------   End  Getters / Setters    ------------------------------------------------------------

bool Position::operator==(const Position& other) const
{
	// The other object refears to the other entity in right side of the equal. 
	// Exemple pos1 == pos2. Other is pos2. 
	return other._x == _x && other._y == _y;
}

bool Position::operator!=(const Position& other) const
{	
	// Operator== gives the equality we want the inequality so it is the opposite. 
	return !(*this == other);
}


// This prints out the Position, it is mainly for debugging
std::ostream& operator<<(std::ostream& ostream, const Position& _this)
{
	ostream << '[' << _this._x << ',' << _this._y << ']';
	return ostream;
}
