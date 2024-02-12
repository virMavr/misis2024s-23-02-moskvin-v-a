#include "dynarr.hpp"

DynArr::DynArr(const ptrdiff_t new_size)
{
	size_ = new_size;
	data_ = new float[size_];
}

void DynArr::Resize(const ptrdiff_t& new_size)
{
	if (new_size <= 0) {
		throw std::logic_error("The size off array can not be 0 or lower");
	}
	else{
		if (new_size > capacity_) {

		}
	}
}

float& DynArr::operator[](const std::ptrdiff_t& index)
{
	if (index < 0 || index >= capacity_) {
		throw std::out_of_range("Out of array range");
	}
	else {
		return data_[index];
	}
}

