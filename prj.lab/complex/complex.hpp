// COMPLEX LIBRARY (1st term 1st semester MISIS Applied Math)
// 
// NOTES:
// rhs - right hand side (выражение справа от оператора)
// try understand what you do
// when you OVERLOAD << OR >> you give in () 2 params: STREAM and OBJECT
// 
// TASKS:
// 1) ADD exceptions
// 2) ADD slovechki

#ifndef COMPLEX_LIBRARY // Include guards
#define COMPLEX_LIBRARY

#include <iostream>
#include <sstream>

struct Complex
{
	Complex() = default;
	Complex(const double rhs);
	Complex(const double& re, const double& im);
	~Complex() = default;
	Complex(const Complex&) = default;
	void operator=(const Complex& rhs);

	bool operator==(const Complex& rhs);
	bool operator!=(const Complex& rhs);
	// WE CAN'T COMPARE COMPLEX NUMS SO >, <= and others is absent

	// ASSIGNMENTS (присваювающие) operators with complex and double (common num)
	Complex& operator+=(const Complex& rhs);
	Complex& operator+=(const double& rhs);
	Complex& operator-=(const Complex& rhs);
	Complex& operator-=(const double& rhs);
	Complex& operator*=(const Complex& rhs);
	Complex& operator*=(const double& rhs);
	Complex& operator/=(const Complex& rhs);
	Complex& operator/=(const double& rhs);

	double re_ = 0.0; // real part of complex num
	double im_ = 0.0; // imaginary part of complex num
};

// ARITHMETIC operators declaration
Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator+(const Complex& lhs, const double& rhs);
Complex operator+(const double& lhs, const Complex& rhs);

Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const double& rhs);
Complex operator-(const double& lhs, const Complex& rhs);

Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const double& rhs);
Complex operator*(const double& lhs, const Complex& rhs);

Complex operator/(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const double& rhs);
Complex operator/(const double& lhs, const Complex& rhs);

//IO streams
std::ostream& operator<<(std::ostream& osrtm,const Complex& rhs);
std::istream& operator>>(std::istream& istrm, Complex& rhs);

#endif