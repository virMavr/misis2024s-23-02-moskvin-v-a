#include <iostream>
#include <sstream>

struct Complex {
  Complex() {}
  explicit Complex(const double real); // обязательно передай дабл
  Complex(const double real, const double imaginary); 
  bool operator==(const Complex& rhs) const { return (re == rhs.re) && (im == rhs.im); }
  bool operator!=(const Complex& rhs) const { return !operator==(rhs); }
  Complex& operator+=(const Complex& rhs);
  Complex& operator+=(const double rhs) { return operator+=(Complex(rhs)); }
  //Complex& operator-=(const Complex& rhs);
  //Complex& operator-=(const double rhs) { return operator-=(Complex(rhs)); }
  //Complex& operator*=(const Complex& rhs);
  Complex& operator*=(const double rhs);
  std::ostream& writeTo(std::ostream& ostrm) const; // для записи
  std::istream& readFrom(std::istream& istrm); // для чтения

  double re{ 0.0 }; // изначальные значения
  double im{ 0.0 };
 
  static const char leftBrace{ '{' };
  static const char separator{ ',' };
  static const char rightBrace{ '}' };
};

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs)
{
  return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Complex& rhs)
{
  return rhs.readFrom(istrm);
}