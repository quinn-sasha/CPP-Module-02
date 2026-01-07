#include "Fixed.hpp"
#include "Point.hpp"

namespace {
/*
 * If ac is the left side of ab, result > 0
 * If ac is the right side of ab, result < 0
 * If c is in the ab, result == 0
 */
Fixed cross_product(const Point& a, const Point& b, const Point& c) {
  Point ab(b.x() - a.x(), b.y() - a.y());
  Point ac(c.x() - a.x(), c.y() - a.y());
  return ab.x() * ac.y() - ab.y() * ac.x();
}
} // namespace

// Return true if point is inside the triangle abc, false otherwise
bool bsp(Point const a, Point const b, Point const c, Point const point) {
  Fixed side1 = cross_product(a, b, point);
  Fixed side2 = cross_product(b, c, point);
  Fixed side3 = cross_product(c, a, point);

  Fixed zero(0);
  // If point is in the edge or at vertice
  if (side1 == zero || side2 == zero || side3 == zero) {
    return false;
  }
  bool is_all_left = (side1 > 0 && side2 > 0 && side3 > 0);
  bool is_all_right = (side1 < 0 && side2 < 0 && side3 < 0);
  if (is_all_left) {
    return true;
  }
  if (is_all_right) {
    return true;
  }
  return false;
}
