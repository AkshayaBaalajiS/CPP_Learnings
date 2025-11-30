#include <iostream>
using namespace std;

// template< typename T>
//  int operator = (T arg) // operator= cannot be overloaded as a non-member function.
// // explicit int operator = (T arg)
// // explicit cant be applied outside of the class 
// {
// 	return (int)arg;
// }

// int operator int() //  must be a non-static member function
// {
// 	return (int)arg;
// }

class A
{
	public :
		A()
		{
			cout<<"@ A class constructor\n";
		}
		~A()
		{
			cout<<"@ A class destructor\n";
		}

		/*
You are defining:

“A function that converts the object to an int.”

So C++ already knows the return type = int.
		*/
		 operator int ()
		{
			return 1;
		}
};
int main()
{
	cout<<"Explicit understanding \n";
	A obj;
	int a = (int)obj;
	cout<<" a = " << a <<endl;
}