#include <iostream>
#include <queue>
using namespace std;

int main()
{
	cout<<"This is the code to understand the Priority queue in C++\n";
	queue <int> pq ;

	// adding elements 
	pq.push(121);
	pq.push(23);
	pq.push(34);
	pq.push(45);
	pq.push(56);

	// printing // as queue is not having the indexing concept we have to take a copy of queue and we have to top and pop each time 
	// way 1 
	queue<int> pq1 = pq;
	while(!pq1.empty())
	{
		int a = pq1.front(); // in queue there is no top there is front 
		pq1.pop();
		cout<<"A = " << a<<endl; 
	}
	// so the queue is not listing the ele based ont he highest value so this is the difference between queue and priority queue 
	/// statck is FILO and queue is FIFO 
}