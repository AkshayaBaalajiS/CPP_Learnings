#include <iostream>
using namespace std;
constexpr int function(int a, int b, int &c )
{
	c = a + b;
	return c ;
}
int main()
{
	cout<<"This is the program to understand the cosntexpr in the function\n";

	int a =12;
	int b= 12;
	int c=0;
	cout<<"Before compute = " << c<<endl;
	function(a,b,c);
	cout<<"After compute =  " << c<<endl;
	int * ptr = &a;
	function(*ptr,b,c);
}