#ifndef QUEUELST_LIBRARY
#define QUEUELST_LIBRARY

class QueueLst 
{
public:

	QueueLst() = default;
	~QueueLst() = default;
	QueueLst(const QueueLst&) = default;
	QueueLst& operator=(const QueueLst&) = default;

	[[nodiscard]] bool isEmpty() const noexcept;
	void Pop();
	void Push();
	[[nodiscard]] int Top();

private:
	struct Node {
		int value;
		Node* next 
	};

	Node* head_ = nullptr;
	Node* tail_ = nullptr;
};

#endif