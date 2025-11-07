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
	return *ptr; // this  is not a T&& cause *ptr -> T& not T&&  // this is a proof that return type deduction is not there 
}



// return type deduc of function2 return type did change but the what we are returning is diff 
decltype(auto) function222() // this is T cause 12 is T
{
	return 12;
} 
decltype(auto) function222(float b) // T&&
{
	// return std::move(12); // when returning this on using it or printing it we get seg fault cauuse this is temporary after the func call done the mem is invalid 
	return std::move(a); //here we are returning a global obj of move 
	//You are returning a reference (int&&) to an existing object (a).
	// That object (a) continues to live even after the function returns.
} 
decltype(auto) function222(int b) // T&
{
	return a;
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
	// cout<<"properfunction1  " <<properfunction1 <<endl; 

	// we are commenting 
	// auto & properfunction11 = function22(); // T&& -> T& error will be created +
	/* cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’*/
	// cout<<"properfunction11  " <<properfunction11 <<endl; 


	// REAL return type declaration 
	auto && properfunction222 = function222(); // T&& -> T& error will be created +
	auto && properfunction2221 = function222(1); // T&& -> T& error will be created +
	auto && properfunction2222 = function222(1.0f); // T&& -> T& error will be created +
	/* cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’*/
	cout<<"properfunction222  " <<properfunction222 <<endl; 
	cout<<"properfunction2221  " <<properfunction2221 <<endl; 
	cout<<"properfunction2222  " <<properfunction2222 <<endl; 


	


}


/*
decltype(auto) function222(float b) // T&& { return std::move(12); } auto && properfunction2222 = function222(1.0f); cout<<"properfunction2222 " <<properfunction2222 <<endl;

Expression: std::move(12)
→ Type: int&&

Then:

decltype(auto) uses the exact declared type of the return expression.

So the function’s return type becomes int&&.

✅ That means return type deduction worked perfectly.


Although return type deduction worked correctly (int&&),
what you’re returning is a reference to a temporary that dies immediately after return.

*/