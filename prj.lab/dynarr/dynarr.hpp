#include <iostream>

// QUESTIONS:
// what is the difference between size and capacity

class DynArr {
public:
	DynArr() = default;
	DynArr(const ptrdiff_t new_size);
	~DynArr() = default;
	DynArr(const DynArr&) = default;


	std::ptrdiff_t Size() const {	return size_; }
	void Resize(const ptrdiff_t& new_size);
	float& operator[](const std::ptrdiff_t& index);	
private:
	std::ptrdiff_t size_ = 0; // how much elements right now in array
	std::ptrdiff_t capacity_ = 0; // common size of array
	float* data_ = nullptr;
};