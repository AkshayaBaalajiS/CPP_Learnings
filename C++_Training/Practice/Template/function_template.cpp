#include<iostream>
#include<typeinfo>
using namespace std ;

template<typename t1 , typename t2>
void template_function(t1 args1 , t2 args2)
{
	cout<<"##################################\n";
	cout<<"args1 : " << args1 << "   typeid().name()  : " << typeid(args1).name() <<"\n";
	cout<<"args2 : " << args2  << "   typeid().name()  : " << typeid(args2).name()<< "\n";
	cout<<"##################################\n";
}

int main()
{
	cout<<"-------------------------------------------------------------\n";
	int a =120;
	float b= 2.344f ;
	template_function<int,float>(a,b);
	cout<<"-------------------------------------------------------------\n";
	char arr[] = "Akshay" ;
	string str ="a";
	template_function<char*,string>(arr,str);
	cout<<"-------------------------------------------------------------\n";
	double d =23.234343;
	template_function(d,'a');
	cout<<"-------------------------------------------------------------\n";
	
	
}
