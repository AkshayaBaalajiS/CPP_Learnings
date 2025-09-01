#include <iostream>
using namespace std;

#define ASSERT(condi, message ) \
if(!(condi)) \
{ \
	cout<<"ASSERT   :  " << message; \
	exit(1); \
}

int main()
{
	cout<<"Assert practice  \n";
	int size =3;
	ASSERT(size>=3, " Size is greater than 3 ");
	size=2;
	ASSERT(size>=3, " Size is less than 3 ");
}