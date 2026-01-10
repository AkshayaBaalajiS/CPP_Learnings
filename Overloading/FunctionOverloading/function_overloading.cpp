#include <iostream>
using namespace std;

class A
{
	public :
		A()
		{
			cout<<"@ A class constructor \n";
		}

		virtual void pureVirFunc() =0;

		virtual void virFunc();

		virtual void virFunc1() final 
		{
			cout<<"A class virFunc1\n";
		}

		~A()
		{
			cout<<"@ A class destructor \n";
		}
};

void A::virFunc()
{

}

class B : public A
{
	public :
		B()
		{
			cout<<"@ B class constructor \n";
		}

		void pureVirFunc() override
		{
			cout<<"@ B class pureVirFunc \n";
		}

		void virFunc () override
		{

		} 

		// final function cant be override 
		// void virFunc1() override
		// {

		// }

		~B()
		{
			cout<<"@ B class destructor \n";
		}
};

int main()
{
	cout<<"Function overloading in cpp \n";
	// A obj;
	A * ptr = new B();
	ptr->pureVirFunc();
}