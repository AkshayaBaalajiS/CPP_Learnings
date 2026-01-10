#include <iostream>
using namespace std;

class Sample
{
	public :
		Sample()
		{
			cout<<"@ Sample class constructor \n";
		}

		virtual void function() final 
		{
			cout<<"@ virtual void function() final \n";
		}

		~Sample()
		{
			cout<<"@ Sample class destructor \n";
		}
};

class Sample1 : Sample
{
	public :
		Sample1()
		{
			cout<<"@ Sample1 class constructor \n";
		}

		// virtual function ‘virtual void Sample1::function()’ overriding final function
		// void function() override 
		// {
		// 	cout<<"@ virtual void function() final \n";
		// }

		~Sample1()
		{
			cout<<"@ Sample1 class destructor \n";
		}
};


int main()
{
	cout<<"@ final usage in cpp and working \n";

	Sample obj;
	obj.function();

}