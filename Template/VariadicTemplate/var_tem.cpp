#include <iostream>
using namespace std;

void functionArg(int a , char b , double d )
{
	cout<<"void functionArg(int a , char b , double d )\n";
}

template <typename T, typename... TT>
void function(TT&&... args )
{
	cout<<"void function(TT&&... args )\n";
	// functionArg(args...); // either this or the below 
	functionArg(std::forward<TT>(args)...); // this is to maintain the l and r value reference 
}

int main()
{
	cout<<"Varaidic template \n";
	function<int>(234,'t',43.23423);
}