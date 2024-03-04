// PROBLEMS:
// Complex decl SOLVED (add target_link_libraries)
// Pop (how to pop)
// sort (PR)

#include <iostream>
#include "prj.lab/complex/complex.hpp"

class QueueLstPr {
public:
	QueueLstPr() = default;
	~QueueLstPr() = default;
	QueueLstPr(const QueueLstPr&) = default;

	Complex Top();
	void Push(Complex& rhs);
	void Pop();
	bool isEmpty();

private:
	struct Node {
		Node* next = nullptr; // NEXT TO EST SLEDUUSHIY VO VREMENI
		Complex value;
	};
	Node* head_ = nullptr;
	Node* tail_ = nullptr;
};

int main()
{
	QueueLstPr a;
	Complex b(14,2);
	a.Push(b);
	std::cout << a.Top() << "\n";
	b = 2;
	a.Push(b);
	std::cout << a.Top() << "\n";
	a.Pop();
	std::cout << a.Top() << "\n";
}

Complex QueueLstPr::Top() 
{
	return head_->value;
}


void QueueLstPr::Push(Complex& rhs) 
{
	Node* newnode = new Node;
	if (head_ == nullptr) {
		newnode->value = rhs;
		tail_ = newnode;
		head_ = newnode;
	}
	else {
		newnode->value = rhs;
		tail_->next = newnode;
		tail_ = newnode;
	}
}

void QueueLstPr::Pop()
{
	Node* tmp = head_->next;
	delete head_;
	head_ = tmp;
}