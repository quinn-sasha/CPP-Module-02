#ifndef EX00_FIXED_HPP_
#define EX00_FIXED_HPP_

class Fixed {
  int value;
  static const int num_fractional_bits; // Always 8

public:
  Fixed();
  Fixed(const Fixed& rhs);
  Fixed& operator=(const Fixed& rhs);
  ~Fixed();

  int getRawBits() const;
  void setRawBits(int const raw);
};

#endif // EX00_FIXED_HPP_
