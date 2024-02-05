#include "rational.hpp"

std::ostream& Rational::writeTo(std::ostream& ostrm) const
{
	ostrm << num << "/" << den;
	return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm)
{
	int num_(0), den_(0);
	char cherta;
	istrm >> num_ >> cherta >> den_;
	if (istrm.good()) {
		if (cherta == '/' && den_ != 0) {
			num = num_;
			den = den_;
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}

	return istrm;
}

// ��� ��� ���������� � ������
int nod(int m, int n) { return n ? nod(n, m % n) : m; }

// ����������� ����� 1 �����
Rational::Rational(const int number)
{
	num = number;
	den = 1;
}

// ����������� ����� 2 �����
Rational::Rational(const int num_, const int den_)
{
	if (den_ > 0) {
		num = num_ / nod(num_, den_);
		den = den_ / nod(num_, den_);
	}
	if (den_ < 0) {
		num = -num_ / nod(num_, den_);
		den = -den_ / nod(num_, den_);
	}
	if (den_ == 0) {
		throw std::invalid_argument("�������������� � ���� 0 � �����������");
	}
}