#include <cassert>
#include "Point.hpp"

int main() {
  Point a(5.0f, 10.0f);
  Point b(2.0f, 1.0f);
  Point c(9.0f, 1.0f);

  Point p_in1(4.0f, 6.0f);
  assert(bsp(a, b, c, p_in1));

  Point p_in2(8.0f, 1.5f);
  assert(bsp(a, b, c, p_in2));

  Point p_out1;
  assert(!bsp(a, b, c, p_out1));

  Point p_out2(11.0f, 11.0f);
  assert(!bsp(a, b, c, p_out2));

  Point p_in_vertice(c);
  assert(!bsp(a, b, c, p_in_vertice));

  Point p_in_edge(5.0f, 1.0f);
  assert(!bsp(a, b, c, p_in_edge));
}
