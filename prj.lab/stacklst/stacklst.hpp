#include <iostream>

#ifndef STACKLST_LIBRARY
#define STACKLST_LIBRARY

class StackLst {
public:
	StackLst() = default;
	// StackLst(const StackLst&) = default;
	~StackLst();
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

#endif