#include <iostream>
using namespace std;

int main()
{
	cout<<"This is the simple print stmt \n";

	cout.put('a');

	int a =2134;

	cout<<"\nPrint through the cout \n";
	cout.put('a');	

	cout.flush(); // for flushing the stream 

	cout.write("\nThis is the simple print stmt ", 32); 
}