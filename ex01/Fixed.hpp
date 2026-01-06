#ifndef EX01_FIXED_HPP_
#define EX01_FIXED_HPP_

#include <iostream>

class Fixed {
  int value;
  static const int num_fractional_bits; // Always 8

public:
  Fixed();
  Fixed(const int& rhs);
  Fixed(const float& rhs);
  Fixed(const Fixed& rhs);
  Fixed& operator=(const Fixed& rhs);
  ~Fixed();

  int getRawBits() const;
  void setRawBits(int const raw);

  float toFloat() const;
  int toInt() const;
};

// Utilities
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif // EX01_FIXED_HPP_
