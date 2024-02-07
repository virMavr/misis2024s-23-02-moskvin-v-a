#include <iostream>

class DynArr {
public:
	DynArr() = default;
	DynArr(const ptrdiff_t new_size);
	~DynArr() = default;
	DynArr(const DynArr&);


	ptrdiff_t Size() const
	{
		return size_;
	}
	void Resize(const ptrdiff_t new_size)
	{
		size_ = new_size;
	}
	float& operator[](const ptrdiff_t S)
	{
		return data_[S];
	}
private:
	ptrdiff_t size_ = 0;
	//T* data_ = nullptr;
	float* data_ = nullptr;
};