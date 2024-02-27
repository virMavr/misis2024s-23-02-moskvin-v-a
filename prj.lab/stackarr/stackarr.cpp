#include "stackarr.hpp"

// realization

StackArr::StackArr(const int size) { 
	if (size < 0) {
		throw std::logic_error("Размер массива не может быть отрицательным");
	}
	else {
		size_ = size;
		data_ = new int[size_]; // question here
	}
}

bool StackArr::isEmpty() noexcept {
	if (head_ == -1) {
		return true;
	}
	return false;
}

int StackArr::Size() {
	return size_;
}

const int& StackArr::Top() {
	if (head_ == -1) {
		throw std::logic_error("Массив пустой");
	}
	else {
		return data_[head_];
	}
}

void StackArr::Push(const int& object) {
	// just add new element
	if (head_ < size_ - 1) {
		head_ += 1;
		data_[head_] = object;
	}
	else {
		// increase the size of StackArr by creating new,copy; and add new element
		int* newdata_ = new int[size_ * 2];
		for (int i = 0; i < size_*2; i++) {
			if (i < size_) {
				*(newdata_ + i) = *(data_ + i);
			}
			else {
				*(newdata_ + i) = 0;
			}
		}
		delete[] data_;
		data_ = newdata_;
		size_ *= 2;
		head_ += 1;
		data_[head_] = object;
	}
}

void StackArr::Pop() {
	if (head_ == -1) {
		throw std::logic_error("Массив пустой!");
	}
	else {
		data_[head_] = 0;
		head_ -= 1;
	}
}
