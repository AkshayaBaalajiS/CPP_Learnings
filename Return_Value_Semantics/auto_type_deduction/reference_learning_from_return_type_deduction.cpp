#include <iostream>
#include <cstring>

using namespace std;


// Return type deduction 
auto function (auto variable )
{
	cout<<"auto function (auto variable )\n";
	return variable;
}

// // Return type deduction with reference 
// auto& function1 (auto & variable )
// {
// 	cout<<"auto& function1 (auto & variable )\n";
// 	return variable;
// }

auto&& function2 (auto& variable )
{
	cout<<"auto&& function2 (auto && variable )\n";
	return variable;
}

// Every named variable is an lvalue — even if its type is rvalue reference (T&&).
auto&& function2 (auto&& variable )
{
	cout<<"auto&& function2 (auto && variable )\n";
	return variable;
}


int a =123;
int * ptr = &a;

auto && function2()
{
	return *ptr; // this  is not a T&& cause *ptr -> T& not T&& 
}

auto && function22()
{
	return 34; // this  is not a T&& cause *ptr -> T& not T&& 
}



int main()
{
	cout<<"This is the program to understand the auto in cpp\n";

	int a = 12;
	float b = 12.12f;
	char c = 'a';
	double d = 12.1212121;
	string s = "Hi String";
	char * ptr = "This is the char *";
	float array[] = {1.12f,0.123f, 0.123f, 0.2134f,0.234f};
	float * fptr;

	// return type deduction 
	auto autoFuncRet0 = function(a);
	auto autoFuncRet1 = function(b);
	

	// auto autoFuncRet2 = function1(234.23423f); // this cant be done cause there we are getting as reference 
	auto & autoFuncRet2 = function2(b);   // func2(T &) -> T& && -> T& 
	char charFun1 = function2('A');  // func2(t&& ) -> T&& && -> T && -> T 

	auto && properfunction2 = function2(); // T&& -> T can be converted 
	auto & properfunction1 = function2(); // working cause dereferencing pointer given T&
	cout<<"properfunction1  " <<properfunction1 <<endl; 


	auto & properfunction11 = function22(); // T&& -> T& error will be created 
	/* cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’*/
	cout<<"properfunction11  " <<properfunction11 <<endl; 

	auto autoFuncRet3 = function2('a');
	char charFun2 = function2('a');

}