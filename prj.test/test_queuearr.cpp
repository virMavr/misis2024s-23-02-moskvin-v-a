#include "queuearr/queuearr.hpp"

int main() 
{
	using namespace std;
	QueueArr q;
	q.Push(7);
	q.Push(8);
	q.Push(9);
	q.Push(12);
	q.Push(100);
	q.Push(0);
	q.Push(11);
	q.Push(39);
	q.Push(75);
	
	for (int i = 0; i < 7; i++) {
		q.Pop();
	}

	cout << q.Top();
	
}