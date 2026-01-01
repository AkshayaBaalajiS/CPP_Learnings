#include <iostream>
using namespace std;

void function1(int , string , float, char , double )
{
	cout<<"@void function1(int , string , float, char , double )\n";
}

template <typename... T>
void function(T&&... args)
{
	function1(args...);
}

int main()
{
	cout<<"Variadic template \n";
	function(123 , (string)("Akshaya Baalaji Senthilraj") , 123.234f, 'a' , 234.23423 );

}