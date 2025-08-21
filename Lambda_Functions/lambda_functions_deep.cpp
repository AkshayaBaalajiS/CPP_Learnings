#include <iostream>
#include <functional>
using namespace std;


int global_variable ;

int main()
{
	int local_variable =34;
	int local_variable_1 = 23;
	int local_variable_2 ;

	/* If we are not giving the & / = in [] we will get error as "is not captured"
	auto change_values_lambda_function = [] ()
	{
		global_variable=23;
		local_variable=545;
		local_variable_1 = 456;
		local_variable_2=567;
	}*/

	// now we are passing it as reference 
	auto change_values_lambda_function_with_reference = [&] ()
	{
		global_variable=23;
		local_variable=545;
		local_variable_1 = 456;
		local_variable_2=567;
	};

	cout<<"Before lambda function with reference passed call \n";
	cout<<"Global variable = " << global_variable<<endl;
	cout<<"local variable 0 = " << local_variable<<endl;
	cout<<"local variable 1 = " << local_variable_1<<endl;
	cout<<"local variable 2 = " << local_variable_2<<endl;
	cout<<"-------------------------------------------\n";
	change_values_lambda_function_with_reference();
	cout<<"After function call \n";
	cout<<"Global variable = " << global_variable<<endl;
	cout<<"local variable 0 = " << local_variable<<endl;
	cout<<"local variable 1 = " << local_variable_1<<endl;
	cout<<"local variable 2 = " << local_variable_2<<endl;
	cout<<"-------------------------------------------\n";

	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	// while using = in the capture clause local variables in code are read only in this scope and only global variables can be changed 
	auto change_values_lambda_function_with_value = [=] ()
	{
		global_variable=67;
		// local_variable=987;
		// local_variable_1 = 786;
		// local_variable_2=976;
	};

	cout<<"Before lambda function with value passed call  \n";
	cout<<"Global variable = " << global_variable<<endl;
	cout<<"local variable 0 = " << local_variable<<endl;
	cout<<"local variable 1 = " << local_variable_1<<endl;
	cout<<"local variable 2 = " << local_variable_2<<endl;
	cout<<"-------------------------------------------\n";
	change_values_lambda_function_with_value();
	cout<<"After function call \n";
	cout<<"Global variable = " << global_variable<<endl;
	cout<<"local variable 0 = " << local_variable<<endl;
	cout<<"local variable 1 = " << local_variable_1<<endl;
	cout<<"local variable 2 = " << local_variable_2<<endl;
	cout<<"-------------------------------------------\n";

	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	// while using = in the capture clause local variables in code are read only but we are using mutable to overcome this 
	auto change_values_lambda_function_with_value_with_mutable = [=] () mutable
	{
		global_variable=67;
		local_variable=987;
		local_variable_1 = 786;
		local_variable_2=976;
	};

	cout<<"Before lambda function with value passed and funciton declared with mutable on it  \n";
	cout<<"Global variable = " << global_variable<<endl;
	cout<<"local variable 0 = " << local_variable<<endl;
	cout<<"local variable 1 = " << local_variable_1<<endl;
	cout<<"local variable 2 = " << local_variable_2<<endl;
	cout<<"-------------------------------------------\n";
	change_values_lambda_function_with_value_with_mutable();
	cout<<"After function call \n";
	cout<<"Global variable = " << global_variable<<endl;
	cout<<"local variable 0 = " << local_variable<<endl;
	cout<<"local variable 1 = " << local_variable_1<<endl;
	cout<<"local variable 2 = " << local_variable_2<<endl;
	cout<<"-------------------------------------------\n";

	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	// while using = in the capture clause local variables in code are read only but we are using & for one variable to overcome this for that variable 
	auto change_values_lambda_function_with_value_with_ref_for_some_var = [=, &local_variable] () 
	{
		global_variable=5678;
		local_variable=7896;
		// local_variable_1 = 786;
		// local_variable_2=976;
	};

	cout<<"Before lambda function with value passed and reference for one variable passed  \n";
	cout<<"Global variable = " << global_variable<<endl;
	cout<<"local variable 0 = " << local_variable<<endl;
	cout<<"local variable 1 = " << local_variable_1<<endl;
	cout<<"local variable 2 = " << local_variable_2<<endl;
	cout<<"-------------------------------------------\n";
	change_values_lambda_function_with_value_with_ref_for_some_var();
	cout<<"After function call \n";
	cout<<"Global variable = " << global_variable<<endl;
	cout<<"local variable 0 = " << local_variable<<endl;
	cout<<"local variable 1 = " << local_variable_1<<endl;
	cout<<"local variable 2 = " << local_variable_2<<endl;
	cout<<"-------------------------------------------\n";

	
}