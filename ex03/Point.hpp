#ifndef EX03_POINT_HPP_
#define EX03_POINT_HPP_

#include "Fixed.hpp"

class Point {
  const Fixed _x;
  const Fixed _y;

 public:
  Point();
  Point(const float x, const float y);
  Point(const Fixed& x, const Fixed& y);
  Point(const Point& other);
  const Point& operator=(const Point& other) const;
  ~Point();

  const Fixed& x() const;
  const Fixed& y() const;
};

// Return true if point is inside the triangle abc, false otherwise
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif  // EX03_POINT_HPP_
