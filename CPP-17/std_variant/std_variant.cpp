#include <iostream>
#include <optional>
#include <variant>
#include <tuple>
using namespace std;

class A 
{
	public:
		int a;
		char b;
		float c;

		A(int a=23, char c = 'a', float d = 23.2343f) : a(a), b(c), c(d)
		{

		}
		friend ostream & operator << (ostream & ref, A & reff)
		{
			ref << "Object printed ";
		}

};

int main()
{
	cout<<"This is the program to understand the variant in cpp \n";

	variant<tuple<int , A*>, int, A , double> var;
	tuple<int, A *> tuple_var1;// tupleas are mutable 
	int a=2134;
	A * ptr = new A(56,'d',345.3453f);

	tuple<int, A *> tuple_var = make_tuple(a, ptr);
	get<0>(tuple_var) = a+123;
	get<1>(tuple_var) = ptr;

	cout<<"get<0>(tuple_var) = " << get<0>(tuple_var) <<endl;


	get<0>(tuple_var1) = a+123;
	get<1>(tuple_var1) = ptr;
	cout<<"get<0>(tuple_var1) = " << get<0>(tuple_var1) <<endl;

	var = tuple_var1;


	/////////////////////////

	if(holds_alternative<int>(var))
	{
		cout<<"get<int>(var) "<< get<int>(var)<<endl;
	}
	else if (holds_alternative<tuple<int , A*>>(var))
	{
		cout<<"get<tuple<int , A*>>(var) "<< get<int>(get<tuple<int , A*>>(var))<<endl;
		cout<<"get<tuple<int , A*>>(var) "<< *(get<A*>(get<tuple<int , A*>>(var)))<<endl;
	}
	else if (holds_alternative<A>(var))
	{
		cout<<"get<A>(var) "<< get<A>(var)<<endl;
	}
	else if (holds_alternative<double>(var))
	{
		cout<<"get<double>(var) "<< get<double>(var)<<endl;
	}

}
