#include "Fixed.hpp"
#include <cmath>
#include <iostream>

const int Fixed::num_fractional_bits = 8;

Fixed::Fixed() : value(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int& rhs) {
  std::cout << "Int constructor called" << std::endl;

  value = rhs << num_fractional_bits;
}

Fixed::Fixed(const float& rhs) {
  std::cout << "Float constructor called" << std::endl;

  value = static_cast<int>(roundf(rhs * (1 << num_fractional_bits)));
}

Fixed::Fixed(const Fixed& rhs) {
  std::cout << "Copy constructor called" << std::endl;

  value = rhs.value;
}

Fixed& Fixed::operator=(const Fixed& rhs) {
  std::cout << "Copy assignment operator called" << std::endl;

  value = rhs.value;
  return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits() const {
  std::cout << "getRawBits member function called" << std::endl;
  return value;
}

void Fixed::setRawBits(int const raw) {
  std::cout << "getRawBits member function called" << std::endl;
  value = raw;
}

float Fixed::toFloat() const {
  return static_cast<float>(value) / (1 << num_fractional_bits);
}

int Fixed::toInt() const { return value >> 8; }

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
  os << fixed.toFloat();
  return os;
}
