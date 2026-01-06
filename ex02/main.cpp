#include "Fixed.hpp"
#include <cassert>
#include <iostream>

void test_42_requirements() {
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));

  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << Fixed::max(a, b) << std::endl;
}

void test_relational_operation() {
  Fixed x(-2);
  Fixed y(-2);
  assert(x == y);

  x = Fixed(2.5f);
  y = Fixed(2.5f);
  assert(x == y);

  y = Fixed(0.0001f);
  assert(x != y);
  assert(x >= y);

  x = Fixed(1000.1f);
  y = Fixed(1000.2f);
  assert(x != y);
  assert(x < y);
  y = Fixed(1000.1f);
  assert(x == y);
}

void test_arithmetic_operation() {
  Fixed x;
  Fixed y(2.5f);
  Fixed z(2.5f);

  x = y + z;
  std::cout << "2.5 + 2.5: " << x << std::endl;
  assert(x == y * Fixed(2));

  x = y - z;
  std::cout << "2.5 - 2.5: " << x << std::endl;
  assert(x == Fixed(0));

  x = y / z;
  std::cout << "2.5 / 2.5: " << x << std::endl;
  assert(x == Fixed(1));

  x = y * z;
  std::cout << "2.5 * 2.5: " << x << std::endl;
  assert(x == Fixed(2.5f * 2.5f));
}

void test_decrement_and_min() {
  Fixed x;
  Fixed y(1.1f);

  std::cout << x << std::endl;
  std::cout << --x << std::endl;
  std::cout << x-- << std::endl;
  std::cout << x << std::endl;
  std::cout << y << std::endl;
  std::cout << "min(1.1, 1.09): " << Fixed::min(y, Fixed(1.09f)) << std::endl;
}

int main() {
  test_42_requirements();
  test_relational_operation();
  std::cout << '\n';
  test_arithmetic_operation();
  std::cout << '\n';
  test_decrement_and_min();
}
