#include <iostream>
using namespace std;

int main()
{
	cout<<"This is the code to understand the const correctness\n";
	int number  = 234;

	const int * ptr = new int(123);
	int * const  ptr1 = new int(567);

	cout<<"-------------------------\n";
	cout<<"*ptr = "<<*ptr<<endl;
	cout<<"*ptr1 = "<<*ptr1<<endl;
	cout<<"-------------------------\n";


	cout<<"-------------------------\n";
	ptr = &number;
	cout<<"*ptr = "<<*ptr<<endl;
	cout<<"*ptr1 = "<<*ptr1<<endl;
	cout<<"-------------------------\n";


	cout<<"-------------------------\n";
	*ptr1 = number;
	cout<<"*ptr = "<<*ptr<<endl;
	cout<<"*ptr1 = "<<*ptr1<<endl;
	cout<<"-------------------------\n";

}