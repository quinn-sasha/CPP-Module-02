#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {}

Point::Point(const Fixed& x, const Fixed& y) : _x(x), _y(y) {}

// No need to implement
const Point& Point::operator=(const Point& other) const {
  (void)other;
  return *this;
}

// No need to implement
Point::~Point() {}

const Fixed& Point::x() const { return _x; }

const Fixed& Point::y() const { return _y; }
