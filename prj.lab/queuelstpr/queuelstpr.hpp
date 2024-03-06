// TAIL here is unnecessary
#include <iostream>

class QueueLstPr {
public:
	QueueLstPr() = default;
	~QueueLstPr() = default;
	QueueLstPr(const QueueLstPr&) = default;

	float Top();
	void Push(const float& rhs);
	void Pop();
	bool isEmpty() noexcept;
	void Clear() noexcept;

private:
	struct Node {
		Node* next = nullptr; // NEXT TO EST SLEDUUSHIY VO VREMENI
		float value;
	};
	Node* biggest_ = nullptr;
};