#include <iostream>
#include <queue>
using namespace std;

int main()
{
	cout<<"This is the program to see how the priority queue with vector and less compare works \n";
	priority_queue <int, vector<int>, less<int> > pq ;
	// priority_queue <int, vector<int>, greater<int> > pq ; // greater is used for the sorting of the lowest at first 
	
	// so if you give the below at compare it works accordingly 
	// less ->>  high to low 
	// greater ->>  low to high 

	pq.push(12);
	pq.push(11);
	pq.push(12);
	pq.push(132);
	pq.push(121);
	pq.push(120);

	while(!pq.empty())
	{
		int ele  = pq.top();
		pq.pop();
		cout<<ele << "  ";
	}
	cout<<endl;
	
}