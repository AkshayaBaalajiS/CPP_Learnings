#include <iostream>
using namespace std;

#define ASSERT(expr, str) \
	if(!expr) { \
		cout<<str<<endl; \
		exit(0); \
	}


int main()
{
	cout<<"Custom Assert in cpp\n";
	// ASSERT(true, "Assert trigerred in code by setting the on to true");
	ASSERT(false, "Assert trigerred in code by setting the on to false");
	
}