#include <iostream>
using namespace std;

class Sample
{
	public :
		Sample()
		{
			cout<<"@ Sample class constructor\n";
			throw std::runtime_error("COnstructor failed ");
		}

		~Sample()
		{
			cout<<"@ Sample class destructor \n";
		}
};
int main()
{
	cout<<"Constructor having the throw for the exception\n";
	try
	{
		Sample obj;
	}
	catch(std::exception & e )
	{
		cout<<"Catch exception \n";
	}
	// destructor not called 
}