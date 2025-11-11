#include <iostream>

using namespace std;


void func(int a, int b, int c, int d)
{
	cout<<"void ifunc(int a, int b, int c, int d)\n";
}
void func(char a, char b, char c, char d)
{
	cout<<"void cfunc(char a, char b, char c, char d)\n";
}



template <typename T , typename ... TT>
void function (T arg, TT&&... args)
{
	func(arg, args...);
}

int main()
{
	cout<<"variadic template understanding \n";\

	function(12,23,34,45); // 

	function('a','as','sd','we'); // int 

	char a='a';
	char b='b';
	char c='c';
	char d='d';
	function(a,b,c,d); // char 
}