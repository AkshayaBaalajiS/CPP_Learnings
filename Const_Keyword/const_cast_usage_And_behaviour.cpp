#include <iostream>
using namespace std;

int main()
{
	cout<<"This the code to udnerstand the auto variable on const passed it will not take the const \n";
	const int someVar = 324;
	const int * cptr = &someVar;

	int * iptr = const_cast<int *>(cptr);
	*iptr = 234;
	cout<<"SomeVar = " << someVar <<endl;
	cout<<"*cptr = " << *cptr <<endl;
	cout<<"cptr = " << cptr <<endl;
	cout<<"iptr = " << iptr <<endl;
	cout<<"*iptr = " << *iptr <<endl;
}

/*
C++ standard says:

If you modify a const object through a non-const pointer → undefined behavior.
*/