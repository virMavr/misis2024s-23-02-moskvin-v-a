#include "queuearr.hpp"

void QueueArr::Push(const object&) {
	if (tail_ == -1) {
		head_ = tail_ = 0;
	}

	if ((head_ == 0 && tail_ == size - 1) || (tail_ == head_ - 1)) || (head_ == -1)){
		if (size_ = 0) {
			size_ = 2;
		}
		else {
			size_ *= 2;
		}
		int* newdata = new int[size_];
		for (int i = head_; i < size; i++) {

		}
		// ...
	}
	

	tail_ = (tail_ + 1) % size;
	data_[tail_] = object;
}