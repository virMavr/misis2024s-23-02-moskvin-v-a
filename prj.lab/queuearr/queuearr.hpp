

class QueueArr
{
public:
	QueueArr() = default;
	~QueueArr() = default;
	QueueArr(const QueueArr&) = default;

	bool isEmpty();
	int Top();
	void Push(const int& object);
	void Pop();

private:
	int size_ = 0;
	int* data_ = nullptr;
	int head_ = -1;
	int tail_ = -1;
};