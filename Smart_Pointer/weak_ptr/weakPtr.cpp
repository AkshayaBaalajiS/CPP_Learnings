#include <iostream>
#include <memory>
using namespace std;

class Base
{
	
	public :
		int a ;
		Base(): a(12)
		{
			cout<<"Base class constructor \n";
		}

		~Base()
		{
			cout<<"Base class destructor\n";
		}
};

int main()
{
	cout<<"This is the program to practice the weakPtr in cpp\n";
	Base obj;

	shared_ptr <Base> baseObj = make_shared<Base>();

	weak_ptr<Base> weakBase = baseObj;
	if(!weakBase.expired())
	{
		cout<< (*weakBase.lock()).a <<endl;
	}
	baseObj.reset(); 
	if(!weakBase.expired())
	{
		cout<< (*weakBase.lock()).a <<endl;
	}
	else{
		cout<<"Weak Ptr is expired\n";
	}

}