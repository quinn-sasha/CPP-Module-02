#ifndef EX02_FIXED_HPP_
#define EX02_FIXED_HPP_

#include <iostream>

class Fixed {
  int value;
  static const int num_fractional_bits;  // Always 8

 public:
  Fixed();
  explicit Fixed(const int& rhs);
  explicit Fixed(const float& rhs);
  Fixed(const Fixed& rhs);
  Fixed& operator=(const Fixed& rhs);
  ~Fixed();

  bool operator==(const Fixed& rhs) const;
  bool operator!=(const Fixed& rhs) const;
  bool operator<(const Fixed& rhs) const;
  bool operator>(const Fixed& rhs) const;
  bool operator<=(const Fixed& rhs) const;
  bool operator>=(const Fixed& rhs) const;

  Fixed operator+(const Fixed& rhs) const;
  Fixed operator-(const Fixed& rhs) const;
  Fixed operator*(const Fixed& rhs) const;
  Fixed operator/(const Fixed& rhs) const;

  Fixed& operator++();
  Fixed& operator--();
  Fixed operator++(int);
  Fixed operator--(int);

  int getRawBits() const;
  void setRawBits(int const raw);

  float toFloat() const;
  int toInt() const;

  static Fixed& min(Fixed& a, Fixed& b);
  static const Fixed& min(const Fixed& a, const Fixed& b);
  static Fixed& max(Fixed& a, Fixed& b);
  static const Fixed& max(const Fixed& a, const Fixed& b);
};

// Utilities
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif  // EX02_FIXED_HPP_
