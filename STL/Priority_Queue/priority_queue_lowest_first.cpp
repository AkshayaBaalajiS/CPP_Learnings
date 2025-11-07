#include <iostream>
#include <queue>
using namespace std;

int main()
{

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