#include "queuelstpr.hpp"

float QueueLstPr::Top()
{
	if (isEmpty()) {
		throw std::logic_error("The queue is empty");
	}
	return biggest_->value;
}

bool QueueLstPr::isEmpty() noexcept {
	if (biggest_ == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

//my best children at 06.03.2024
void QueueLstPr::Push(const float& rhs)
{
	Node* newnode = new Node;
	newnode->value = rhs;

	// if add first Node
	if (biggest_ == nullptr) {
		biggest_ = newnode;
		return;
	}
	// if RHS is BIGGEST
	else if (rhs > biggest_->value) {
		newnode->next = biggest_;
		biggest_ = newnode;
		return;
	}
	// other situations
	Node* tmp = biggest_;
	Node* previous_tmp;
	bool latest = 0;
	while (rhs <= tmp->value) {
		if (tmp->next == nullptr) {
			latest = 1;
			break;
		}
		previous_tmp = tmp;
		tmp = tmp->next;
	}
	// if RHS is LATEST
	if (latest) {
		tmp->next = newnode;
		return;
	}
	// if RHS between 2
	newnode->next = previous_tmp->next;
	previous_tmp->next = newnode;
}

void QueueLstPr::Pop()
{
	Node* tmp = biggest_->next;
	delete biggest_;
	biggest_ = tmp;
}

void QueueLstPr::Clear() noexcept {
	while (!isEmpty()) {
		Pop();
	}
}