#include <iostream>
#include <optional>

using namespace std;

struct A 
{
	A()
	{
		cout<<"A class constructor \n";
	}
	~A()
	{
		cout<<"A class destructor \n";
	}
};

// template<typename T>
// optional<T> function(T&& args )
/*
✅ You passed a pointer (A*) — so how did it become A*& ?

Because of universal reference (T&&) rules.

This is how template deduction works:

✔️ Case 1: You pass an lvalue
A* ptr = nullptr;  // ptr is an lvalue
function(ptr);


Template:

template<typename T>
optional<T> function(T&& args)


Since args is a universal (forwarding) reference, C++ applies this rule:

If the argument is an lvalue, then T becomes an lvalue reference.

So here:

ptr is an lvalue → so T = A*&


Because you passed an lvalue pointer, not a literal pointer.

Thus:

args type = T&& = (A*&)&&  → collapses to A*&


✔ Final deduced type: T = A&*
❌ But optional<A*&> is ILLEGAL → compilation error
*/
template<typename T>
optional<T> function(T& args )
{
	if(args == nullptr)
	{
		return nullopt;
	}
	static optional<T> opt_var = args;
	// return optional<T>(args);
	return opt_var;
}


int main()
{
	optional<A> opt_var;
	opt_var = *(new A());

	// opt_var = 123; // error cause opt_var will act as the object 
	A * ptr = nullptr  ;

	optional<A *> optional_var = function(ptr);
	
	std::cout<<"Has value = " << optional_var.has_value() <<std::endl;

	A * ptr1 = new A()  ;

	optional<A *> optional_var1 = function(ptr1);
	
	std::cout<<"Has value = " << optional_var1.has_value() <<std::endl;
}