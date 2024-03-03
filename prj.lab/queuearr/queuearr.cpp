#include "queuearr.hpp"

QueueArr::QueueArr(const int& s) {
	if (s < 0) {
		throw std::logic_error("The size of queue can't be negative.");
	}
	data_ = new int[s];
	size_ = s;
}

QueueArr::~QueueArr() {
	while (!isEmpty()) {
		Pop();
	}
}
bool QueueArr::isEmpty() {
	if (head_ == -1) {
		return true;
	}
	return false;
}

int QueueArr::Top() {
	if (head_ == -1) {
		throw std::logic_error("Queue is empty");
	}
	return data_[head_];
}

void QueueArr::Push(const int& object) {
	// if you don't have enough size and size == 0
	if (size_ == 0) {
		data_ = new int[2];
		size_ = 2;
	}

	// if you q isEmpty
	if (isEmpty()) {
		head_ = 0;
	}

	// if you don't have enough size and size > 0
	if ((head_ == 0 && tail_ == size_ - 1) || (tail_ == head_ - 1 && tail_ != -1)){
		int* newdata = new int[size_*2];
		for (int i = 0; i < size_; i++) {
			*(newdata + i) = data_[(i + head_) % size_];
		}
		delete[] data_;
		data_ = newdata;
		head_ = 0;
		tail_ = size_ - 1;
		size_ *= 2;
	}
	
	tail_ = (tail_ + 1) % size_;
	data_[tail_] = object;
}

void QueueArr::Pop() noexcept {
	// if one number in q
	if (head_ == tail_) {
		head_ = -1;
		tail_ = -1;
		delete[] data_;
		size_ = 0;
	}
	// in any other situations
	else {
		head_ = (head_ + 1) % size_;
		if (head_ == size_) {
			head_ = 0;
		}
	}
}