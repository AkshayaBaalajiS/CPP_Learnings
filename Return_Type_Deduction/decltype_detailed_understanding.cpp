#include <iostream>
using namespace std;

template <typename T>
decltype(auto) function (T arg)
{
	cout<<"@decltype(T) function (T arg)\n";
	return arg;
}

/*

❌ Why this is wrong

decltype does not work on types.
It works on expressions.

🔴 T is a type, not an expression.

So:

decltype(T)   // ❌ INVALID

What decltype actually expects
decltype(expression)


Examples:

decltype(x)        // OK (x is an expression)
decltype(x + y)    // OK
decltype((x))      // OK (important!)


But:

decltype(int)      // ❌ INVALID
decltype(T)        // ❌ INVALID (T is a type)

Why decltype(auto) works
Example
template <typename T>
decltype(auto) function(T arg)
{
    return arg;
}

Why this works ✅

decltype(auto):

Tells the compiler:

“Deduce the return type using decltype rules on the return expression”

Here, the return expression is:

arg


So the compiler effectively does:

decltype(arg)


Which is valid, because arg is an expression.

*/

int main()
{
	function(123);
}


/*
use of decltype 
see the diff below 

auto type deduction (template-like)

auto uses rules similar to template type deduction.

Example
int x = 10;
int& rx = x;
const int cx = 20;

auto a = x;    // int
auto b = rx;   // int      (reference removed)
auto c = cx;   // int      (const removed)


compare the above and below one 

decltype(auto) type deduction (expression-based)

decltype(auto) uses decltype(expression) rules on the initializer or return expression.

Example
int x = 10;
int& rx = x;

decltype(auto) a = x;     // int
decltype(auto) b = (x);   // int&  ← note parentheses!
decltype(auto) c = rx;    // int&

*/