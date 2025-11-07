#include<string>
#include <iostream>
using namespace std;

int main()
{
	cout<<"This is the program to understand the use of to_string and static_cast<char>";

	int  a =123;

	string store_1 = to_string(a);
	cout<<"\nA to_string result  = " << store_1<<endl;

	char store_2 = static_cast<char>(a);
	cout<<"A static_cast result = " << store_2 <<endl;
}