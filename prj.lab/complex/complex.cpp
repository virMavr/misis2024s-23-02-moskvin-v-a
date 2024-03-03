#include "complex.hpp"

// C-TORS
Complex::Complex(const double rhs) {
	re_ = rhs;
}

Complex::Complex(const double& re, const double& im) {
	re_ = re;
	im_ = im;
}

void Complex::operator=(const Complex& rhs) {
	re_ = rhs.re_;
	im_ = rhs.im_;
}




// LOGICS
bool Complex::operator==(const Complex& rhs) {
	return (re_ == rhs.re_ && im_ == rhs.im_);
}

bool Complex::operator!=(const Complex& rhs) {
	return !operator==(rhs);
}




// ASSIGNMENTS operators
Complex& Complex::operator+=(const Complex& rhs) {
	re_ += rhs.re_;
	im_ += rhs.im_;
	return *this;
}
Complex& Complex::operator+=(const double& rhs) {
	return operator+=(Complex(rhs));
}

Complex& Complex::operator-=(const Complex& rhs) {
	re_ -= rhs.re_;
	im_ -= rhs.im_;
	return *this;
}
Complex& Complex::operator-=(const double& rhs) {
	return operator-=(Complex(rhs));
}

Complex& Complex::operator*=(const Complex& rhs) {
	re_ = (re_ * rhs.re_ - im_ * rhs.im_); // a1*a2-b1*b2
	im_ = (re_ * rhs.im_ + im_ * rhs.re_); // a1*b2+b1*a2
	return *this;
}
Complex& Complex::operator*=(const double& rhs) {
	return operator*=(Complex(rhs));
}

Complex& Complex::operator/=(const Complex& rhs) {
	re_ = (re_ * rhs.re_ + im_ * rhs.im_) / (rhs.re_ * rhs.re_ + rhs.im_ * rhs.im_);// a1*a2-b1*b2
	im_ = (rhs.re_ * im_ - re_ * rhs.im_) / (rhs.re_ * rhs.re_ + rhs.im_ * rhs.im_);// a1*b2+b1*a2
	return *this;
}
Complex& Complex::operator/=(const double& rhs) {
	return operator/=(Complex(rhs));
}



// ARITHMETIC operators
Complex operator+(const Complex& lhs, const Complex& rhs) {
	return Complex(lhs) += rhs;
}
Complex operator+(const Complex& lhs, const double rhs) {
	return Complex(lhs) += Complex(rhs);
}
Complex operator+(const double lhs, const Complex& rhs) {
	return Complex(lhs) += Complex(rhs);
}

Complex operator-(const Complex& lhs, const Complex& rhs) {
	return Complex(lhs) -= rhs;
}
Complex operator-(const Complex& lhs, const double& rhs) {
	return Complex(lhs) -= Complex(rhs);
}
Complex operator-(const double& lhs, const Complex& rhs) {
	return Complex(lhs) -= Complex(rhs);
}

Complex operator*(const Complex& lhs, const Complex& rhs) {
	return Complex(lhs) *= rhs;
}
Complex operator*(const Complex& lhs, const double& rhs) {
	return Complex(lhs) *= Complex(rhs);
}
Complex operator*(const double& lhs, const Complex& rhs) {
	return Complex(lhs) *= Complex(rhs);
}

Complex operator/(const Complex& lhs, const Complex& rhs) {
	return Complex(lhs) /= rhs;
}
Complex operator/(const Complex& lhs, const double& rhs) {
	return Complex(lhs) /= Complex(rhs);
}
Complex operator/(const double& lhs, const Complex& rhs) {
	return Complex(lhs) /= Complex(rhs);
}



//IO streams
std::ostream& operator<<(std::ostream& ostrm,const Complex& rhs)
{
	// IF I WANT in (...+...i), NEED TO COPE WITH HOW TO CHOOSE + or - and other
	// ostrm << rhs.re_ << "+" << rhs.im_ << "i"; 
	// 
	// => doing how Dmitry Valerievich say

	ostrm << "{" << rhs.re_ << "," << rhs.im_ << "}";
	return ostrm;
}
std::istream& operator>>(std::istream& istrm, Complex& rhs) 
{
	double real;
	double imaginary;
	char leftCurlyBrace;
	char comma;
	char rightCurlyBrace;

	istrm >> leftCurlyBrace >> real >> comma >> imaginary >> rightCurlyBrace;

	if (istrm.good()) {
		if (leftCurlyBrace == '{' && comma == ',' && rightCurlyBrace == '}') {
			rhs.re_ = real;
			rhs.im_ = imaginary;
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}