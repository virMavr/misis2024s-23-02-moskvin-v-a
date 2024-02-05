#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "rational/rational.hpp"
#include "doctest.h"
#include <iostream>

//¬опросы: 
//сравнение вещ чисел в тестах
//как правильно перегрузить += и тд
//как протестировать потоки ввода-вывода

TEST_CASE("ctors") {
	Rational a(3, 5);
	Rational b(2);
	Rational c;
	CHECK(a.checknum() == 3);
	CHECK(a.checkden() == 5);
	CHECK(b.checknum() == 2);
	CHECK(b.checkden() == 1);
	CHECK(c.checknum() == 0);
	CHECK(c.checkden() == 1);
}

TEST_CASE("overloaded operators") {
	Rational a(3, 4);
	Rational b(5, 4);
	Rational res0(-1, 2);
	Rational res1(11,4);
	CHECK(a + b == 2);
	CHECK(a - b == res0);
	CHECK((a += 2) == res1);
}

//TEST_CASE("streams") {
//	Rational a(9, 7);
//
//}