#include <iostream>

int main() {
	int* data_ = nullptr;
	int size_ = 10;

	data_ = new int[size_];
	data_[0] = 1;
	std::cout << data_[1] << std::endl;
}