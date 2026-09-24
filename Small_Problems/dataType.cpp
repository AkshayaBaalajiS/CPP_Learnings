#include <iostream>
using namespace std;

struct A
{
	long a : 8 ;
	char aa ;
	char b ;
	char c ;
	char d ;
	char e ;
	char e1 ;
	char e2 ;
	char e3 ;

};
int main()
{
	int8_t  charData;
	cout<<"Sizeof " << sizeof(charData);
	cout<<"Sizeof " << sizeof(A);
}