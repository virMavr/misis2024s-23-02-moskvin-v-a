#include "stack.hpp"

// realization

Stack::Stack(const int size) { 
	size_ = size; 
	data_ = new int[2]; // question here
}

bool Stack::isEmpty() noexcept {
	if (head_ == -1) {
		return true;
	}
	return false;
}

const int& Stack::Top() {
	if (head_ == -1) {
		throw std::logic_error("ћассив пустой");
	}
	else {
		return data_[head_];
	}
}

void Stack::Push(const int& object) {
	// if (head_ < size_ - 1) {
		head_ += 1;
		data_[head_] = object;
	// }
	// else {
		// нужно увеличить size на 1 динамически и добавить туда ???

	//}
}

void Stack::Pop() {
	if (head_ == -1) {
		throw std::logic_error("ћассив пустой!");
	}
	else {
		data_[head_] = 0;
		head_ -= 1;
	}
}
