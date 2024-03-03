#include <iostream>
#include <sstream>

#ifndef RATIONAL_LIBRARY
#define RATIONAL_LIBRARY

class Rational {
public:
	Rational() = default; //��������� �����������
	// explicit ��������� ������� ��������������
	Rational(const int number);//����������� �� 1 ����� (���������� ����)
	Rational(const int num, const int den); //����������� �� 2 ����� (���������� ����)
	Rational(const Rational&) = default; //��������� ����������� �����������
	~Rational() = default; //��������� ����������
	Rational& operator=(const Rational&) = default; // ��������� �������� ������������


	// ���������� ������� ������� ���������� ��� ������ Rational
	// !!! ����������� ����� ������ ��, ��� �� � �� �� ����� �������� ���� ������
	bool operator==(const Rational& rhs) const { return (num == rhs.num) && (den == rhs.den); }
	bool operator!=(const Rational& rhs) const { return !operator==(rhs); }
	bool operator>(const Rational& rhs) const { return (num * rhs.den) > (rhs.num * den); }
	bool operator<(const Rational& rhs) const { return !operator>(rhs); }
	bool operator>=(const Rational& rhs) const { return (num * rhs.den) >= (rhs.num * den); }
	bool operator<=(const Rational& rhs) const { return !operator>=(rhs); }

	// ���������� ���������� +,-, *, /
	Rational operator+(const Rational& rhs) { return Rational(num * rhs.den + rhs.num * den, den * rhs.den); }
	Rational operator-(const Rational& rhs) { return Rational(num * rhs.den - rhs.num * den, den * rhs.den); }
	Rational operator*(const Rational& rhs) { return Rational(num * rhs.num, den * rhs.den); }
	Rational operator/(const Rational& rhs) { return Rational(num * rhs.den, den * rhs.num); }
	Rational operator+=(const Rational& rhs) {
		num = num * rhs.den + rhs.num * den;
		den = den * rhs.den;
		return *this;
	}
	//Rational operator-=(const Rational& rhs) { return Rational(num * rhs.den - rhs.num * den, den * rhs.den); }
	//Rational operator*=(const Rational& rhs) { return Rational(num * rhs.num, den * rhs.den); }
	//Rational operator/=(const Rational& rhs) { return Rational(num * rhs.den, rhs.num * den); }

	//������ ��� ������ private ����� ������
	int64_t checknum() { return num; }
	int64_t checkden() { return den; }


	//������� ��� << � >>
	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);

private:
	int64_t num = 0; //���������
	int64_t den = 1; //�����������

};

//���������� ��������� <<
inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs)
{
	return rhs.writeTo(ostrm);
}
inline std::istream& operator>>(std::istream& istrm, Rational& rhs)
{
	return rhs.readFrom(istrm);
}

#endif