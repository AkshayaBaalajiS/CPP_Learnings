#include <iostream>
using namespace std;
/*
constexpr cant be used for the function with string as return type  

// constexpr decltype(auto) function_1()
// {
// 	// return 'a' + 'b' ;
// 	return std::string("dfgdfg") ;
// }

constexpr std::string function_1()
{
	return std::string("hello");
}

int main()
{
	cout<<"constexpr in c++\n";
	string result = function_1() ; 

} 
*/

constexpr int function()
{
	return 23;
}

int main()
{
	cout<<"Const expr ad int as return type of function \n";
	constexpr int result = function();
	
}