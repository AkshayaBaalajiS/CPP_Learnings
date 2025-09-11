#include <iostream>
using namespace std;

class A 
{
	public:
		int a;
		float b;
		char c;
		double d;
		string e;
		A() : a(12), b(234.3434f), c('2'), d(34.3434), e("23dsfsdf")
		{

		}
};

struct StructA : A
{
	int aa;
	float bb;
	char cc;
	double dd;
	string ee;

	StructA() : aa(a), bb(b), cc(c), dd(d), ee(e)
	{

	}


};

// class classA : A // this cant be done cause class inherit as private 
class classA : public A
{
	public :
		int aa;
		float bb;
		char cc;
		double dd;
		string ee;

		classA() : aa(a), bb(b), cc(c), dd(d), ee(e)
		{

		}
};


int main()
{
	cout<<"This is the program to understand the class and structure inheritance \n";
	StructA object;
	cout<<"object.A =" << object.aa <<endl;
	cout<<"object.b =" << object.bb <<endl;
	cout<<"object.c =" << object.c <<endl;
	cout<<"object.d =" << object.d <<endl;
	cout<<"object.e =" << object.e <<endl<<endl;

	classA object1;
	cout<<"object1.A =" << object1.aa <<endl;
	cout<<"object1.b =" << object1.bb <<endl;
	cout<<"object1.c =" << object1.c <<endl;
	cout<<"object1.d =" << object1.d <<endl;
	cout<<"object1.e =" << object1.e <<endl;

	
	
}