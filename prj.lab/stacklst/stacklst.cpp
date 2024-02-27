#include "stacklst.hpp"

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