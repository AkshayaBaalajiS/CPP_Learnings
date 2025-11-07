#include <iostream>
#include <optional>

using namespace std;

template <typename T>
optional<T> function(T arr)
{
	if(arr == nullptr)
	{
		return nullopt;
	}
	return arr;
}

int main()
{
	int a = 123;
	float bb =234.2342f;
	double ssd = 56.655656;

	optional<int *> optionalvar = function(&a);
	// 1. working of has_value 
	if (optionalvar.has_value())
	{
		cout<<"variable = " << *(optionalvar.value()) << endl;
	}
	else
	{
		cout<<"No value \n";
	}

	// optionalvar = nullptr ;// nullptr is a lso consider as value 
	optionalvar = function(nullptr) ;
	if (optionalvar.has_value())
	{
		cout<<"variable = " << *(optionalvar.value()) << endl;
	}
	else
	{
		cout<<"No value \n";
	}
	///////////////////////////////////

	//2 . value working 
	optionalvar = nullopt;
	// cout<<"Printing the optional when it has no value : " << *(optionalvar.value()) <<endl; //seg fault 

	optionalvar = &a;
	cout<<"Printing the optional when it has  value : " << *(optionalvar.value()) <<endl;

	// ///////////////////////////

	// //3.  the proof that why we need the function 
	// 	// cause we are having a pointer and it hold null we are not checking it and putting it to optional that makes the error as the optional variable has value and on derefer it is null so seg fawult  
	int * q = nullptr;

	optional<int *> optioanal_1 =q;

	if(optioanal_1.has_value())
	{
		// cout<<"optioanal_1 = " << *(optioanal_1.value()) <<endl; // seg fault 
	}

	optional<int *> optioanal_2 =function(q);

	if(optioanal_2.has_value())
	{
		// cout<<"optional_2 = " << *(optioanal_2.value()) <<endl;
	}
	else
	{
		cout<<"optioanal_2 has no value \n";
	}
	/////////////////////////////

	//4 . value_or understanding 
	int number =12;
	int * number1 = &number;
	optioanal_2 = function(number1);
	int * optionalNumber = optioanal_2.value_or(number1);
	cout<<"It holds = " << *optionalNumber <<endl;

	////////////////////
	int * number2 = nullptr;
	optioanal_2 = function(number2);
	int * optionalNumber1 = optioanal_2.value_or(number1);
	cout<<"It holds = " << *optionalNumber1 <<endl;


}

/*

| optional state    | Expression                 | Return value | Does it change optionalvar? |
| ----------------- | -------------------------- | ------------ | --------------------------- |
| has value (`&a`)  | `optionalvar.value_or(&b)` | `&a`         | ❌ No                        |
| empty (`nullopt`) | `optionalvar.value_or(&b)` | `&b`         | ❌ No                        |

*/