#include <iostream>
#include <tuple>
using namespace std;

class A
{
	public :
		A()
		{
			cout<<"@ A class constructor \n";
		}

		A(A & ref)
		{
			cout<<"@ A class copy constructor\n";
		}

		friend ostream & operator << (ostream & ref, A & reff)
		{
			ref << "This is a A class object \n";
			return ref;
		}

		~A()
		{
			cout<<"@ A class destructor \n";
		}
};

int main()
{
	A obj;
	tuple <int, char, string, A, float, double> some_tuple = {1,'a', "asdas", obj, 123.2f, 23.2332};

	cout<<"To get use get<type>() in tuple \n";
	cout<<" int = " << get<int>(some_tuple) <<std::endl;
	cout<<" char = " << get<char>(some_tuple) <<std::endl;
	cout<<" string = " << get<string>(some_tuple) <<std::endl;
	cout<<" A class = " << get<A>(some_tuple) <<std::endl;
	cout<<" float = " << get<float>(some_tuple) <<std::endl;
	cout<<" double = " << get<double>(some_tuple) <<std::endl;
}