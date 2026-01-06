#include <iostream>
using namespace std;

class A
{
	public :
		A()
		{
			cout<<"@ A class constructor \n";
		}

		virtual void type()
		{
			cout<<"A class type function\n";
		}

		~A()
		{
			cout<<"@ A class destructor \n";
		}
};

class B : public A 
{
	public :
		B()
		{
			cout<<"@ B class constructor \n";
		}

		void type() override
		{
			cout<<"B class type function\n";
		}

		~B()
		{
			cout<<"@ B class destructor \n";
		}
};

int main()
{
	cout<<"RTTI in cpp in realtime \n";

	cout<<"---------------\n";
	A * ptr = new B(); // upcasting 
	ptr->type();
	cout<<"Type of ptr -> " << typeid(ptr).name() <<endl;
	cout<<"Type of ptr -> " << typeid(*ptr).name() <<endl;
 	cout<<"---------------\n";

	cout<<"---------------\n";
	A * aptr = new A();
	aptr->type();
	cout<<"Type of aptr -> " << typeid(aptr).name() <<endl;
	cout<<"Type of aptr -> " << typeid(*aptr).name() <<endl;
	cout<<"---------------\n";

	cout<<"---------------\n";
	B * bptr = new B();
	bptr->type();
	cout<<"Type of bptr -> " << typeid(bptr).name() <<endl;
	cout<<"Type of bptr -> " << typeid(*bptr).name() <<endl;
	cout<<"---------------\n";

	cout<<"---------------\n";
	// B * baptr = dynamic_cast<B *>(new A());
	// B * baptr = dynamic_cast<B *>(aptr);
	B * baptr = dynamic_cast<B *>(ptr); // ptr is A ptr which is assigned with B // Runtime object is B
	baptr->type();
	cout<<"Type of baptr -> " << typeid(baptr).name() <<endl;
	cout<<"Type of baptr -> " << typeid(*baptr).name() <<endl;
	cout<<"---------------\n";
}