#include <iostream>
using namespace std;

auto function_return_square(auto var)
{
	return var * var ;
}

// the below function will not work as same as above 
int function_return_square(int var)
{
	return var * var;
}

int main()
{
	int number = 5;
	int result = function_return_square(number);
	cout<<"Number  = " << number << " result = " << result << endl;

	int && ref = 55;
	int && result_ref = function_return_square(ref); 
	cout<<"ref = " << ref << " result_ref = " << result_ref << endl;

	int && ref_1 = 43;
	// int && result_34 = ref_1; // we cant assign directly like this cause left side is rvalue reference and left side is && ref  
	int && result_34 = std::move(ref_1);
	cout<<"ref_1 = " << number << " result_34 = " << result_34 << endl;

}