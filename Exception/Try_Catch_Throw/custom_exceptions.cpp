#include <iostream>
using namespace std;

class Exceptions
{
	public :
		Exceptions()
		{
			cout<<"Exceptions class default constructor called \n";
		}

		~Exceptions()
		{
			cout<<"Exceptions class destructor called \n";
		}

		friend ostream & operator << (ostream & ref, Exceptions & obj)
		{
			ref << "Exceptions class instance ";
			return ref;
		}
};

int main()
{
	cout<<"Custom class Exceptions\n";
	try
	{
		Exceptions object;
		throw(object);
	}
	catch(Exceptions & ref)
	{
		cout<<"The error is  : " << ref << " caught\n";
	}
}