#include <iostream>
#include <optional>
using namespace std;

template <typename T>
optional <T> function(T  arr)
{
	if(arr == nullptr) 
	{
		return std::nullopt;
	}
	return arr;
}

int main()
{
	cout<<"This is the program for understanding the std::optional in C++\n";

	int arri[]={1,2,3,4,5,6};
	float arrf[]={1.123f,1.123f,1.123f,1.123f,1.123f,1.123f};
	int * arr_ai[] ={arri, arri};
	int * arr_i = nullptr;
	int value = 546;
	int * arr_ii = &value ;

	// optional 
	/*optional <auto> -> is not permitted cause auto cannot be used inside template arguments.*/ 
	// function is created to check if the arr is empty return nullopt 
	optional<int *> optionalAuto = function(arri);
	optional<float *> optionalAuto_1 = function(arrf);
	optional<int **> optionalAuto_2 = function(arr_ai);
	optional<int *> optionalAuto_3 = function(arr_i);


	cout<<"-----------------------------------------------\n";
	// checking value is there or not 
	cout<<"optional1 has value = " << optionalAuto.has_value()<<std::endl;
	cout<<"optional2 has value = " << optionalAuto_1.has_value()<<std::endl;
	cout<<"optional3 has value = " << optionalAuto_2.has_value()<<std::endl;
	cout<<"optional4 has value = " << optionalAuto_3.has_value()<<std::endl;
	cout<<"-----------------------------------------------\n";

	cout<<"-----------------------------------------------\n";
	// accessing and printing value
	cout<<"optional1 value = " << optionalAuto.value()<<std::endl;
	cout<<"* optional1 value = " << *(optionalAuto.value())<<std::endl;
	cout<<"optional2 value = " << optionalAuto_1.value()<<std::endl;
	cout<<"* optional2 value = " << *(optionalAuto_1.value())<<std::endl;
	cout<<"optional3 value = " << optionalAuto_2.value()<<std::endl;
	cout<<"* optional3 value = " << *(optionalAuto_2.value())<<std::endl;
	cout<<"** optional3 value = " << **(optionalAuto_2.value())<<std::endl;
	// cout<<"optional4 value = " << optionalAuto_3.value()<<std::endl; // if there is no value on derefering we will get the seg fault as result 
	cout<<"-----------------------------------------------\n";
	

	cout<<"-----------------------------------------------\n";
	// accessing and assigning nullopt if there is no value 
	cout<<"optional1 value_or = " << optionalAuto.value_or(nullptr)<<std::endl;
	cout<<"* optional1 value_or = " << *(optionalAuto.value_or(nullptr))<<std::endl;
	cout<<"optional2 value_or = " << optionalAuto_1.value_or(nullptr)<<std::endl;
	cout<<"* optional2 value_or = " << *(optionalAuto_1.value_or(nullptr))<<std::endl;
	cout<<"optional3 value_or = " << optionalAuto_2.value_or(nullptr)<<std::endl;
	cout<<"* optional3 value_or = " << *(optionalAuto_2.value_or(nullptr))<<std::endl;
	cout<<"** optional3 value_or = " << **(optionalAuto_2.value_or(nullptr))<<std::endl;
	cout<<"optional4 value_or  = " << optionalAuto_3.value_or(nullptr)<<std::endl; // if there is no value / nullopt assigned to it on derefering we will get the seg fault as result 
	// cout<<"optional4 value_or  = " << *(optionalAuto_3.value_or(123))<<std::endl; // here you are giving 123 (int) as value instead of  int * so give int * or nullptr as value 
	// cout<<"optional4 value_or  = " << *(optionalAuto_3.value_or(nullptr))<<std::endl; // this assignment of nullptr is crt but derefring will get seg violation
	cout<<"optional4 value_or  = " << *(optionalAuto_3.value_or(arr_ii))<<std::endl; 
	
}	
 

