#include <iostream>
#include <cmath>
#include "Fixed.hpp"

const int Fixed::num_fractional_bits = 8;

Fixed::Fixed() : value(0) {}

Fixed::Fixed(const int& rhs) { value = rhs << num_fractional_bits; }

Fixed::Fixed(const float& rhs) {
  value = static_cast<int>(roundf(rhs * (1 << num_fractional_bits)));
}

Fixed::Fixed(const Fixed& rhs) { value = rhs.value; }

Fixed& Fixed::operator=(const Fixed& rhs) {
  value = rhs.value;
  return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits() const { return value; }

bool Fixed::operator==(const Fixed& rhs) const {
  if (value == rhs.value)
    return true;
  return false;
}

bool Fixed::operator!=(const Fixed& rhs) const { return !(*this == rhs); }

bool Fixed::operator<(const Fixed& rhs) const { return value < rhs.value; }

bool Fixed::operator>(const Fixed& rhs) const { return rhs < *this; }

bool Fixed::operator<=(const Fixed& rhs) const { return !(rhs < *this); }

bool Fixed::operator>=(const Fixed& rhs) const { return !(*this < rhs); }

Fixed Fixed::operator+(const Fixed& rhs) const {
  Fixed result;
  result.setRawBits(value + rhs.value);
  return result;
}

Fixed Fixed::operator-(const Fixed& rhs) const {
  Fixed result;
  result.setRawBits(value - rhs.value);
  return result;
}

Fixed Fixed::operator*(const Fixed& rhs) const {
  Fixed result;
  int64_t new_value = value * rhs.value;
  result.setRawBits(static_cast<int>(new_value >> num_fractional_bits));
  return result;
}

Fixed Fixed::operator/(const Fixed& rhs) const {
  Fixed result;
  int64_t temp = static_cast<int64_t>(value) << num_fractional_bits;
  result.setRawBits(static_cast<int>(temp / rhs.value));
  return result;
}

/*
 * Increment/Decrement operators
 * (1 >> num_fractional_bits) is the smallest number in Fixed.
 * Internal value 1 is 1 >> num_fractional_bits outiside of this class.
 */

Fixed& Fixed::operator++() {
  ++value;
  return *this;
}

Fixed& Fixed::operator--() {
  --value;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed temp(*this);
  ++(*this);
  return temp;
}

Fixed Fixed::operator--(int) {
  Fixed temp(*this);
  --(*this);
  return temp;
}

void Fixed::setRawBits(int const raw) { value = raw; }

float Fixed::toFloat() const {
  return static_cast<float>(value) / (1 << num_fractional_bits);
}

int Fixed::toInt() const { return value >> 8; }

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
  os << fixed.toFloat();
  return os;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
  if (a < b) {
    return a;
  }
  return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
  if (a < b) {
    return a;
  }
  return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
  if (a > b) {
    return a;
  }
  return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
  if (a > b) {
    return a;
  }
  return b;
}
