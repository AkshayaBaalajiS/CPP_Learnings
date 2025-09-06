#include <iostream>
#include <tuple>
using namespace std;

namespace CppClass
{
	class Sample 
	{
		public : 
			int a;
			int b;
			int c;
			Sample() 
			{
				cout<<"@ Sample class constructor \n";
			}
			Sample(int a, int b, int c) : a(a), b(b), c(c) 
			{
				cout<<"@ Sample class parameterized constructor \n";
			}
			

			friend ostream & operator << (ostream & out, CppClass::Sample  ref )
			{
				out << " Printed :  Sample class object \n";
			}

			~Sample()
			{
				cout<<"@ Sample class destructor \n";
			}

			
	};
};

int main()
{
	cout<<"This is the program to understand the tuple functions like get and make_tuple in C++\n";

	CppClass::Sample * samplePtr ;

	CppClass::Sample sampleObj ;
	CppClass::Sample sampleObj_1(23,34,45) ;

	int a;
	float b;
	char c ;
	double d;
	string e;

	cout<<"-----------------------------------------------\n";
	cout<<"Before tie used the variable values are listed below \n";
	cout<< " A = " << a <<endl;
	cout<< " b = " << b <<endl;
	cout<< " c = " << c <<endl;
	cout<< " d = " << d <<endl;
	cout<< " e = " << e <<endl;
	
	cout<<"Object.a " << sampleObj.a <<endl;
	cout<<"Object.b " << sampleObj.b <<endl;
	cout<<"Object.c " << sampleObj.c <<endl;
	cout<<"-----------------------------------------------\n";
	
	tie(a,b,c,d,e, samplePtr, sampleObj) = make_tuple(12,23.32f,'a',434334.34, "Akshaya Baalaji",new CppClass::Sample(), sampleObj_1 );
	cout<<"-----------------------------------------------\n";
	cout<<"After tie used the variable values are listed below \n";
	cout<< " A = " << a <<endl;
	cout<< " b = " << b <<endl;
	cout<< " c = " << c <<endl;
	cout<< " d = " << d <<endl;
	cout<< " e = " << e <<endl;
	
	cout<<"Object.a " << sampleObj.a <<endl;
	cout<<"Object.b " << sampleObj.b <<endl;
	cout<<"Object.c " << sampleObj.c <<endl;

	
	cout<<"Object_1.a " << sampleObj_1.a <<endl;
	cout<<"Object_1.b " << sampleObj_1.b <<endl;
	cout<<"Object_1.c " << sampleObj_1.c <<endl;
	cout<<"-----------------------------------------------\n";


}