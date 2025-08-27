#include <iostream>
using namespace std;

class A 
{
	public:
		A()
		{
			cout<<"A class default constructor \n";
		}
		friend ostream & operator << (ostream & oref,  A & ref );
			
};

ostream & operator << (ostream & oref,  A & ref )
{
	oref << "A class object \n";
	return oref; 
}

int main()
{
	cout<<"Program to learn printing the obj \n";
	A object;

	cout<<object;

}