#include<iostream>
#include<typeinfo>
using namespace std ;

template<typename t1 >
t1 template_function(t1 a)
{
	return (a+a);
}


int main()
{
	cout<<"-------------------------------------------------------------\n";
	int a =120;
	cout<<"template_function(a)   : "<< template_function(a) <<"\n";
	cout<<"-------------------------------------------------------------\n";
	float b= 2.344f ;
	cout<<"template_function(b);  : "<< template_function(b) <<"\n";
	cout<<"-------------------------------------------------------------\n";
//	char arr[] = "Akshay" ;
//	template_function(arr);
//	cout<<"template_function(b);  : "<< template_function(b) <<"\n";
	cout<<"-------------------------------------------------------------\n";
	string str ="a";
	
	cout<<"template_function(str); : "<< template_function(str)<<"\n";
	cout<<"-------------------------------------------------------------\n";
	double d =23.234343;
	
	cout<<"template_function(d); : "<< template_function(d)<<"\n";
	cout<<"-------------------------------------------------------------\n";
	
	
}
