#include "stack/stack.hpp"
#include <iostream>


int main()
{
	Stack a(1);
	a.Push(6);
	a.Push(7);
	a.Push(8);
	std::cout << a.Top() << std::endl;
}









