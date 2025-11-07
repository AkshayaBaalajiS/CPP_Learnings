#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	cout<<"This is the program to understand the auto in cpp\n";

	int a = 12;
	float b = 12.12f;
	char c = 'a';
	double d = 12.1212121;
	string s = "Hi String";
	char * ptr = "This is the char *";
	float array[] = {1.12f,0.123f, 0.123f, 0.2134f,0.234f};
	float * fptr;

	// auto begins ;

	auto autoInt = a;
	cout<<"type of auto variable " << typeid(autoInt).name() <<std::endl; 

	auto autoFloat = b;
	cout<<"type of auto variable " << typeid(autoFloat).name() <<std::endl; 
	auto autoChar = c;
	cout<<"type of auto variable " << typeid(autoChar).name() <<std::endl; 
	auto autoDouble = d;
	cout<<"type of auto variable " << typeid(autoDouble).name() <<std::endl; 
	auto autoString = s;
	cout<<"type of auto variable " << typeid(autoString).name() <<std::endl; 
	auto autoCptr = ptr;
	cout<<"type of auto variable " << typeid(autoCptr).name() <<std::endl; 
	auto autoFptr= fptr;
	cout<<"type of auto variable " << typeid(autoFptr).name() <<std::endl; 

	
	// we are going to try multiple assignment f the auto variable with diff type 

	// auto autoMultiAss;  // auto has to be intitialized 

	auto autoMultiAss = 2 ; // at  first we are ass with int 
	autoMultiAss = 23.234f ; // this will not create error cause it will be casted 
	autoMultiAss = autoCptr; // this will create error cause auto type deducted at initialization so this will create eror 

}