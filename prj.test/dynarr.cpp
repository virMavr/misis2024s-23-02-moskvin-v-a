#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>

// template <typename T>

class DynArr {
public:
	DynArr() = default;
	DynArr(const ptrdiff_t new_size);
	~DynArr() = default;
	DynArr(const DynArr&);


	ptrdiff_t Size() const
	{
		return size_;
	}
	void Resize(const ptrdiff_t new_size)
	{
		size_ = new_size;
	}
	float& operator[](const ptrdiff_t S)
	{
		return data_[S];
	}
private:
	ptrdiff_t size_ = 0;
	//T* data_ = nullptr;
	float* data_ = nullptr;
};

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

DynArr::DynArr(const ptrdiff_t new_size)
{
	size_ = new_size;
}
