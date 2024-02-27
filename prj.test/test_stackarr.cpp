#include "stackarr/stackarr.hpp"
#include <iostream>


int main()
{
	StackArr a(2);
	a.Push(6);
	a.Push(7);
	std::cout << a.Size() << std::endl;
	a.Push(4);
	std::cout << a.Top() << std::endl;
	std::cout << a.Size() << std::endl;
	a.Pop();
	std::cout << a.Top() << std::endl;
}









