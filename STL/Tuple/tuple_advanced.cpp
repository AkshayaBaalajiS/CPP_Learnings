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
				return out;
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

	cout<<"get in tuple _____________________________\n";
	tuple <int,float,char,double,string, CppClass::Sample *, CppClass::Sample, int > tuple_1 = make_tuple(12,23.3453432f,'a',434334.34, "Akshaya Baalaji",new CppClass::Sample(), sampleObj_1, 56 );
	float res_a =  get<float>(tuple_1); // type T in std::get<T> must occur exactly once in the tuple
	cout<<"The float from the tuple is :" << res_a <<endl; 
	printf("float with .6 precision = %.6f\n", res_a);
	// get with type can get the exasct type from the tuple but the tuple should have exasctly one ele of that type 
	auto auto_var_1 = get<0>(tuple_1);
	auto auto_var_2 = get<1>(tuple_1);
	auto auto_var_3 = get<2>(tuple_1);
	auto auto_var_4 = get<3>(tuple_1);
	auto auto_var_5 = get<4>(tuple_1);
	auto auto_var_6 = get<5>(tuple_1);
	auto auto_var_7 = get<6>(tuple_1);
	auto auto_var_8 = get<7>(tuple_1);
	cout<<"get 0 = " << auto_var_1 <<endl;
	cout<<"get 1 = " << auto_var_2 <<endl;
	cout<<"get 2 = " << auto_var_3 <<endl;
	cout<<"get 3 = " << auto_var_4 <<endl;
	cout<<"get 4 = " << auto_var_5 <<endl;
	cout<<"get 5 = " << auto_var_6 <<endl;
	cout<<"*get 5 = " << *auto_var_6 <<endl;
	cout<<"get 6 = " << auto_var_7 <<endl;
	cout<<"get 7 = " << auto_var_8 <<endl;
	
	cout<<"_____________________________\n";

}