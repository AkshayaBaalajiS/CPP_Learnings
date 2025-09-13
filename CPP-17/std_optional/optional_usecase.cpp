#include <iostream>
#include <optional>

using namespace std;

/*
Usecase : without using this function we can assign a value based on the assignment done to the optional
optional <T> function(T  arr)
{
	if(arr == nullptr) 
	{
		return std::nullopt;
	}
	return arr;
}
*/

int main()
{
	cout<<"In this code we are seeing the Optional Usecase in C++\n";
	int array [] = {12,23,34,45,56,76};

	optional <int *> optional_i;
	optional_i.value_or(array);
	/*
	auto function(auto & ref )
	{
		if(ref!=nullptr)
		{
			return ref;
		}
		else{
			return nullopt;
		}
	}
	*/
	cout<<"The value is empty at initial so value_or function is assigning the optional variable to array\n";
	// cout<<"optional_i.value() = " << optional_i.value() <<endl;
	cout<<"optional_i.value_or() = " << optional_i.value_or(array) <<endl;
	cout<<"* optional_i.value_or() = " << *(optional_i.value_or(array)) <<endl;
	// cout<<"* optional_i.value() = " << *(optional_i.value()) <<endl; // vale_or will not assign the value to optional 
}