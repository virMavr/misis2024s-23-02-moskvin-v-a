#include <iostream>

// QUESTIONS:
// about DINAMYC extension


class StackArr {
public:
	StackArr() = default;
	StackArr(const int size);
	StackArr(const StackArr&) = default;
	~StackArr() = default;
	StackArr& operator=(const StackArr&) = default;

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

int main()
{
	StackArr a(1);
	a.Push(6);
	a.Push(7);
	a.Push(8);
	std::cout << a.Top() << std::endl;

}







// realization

StackArr::StackArr(const int size) { 
	size_ = size; 
	data_ = new int[2]; // question here
}

bool StackArr::isEmpty() noexcept {
	if (head_ == -1) {
		return true;
	}
	return false;
}

const int& StackArr::Top() {
	if (head_ == -1) {
		throw std::logic_error("ћассив пустой");
	}
	else {
		return data_[head_];
	}
}

void StackArr::Push(const int& object) {
	// if (head_ < size_ - 1) {
		head_ += 1;
		data_[head_] = object;
	// }
	// else {
		// нужно увеличить size на 1 динамически и добавить туда ???

	//}
}

void StackArr::Pop() {
	if (head_ == -1) {
		throw std::logic_error("ћассив пустой!");
	}
	else {
		data_[head_] = 0;
		head_ -= 1;
	}
}
