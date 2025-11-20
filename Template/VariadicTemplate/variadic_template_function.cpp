#include <iostream>
#include <iomanip>
using namespace std;

void function1(int a, char b, string cd, float c, double d)
{
	cout<<"void function1(int a, char b, string cd, float c, double d)\n";
	cout<<std::fixed << setprecision(6) <<endl;
}

template <typename T, typename... TT>
void function(TT&&... args)
{
	function1(args...);
}

int main()
{
	cout<<"Variadic template discussion \n";
	function<int>(12,'a',"as",234.32423f, 23423.23423);
}