#include "queuelstpr/queuelstpr.hpp"

int main()
{
	QueueLstPr a;
	a.Push(4);
	a.Push(2);
	a.Push(3);
	a.Push(1);
	a.Push(7);
	a.Push(6);
	for (int i = 0; i < 6; i++) {
		std::cout << a.Top() << "\n";
	}
	a.Clear();
	a.Top();
}