#include <iostream>
#include <variant>
using namespace std;

class A 
{
	public :
		A()
		{
			cout<<"A class constructor \n";
		}
		friend ostream & operator << (ostream & out , A & aout)
		{
			out<<"This is the A class object printed ";
			return out;
		}
		~A()
		{
			cout<<"A class destructor \n";
		}
};

int main()
{
	std::variant<int, float, double, A, string, char * > variant_var;
	variant_var = 123;
	variant_var = 345.234f;
	variant_var = 345.234;
	variant_var = *(new A());
	// variant_var = "Akshaya Baalaji S ";

	if(holds_alternative<int>(variant_var))
	{
		cout<<"Variant hold int Value = " << get<int>(variant_var) << endl;
	}
	if(holds_alternative<string>(variant_var))
	{
		cout<<"Variant hold string Value = " << get<string>(variant_var) << endl;
	}
	if(holds_alternative<A>(variant_var))
	{
		cout<<"Variant hold A Value = " << get<A>(variant_var) << endl;
	}
	if(holds_alternative<char *>(variant_var))
	{
		cout<<"Variant hold char * Value = " << get<char *>(variant_var) << endl;
	}
	if(holds_alternative<float>(variant_var))
	{
		cout<<"Variant hold float Value = " << get<float>(variant_var) << endl;
	}
	if(holds_alternative<double>(variant_var))
	{
		cout<<"Variant hold double Value = " << get<double>(variant_var) << endl;
	}
}