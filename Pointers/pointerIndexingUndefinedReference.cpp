#include <iostream>
#include <memory>
using namespace std;

int main()
{
	cout<<"Program to understand the Undefined reference \n";
	
	// this is also a issue with poointers 
	int * ptrrr = new int[5];
	for(int i=0;i<10;i++)
	{
		ptrrr[i] =  345;
		cout<<"ptrrr["<< i <<  "] " << ptrrr[i] << "  ";
	}
	ptrrr[230] =534;
	cout<<endl;
}

/*

}
You allocated 5 ints
You accessed 10 ints

Yet:

no compile error

no runtime error

cause :Because C++ does not check bounds at runtime


Why no error is thrown (important distinction)
❌ Compile-time

The compiler sees this:

int* ptrrr;
ptrrr[i];


This is syntactically valid.

The compiler:

does not know the allocation size

does not track heap bounds

assumes you know what you’re doing

So it cannot warn you.



❌ Runtime

At runtime:

ptrrr[7]


is compiled as:

*(ptrrr + 7)


try compile as below 
g++ -fsanitize=address -g file.cpp
*/

