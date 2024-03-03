// StackArr, based on array
#include <iostream>

// declaring

// QUESTIONS:
// about DINAMYC extension
#ifndef STACKARR_LIBRARY
#define STACKARR_LIBRARY

class StackArr {
public:
	StackArr() = default;
	StackArr(const int size);
	StackArr(const StackArr&) = default;
	~StackArr() = default;
	StackArr& operator=(const StackArr&) = default;

	// methods
	bool isEmpty() noexcept;
	int Size();
	const int& Top(); // see Top element
	void Push(const int& object); // add element on Top
	void Pop(); // delete element from Top

private:
	std::ptrdiff_t size_ = 0; // size of the StackArr
	int* data_ = nullptr; // pointer on StackArr
	int head_ = -1; // index
};

#endif