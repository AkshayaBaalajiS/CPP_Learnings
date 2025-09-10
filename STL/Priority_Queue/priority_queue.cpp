#include <iostream>
#include <queue>
using namespace std;

int main()
{
	cout<<"This is the code to understand the Priority queue in C++\n";
	priority_queue <int> pq ;

	// adding elements 
	pq.push(121);
	pq.push(23);
	pq.push(34);
	pq.push(45);
	pq.push(56);

	// printing // as queue is not having the indexing concept we have to take a copy of queue and we have to top and pop each time 
	// way 1 
	priority_queue<int> pq1 = pq;
	while(!pq1.empty())
	{
		int a = pq1.top();
		pq1.pop();
		cout<<"A = " << a<<endl; 
	}

	// the print is coming in the LIFO order // so this is wrong observation 
	// priority queue is the queue where it list the largest value at first by default 

	cout<<endl;

	// so how to make the lowest to come at first 
	priority_queue<int, vector<int>, greater<int>> pql ;	
	pql.push(121);
	pql.push(23);
	pql.push(34);
	pql.push(45);
	pql.push(56);

	// for indexing this is the improper way as the queue cant be indexed 
	/*
	for(auto i : pql)
	{
		cout<< i <<" " ;
	}
	cout<<endl;
	*/
	// only way for printing a queue is 
	while(!pql.empty())
	{
		int a = pql.top();
		pql.pop();
		cout<<"A = " << a<<endl; 
	}

	
}