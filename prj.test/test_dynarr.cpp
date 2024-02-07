#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "dynarr/dynarr.hpp"
#include "doctest.h"


TEST_CASE("rational ctor") {
	//DynArr <int> a;
	//DynArr <int> b;

	DynArr a(7);
	DynArr b(8);

	CHECK(a.Size() == b.Size());
	// b.Resize(2);
	//CHECK(a.Size() != b.Size());
}

TEST_CASE("class methods") {
	DynArr a;
	CHECK(a.Size() == 0);
	a.Resize(1);
	CHECK(a.Size() == 1);
}
