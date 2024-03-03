#include <iostream>

#ifndef QUEUEARR_LIBRARY
#define QUEUEARR_LIBRARY

class QueueArr
{
public:
	QueueArr() = default;
	QueueArr(const int& s);
	~QueueArr();
	QueueArr(const QueueArr&) = default;

	bool isEmpty();
	[[nodiscard]] int Top();
	void Push(const int& object);
	void Pop() noexcept;

private:
	int size_ = 0;
	int* data_ = nullptr;
	int head_ = -1;
	int tail_ = -1;
};

#endif