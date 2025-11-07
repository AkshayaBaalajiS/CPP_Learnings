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
	cout<<"This is the program to understand the std variant in C++ \n";
	variant<int, double, char, classA, structB, tuple<int, float>> variantVar ;
	variant<int, double, char, classA, structB, tuple<int, float>> variantVar_1 ;

	// assign any value to variant 
	variantVar = 56;
	// we are seeting the varient will only int and printing it 
	findTypeAndPrint(variantVar);

	// we are passing the float value now
	variantVar = 14.34f; // we have not declared float as a type in variant but the float is typecasted to double there 
	findTypeAndPrint(variantVar);

	// we are passing the double value now
	variantVar = 34.343245345534d; 
	findTypeAndPrint(variantVar);

	// we are passing the char value now
	variantVar = 's'; 
	findTypeAndPrint(variantVar);
	
	// we are passing the string value now // but the declaration of variant is not there with string 
	// variantVar = "akshaya baalaji S"; // here we are getting error cause the varient with string type is not declared 
	// findTypeAndPrint(variantVar);
	
	int a=32;
	float b=4;
	tuple<char, float> var= make_tuple<char,float>('a',234.23423f); 
	tuple<int, float> var_1= make_tuple(a,b); 
	// try giving the tuple for varient 
	// the above error will come here I guess 
	// variantVar = var; // error araises 
	variant<int, double, tuple<int, float>, char, classA, structB > variantVar_11 ;
	variant<int, double, tuple<int, float>, char, classA, structB > variantVar_2 ;
	variantVar_11 = var_1;
	
	// findTypeAndPrint(variantVar_11); // type mismatch occurs 
	/*
	invalid initialization of reference of type ‘std::variant<int, double, char, classA, structB, std::tuple<int, float> >&’ from expression of type ‘std::variant<int, double, std::tuple<int, float>, char, classA, structB>’
	*/
	// trying copy of one variant to another 
	// variantVar = variantVar_11; // error arraises 
	// trying the same with same type
	variantVar_1 = variantVar; // this works
	findTypeAndPrint(variantVar_1);
	variantVar_1 = *(new classA());
	// checking whether the variant copied affect the original 
	findTypeAndPrint(variantVar_1);
	variantVar = var_1;
	findTypeAndPrint(variantVar);
	
	// CHECKING IT IS DOING A SHALLOW OR DEEP COPY 
	variantVar = *(new structB(34,4546.345345f));
	findTypeAndPrint(variantVar);

	variantVar_1 = variantVar;
	// changing the value of member 
	get<structB>(variantVar).a=89890;
	get<structB>(variantVar).b=23423.3489890;
	findTypeAndPrint(variantVar_1);
	findTypeAndPrint(variantVar);
	// so this is doing a deep copy 
	
}