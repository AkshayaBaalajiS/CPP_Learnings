#include <iostream>
using namespace std;


#define ASSERT(condition, message) \
if(condition) \
{ \
	cerr<<"ASSERT : "<<message<<endl; \
	exit(1); \
}
 
 //  \ is a line continuation charecter 

int main()
{
	int size=234;
	ASSERT(size>5 , "The size is lesser than 5 ");

	size=3;
	ASSERT(size>5 , "The size is lesser than 5 ");

}