#include <iostream>
using namespace std;

void f(int args)
{
	cout<<"@void f(int args)\n";
}

void Function(int && args)
{
	f(args);
}

/*
void ff(int);   // parameter is passed by value
void ff(int&);  // reference is just an alias
After type adjustment, both become:

cpp
Copy code
void ff(int);


void ff(int args)
{
	cout<<"@void f(int args)\n";
}
*/

void ff(int & args)
{
	cout<<"@void ff(int &args)\n";
}

void ff(int && args)
{
	cout<<"@void ff(int && args)\n";
}

template <typename T>
void ForwardFunction(T && args)
{
	ff(std::forward<T>(args));
}

template <typename T>
void ForwardFunction1(T & args)
{
	ff(std::forward<T>(args));
	// ff(std::forward<int>(args));
}
/*

T&& in a template is a forwarding (universal) reference.
int&& is a pure rvalue reference.

3️⃣ How forwarding reference works (step-by-step)
🔹 Call with rvalue
ForwardFunction(12);


T deduced as int

Parameter becomes:

int&& args;


✔ OK

🔹 Call with lvalue
int number = 123;
ForwardFunction(number);


T deduced as int&

Parameter becomes:

int& && args;

🧠 Reference collapsing rule:
int& &&  →  int&

Combination	Result
& &	    &
& &&	&
&& &	&
&& &&	&&

int&&
👉 “I accept only temporaries”

T&&
👉 “I accept whatever you give me, and I’ll remember what it was”
*/


int main()
{
	cout<<"This is the program to understand the forward concept in cpp \n";
	int number=123;

	Function(12);
	// Function(number);

	ForwardFunction(12);
	ForwardFunction(number);

	ForwardFunction1(number);

}	