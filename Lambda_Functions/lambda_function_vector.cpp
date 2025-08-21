#include <iostream>
#include <functional>

using namespace std;

void function_to_print(vector<int> & ref )
{
	cout<<"Size  = " << ref.size() << endl; 

	for(int i : ref )
	{
		cout<<" i  = " << i << endl;
	}
	cout<<endl;
}

int main()
{
	cout<<"This is lambda function in arg of vector \n";

	vector<int> vec_int = {1,2,3,4,5};

	function_to_print(vec_int);

	auto lambda_function = [=]() mutable 
	{
		vec_int.push_back(12);
	};
	/*

🔍 What [=] Does:
[=] means: capture all used outer variables by value (i.e., copy them into the lambda).

mutable allows modifying those copies inside the lambda.

BUT: It does not affect the original vec_int declared in main().
	*/

	cout<<" _____________________________________ \n";
	
	function_to_print(vec_int);

	cout<<" _____________________________________ \n";

	lambda_function();

	cout<<" _____________________________________ \n";
	
	function_to_print(vec_int);

	cout<<" _____________________________________ \n";

}