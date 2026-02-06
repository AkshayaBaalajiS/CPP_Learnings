#include <iostream>
using namespace std;

class Sample
{
public:
	int a=1234;
		Sample()
		{
			cout<<"@Sample class cons\n";
		}
		~Sample()
		{
			cout<<"@Sample class desc\n";
		}
		friend ostream & operator <<(ostream & out, Sample & sam)
		{
			out<<"Object printed " ;
			return out;
		}
};
int main()
{
	cout<<"Reference vs pointers"<<endl;
	int a=23;
	cout<<"A = " << a <<endl;
	cout<<"&A = " << &a <<endl;
	int & b =a ;
	cout<<"B = " << b <<endl;
	cout<<"&B = " << &b <<endl;
	// b = nullptr;// reference cant be null 

	int c = 234;

	cout<<"c = " << c <<endl;
	cout<<"&c = " << &c <<endl;
	b = c;
	cout<<"After b=c ------------\n";
	cout<<"B = " << b <<endl;
	cout<<"&B = " << &b <<endl;
	cout<<"A = " << a <<endl;
	cout<<"&A = " << &a <<endl;
	cout<<"---------------\n";

	int * ptr = &a;
	cout<<"ptr = " << ptr <<endl;
	cout<<"*ptr = " << *ptr <<endl;
	cout<<"&ptr = " << &ptr <<endl;
	ptr = nullptr; 

	Sample obj;

	cout<<"obj = " << obj <<endl;
	cout<<"&obj = " << &obj <<endl;
	Sample * ptt = &obj ;
	ptt = nullptr; // can be null 


	// Sample & samref = *ptt;
	Sample & samref = *	ptt;
	cout<<"samref = " << samref <<endl;
	cout<<"samref.a = " << samref.a <<endl;
	cout<<"&samref = " << &samref <<endl;
	// ptr = nullptr; 
}