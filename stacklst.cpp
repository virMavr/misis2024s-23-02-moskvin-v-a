#include <iostream>

class StackLst {
public:
	StackLst() = default;
	// StackLst(const StackLst&) = default;
	~StackLst() = default;
	// StackLst& operator=(const StackLst&) = default;

	bool isEmpty();
	int Top();
	void Push(const int& object);
	void Pop();
private:
	struct Node
	{
		int value;
		Node* next = nullptr;
	};
	Node* head_ = nullptr;
};

int main() 
{
	StackLst a;
	a.Push(7);
	a.Push(6);
	a.Pop();
	std::cout << a.Top() << "\n";
}






StackLst::~StackLst() {
	while (!isEmpty()) {
		Pop();
	}
}

bool StackLst::isEmpty()
{
	if (head_ = nullptr) {
		return true;
	}
	else {
		return false;
	}
}

int StackLst::Top() {
	return head_->value;
}
void StackLst::Push(const int& object)
{
	/*Node* newnode = new Node;
	newnode->value = object;
	newnode->next = head_;
	head_ = newnode;*/

	head_ = new Node{ object, head_ }; // first { value = object; next = head_; } ,
}

void StackLst::Pop() {
	if (head_ == nullptr) {
		throw std::logic_error("Can not delete element if stack is empty!");
	}
	Node* tmp = head_;
	head_ = head_->next;
	delete tmp;
}