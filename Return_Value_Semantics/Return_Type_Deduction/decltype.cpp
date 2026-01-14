#include <iostream>
using namespace std;

template <typename T>
decltype(auto) function(T&& args )
{
	return std::forward<T>(args);
}

int main()
{
	cout<<"Return type deduction in the code \n";
	function(234);

	int a=234;
	function(a);

}