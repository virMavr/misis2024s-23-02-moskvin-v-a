#include <iostream>
#include <sstream>

#ifndef RATIONAL_LIBRARY
#define RATIONAL_LIBRARY

class Rational {
public:
	Rational() = default; //дефолтный конструктор
	// explicit запрещает неявные преобразования
	Rational(const int number);//конструктор из 1 числа (реализация ниже)
	Rational(const int num, const int den); //конструктор из 2 чисел (реализация ниже)
	Rational(const Rational&) = default; //дефолтный конструктор копирования
	~Rational() = default; //дефолтный деструктор
	Rational& operator=(const Rational&) = default; // дефолтный оператор присваивания


	// перегрузка базовых булевых операторов для класса Rational
	// !!! константный метод значит то, что мы в нём не можем изменять поля класса
	bool operator==(const Rational& rhs) const { return (num == rhs.num) && (den == rhs.den); }
	bool operator!=(const Rational& rhs) const { return !operator==(rhs); }
	bool operator>(const Rational& rhs) const { return (num * rhs.den) > (rhs.num * den); }
	bool operator<(const Rational& rhs) const { return !operator>(rhs); }
	bool operator>=(const Rational& rhs) const { return (num * rhs.den) >= (rhs.num * den); }
	bool operator<=(const Rational& rhs) const { return !operator>=(rhs); }

	// перегрузка операторов +,-, *, /
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

	//методы для вывода private полей класса
	int64_t checknum() { return num; }
	int64_t checkden() { return den; }


	//функции для << и >>
	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);

private:
	int64_t num = 0; //числитель
	int64_t den = 1; //знаменатель

};

//перегрузка оператора <<
inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs)
{
	return rhs.writeTo(ostrm);
}
inline std::istream& operator>>(std::istream& istrm, Rational& rhs)
{
	return rhs.readFrom(istrm);
}

#endif