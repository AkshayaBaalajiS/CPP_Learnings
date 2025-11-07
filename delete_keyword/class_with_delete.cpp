#include <iostream>
using namespace std;

class classA
{
	public:
		classA()
		{
			cout<<"@ classA constructor\n";
		}
		classA(classA & ref) = delete; // delete helps to not use the this function / special function 
		// below error occurs 
		// error: use of deleted function ‘classA::classA(classA&)’
		
};

int main()
{
	cout<<"Program for understanding the class with delete in constructor \n";
	classA object;
	classA object1(object); 
}