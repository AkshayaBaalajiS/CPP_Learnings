#include <iostream>
using namespace std;

auto function_return_square(auto var)
{
	return var * var ;
}

decltype(auto) increase(int& a)
{
    a++;
    return a;
}

int main()
{
	int number = 5;
	int result = function_return_square(number);
	cout<<"Number  = " << number << " result = " << result << endl;

	int && ref = 55;
	int && result_ref = function_return_square(ref); 
	cout<<"ref = " << ref << " result_ref = " << result_ref << endl;

	// for the below it will throw error 
	// cause it will consider ref_1 as int and it will return int but the expec is int & 
	/*int & ref_1 = number;
	int & result_ref_1 = function_return_square(ref_1);
	cout<<"ref = " << ref << " result_ref = " << result_ref_1 << endl;
	*/

	int & ref_1 = number;
	int & result_ref_1 = increase(ref_1);
	cout<<"ref_1 = " << ref_1 << " result_ref_1 = " << result_ref_1 << endl;
	
}