#include <iostream>
#include "bitset/bitset.hpp"
int main() 
{
	BitSet a(32);

	a.Set(3, 1);
	std::cout << a.Get(4) << " " << a.Get(3) << "\n";
}
