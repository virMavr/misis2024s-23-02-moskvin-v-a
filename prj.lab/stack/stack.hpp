// stack, based on array
#include <iostream>

// declaring

// QUESTIONS:
// about DINAMYC extension


class Stack {
public:
	Stack() = default;
	Stack(const int size);
	Stack(const Stack&) = default;
	~Stack() = default;
	Stack& operator=(const Stack&) = default;

	// methods
	bool isEmpty() noexcept;
	const int& Top(); // see Top element
	void Push(const int& object); // add element on Top
	void Pop(); // delete element from Top

private:
	std::ptrdiff_t size_ = 0; // size of the stack
	int* data_ = nullptr; // pointer on stack
	int head_ = -1; // index
};