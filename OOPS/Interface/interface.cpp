#include <iostream>
using namespace std;

class Interface
{
	public:
		Interface()
		{
			cout<<"@ Interface class constructor\n";
		}

		virtual void print() = 0;
		virtual void func() = 0;
		virtual void function1() = 0;
		
		virtual ~Interface()
		{
			cout<<"@ Interface class destructor\n";
		}
};

int main()
{
	cout<<"This is the code to understand the interface in cpp \n";

}