#include <iostream>
using namespace std;

void func(int &)
{
	cout<<"@ void func(int & )\n";
}
void func(int &&)
{
	cout<<"@ void func(int && )\n";
}

void func(int a, int b, int & c, int & d)
{
	cout<<"@ void func(int, int , int &, int &)\n";
}

template <typename... T>
void functionTakeInfArg(T&&... ref)
{
	func(std::forward<T>(ref)...);
}

template <typename TT, typename... T>
void functionTakeInfArg1(T&&... ref)
{
	func(std::forward<T>(ref)...);
}


int main()
{
	cout<<"This is the function for the std_forward leartning \n";
	int vari =234;
	float varf =23.324f ; 
	string vars = "234234.345345f";

	functionTakeInfArg(12);
	functionTakeInfArg(vari);
	functionTakeInfArg1<int>(12,234,vari,vari);

}