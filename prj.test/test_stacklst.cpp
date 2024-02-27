#include <iostream>
#include "stacklst/stacklst.hpp"

int main()
{
	StackLst a;
	a.Push(7);
	a.Push(6);
	a.Pop();
	std::cout << a.Top() << "\n";
}
