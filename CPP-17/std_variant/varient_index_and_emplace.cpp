#include <iostream>
#include <variant>
#include <iomanip> // for fixedd and precision 
using namespace std;

class classA
{
	public :
		classA()
		{
			cout<<"classA constructor called \n";
		}
		~classA()
		{
			cout<<"classA destructor called \n";
		}
		friend ostream & operator << (ostream & out, classA &ref)
		{
			out<<"@friend ostream & operator << (ostream & out, classA &ref) Object Printed \n ";
			return out;
		}
};

struct structB
{
	int a=78;
	float b= 45.3443f;
	structB(int a, float b) : a(a) , b(b)
	{
		cout<<"structB constructor called \n";
	}
	~structB()
	{
		cout<<"structB destructor called \n";
	}

	friend ostream & operator << (ostream & out, structB &ref)
	{
		out<<"@friend ostream & operator << (ostream & out, structB &ref) Object Printed \n ";
		return out;
	}
};

void findTypeAndPrint(variant<int, double, char, classA, structB, tuple<int, float>> & variantVar)
{
	if(holds_alternative<int>(variantVar))
	{
		cout<<"holds_alternative<int>(variantVar) is true and value = " << get<int>(variantVar)<<std::endl;
	}
	// we are commenting this cause the float type is not declared in variant 
	// else if (holds_alternative<float>(variantVar))
	// {
	// 	cout<<"holds_alternative<float>(variantVar) is true and value = " << get<float>(variantVar)<<std::endl;
	// }
	else if (holds_alternative<double>(variantVar))
	{
		cout<<std::fixed << std::setprecision(20);
		cout<<"holds_alternative<double>(variantVar) is true and value = " << get<double>(variantVar)<<std::endl;
	}
	else if (holds_alternative<char>(variantVar))
	{
		cout<<"holds_alternative<char>(variantVar) is true and value = " << get<char>(variantVar)<<std::endl;
	}
	else if (holds_alternative<classA>(variantVar))
	{
		cout<<"holds_alternative<classA>(variantVar) is true and value = " << get<classA>(variantVar)<<std::endl;
	}
	else if (holds_alternative<structB>(variantVar))
	{
		cout<<"holds_alternative<structB>(variantVar) is true and value = " << (get<structB>(variantVar)).a<<std::endl;
		cout<<"holds_alternative<structB>(variantVar) is true and value = " << (get<structB>(variantVar)).b<<std::endl;
	}
	else if (holds_alternative<tuple<int,float>>(variantVar))
	{
		cout<<"holds_alternative<tuple<int,float>>(variantVar) is true and value = " << get<int>(get<tuple<int,float>>(variantVar))<<std::endl;
		cout<<"holds_alternative<tuple<int,float>>(variantVar) is true and value = " << get<float>(get<tuple<int,float>>(variantVar))<<std::endl;
	}
	else 
	{
		cout<<"Type not found \n";
	}	
}

int main()
{
	cout<<"This is the program to understand the std variant index and emplace in C++ \n";
	variant<int, double, char, classA, structB, tuple<int, float>> variantVar ;
	variant<int, double, char, classA, structB, tuple<int, float>> variantVar_1 ;

	// assign any value to variant 
	variantVar = 56;
	// we are seeting the varient will only int and printing it 
	findTypeAndPrint(variantVar);

	// index we are printing // index here represent the index of type specified in the variant 
	cout<< "The index of int in the variant " <<  variantVar.index() <<endl; // index starts from 0
	
	variantVar = 34534.53453d;
	// checking the index after assigning the variant to double
	cout<< "The index of double in the variant " <<  variantVar.index() <<endl; 

	// emplace working 
	classA obj;
	variantVar.emplace<classA>(obj);
	//checking index 
	cout<< "The index classA in the variant " <<  variantVar.index() <<endl; 

	//check the variant is having the int value or not after emplace
	cout<< "The value of int after emplacing the class to variant " <<  get<int>(variantVar) <<endl;  // we are getting abort here so the value are erased once after assigning it or emplacing it 

}