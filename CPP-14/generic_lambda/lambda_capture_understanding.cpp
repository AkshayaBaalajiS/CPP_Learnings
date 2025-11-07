#include <iostream>
#include <functional>
using namespace std;

struct A 
{
	int a;
	char b;
	double d;
	A()
	{
		a=45;
		b=87;
		d=45.1232342;

		lambda1 = [*this] () mutable 
		{
			cout<<"auto lambda1 = [*this]()\n";
			cout<<"Before : " << a << " " << b << " " << d <<endl;
			// this cant be done 
			a++;
			b++;
			d++;
			// this->a;
		};	
	}
	std::function<void()> lambda1;

	std::function<void()> lambda = [this]()
	{
		cout<<"auto lambda = [this]()\n";
		cout<<"Before : " << a << " " << b << " " << d <<endl;
		a++;
		b++;
		d++;
	};
	// *this in the capture class will be done in cpp 17
	/* This wont work cause the lambda wont have the pointer 
	when we are giving this definition at constructor it works fine 
	std::function<void()> lambda1 = [*this]()
	{
		// *this capture the cpy of the obj
		cout<<"auto lambda1 = [*this]()\n";
		cout<<"Before : " << a << " " << b << " " << d <<endl;
		// this cant be done 
		// a++;
		// b++;
		// d++;
		// this->a;
	};
	*/

};


int main()
{
	cout<<"This is the code for understanding the lambda in cpp\n";
	int a=45;
	char b=87;
	double d=45.1232342;
	printf("%f",d);

	cout<<"Before Lambda  : \n";
	cout<<"a = " << a <<endl;
	cout<<"b = " << b <<endl;
	cout<<"d = " << d <<endl;

	// when capture set to & 
	auto lambda = [&]()
	{
		a++;
		b++;
		d++;
	};

	lambda();

	cout<<"After Lambda  : \n";
	cout<<"a = " << a <<endl;
	cout<<"b = " << b <<endl;
	cout<<"d = " << d <<endl;

	cout<<"Before Lambda1  : \n";
	cout<<"a = " << a <<endl;
	cout<<"b = " << b <<endl;
	cout<<"d = " << d <<endl;

	// when capture set to = 
	auto lambda1 = [=]()
	{
		// the assignment operations are not possible as it is read only when we use the = in capture class 
		// a++;
		// b++;
		// d++;
		cout<<a << b << d <<endl;
	};
	lambda1();
	

	auto lambda8 = [=]() mutable 
	{
		// the assignment operations are not possible as it is read only when we use the = in capture class with mutable 
		a++;
		b++;
		d++;
		cout<<a << b << d <<endl;
	};
	lambda8();


	auto lambda3 = [=]()
	{
		// the assignment operations are not possible as it is read only when we use the = in capture class 
		// a++;
		// b++;
		// d++;
		int some_value = a+d;
		return some_value;
	};

	int some_value = lambda3();
	cout<<"Some value = " << some_value <<endl;
	
	// this is also read only 
	auto lambda4 = [a,b]()
	{
		cout<<a << " " <<b<<endl;
		// cout<<d<<endl; // this cant be used cause lambda knows only a and b 

		// the assignment stmt cant be used without the reference passed 
		// a++;
		// b++;
		// d++;
	};
	lambda4();

	auto lambda5 = [&a,&b]()
	{
		cout<<a <<" " << b<<endl;
		// cout<<d<<endl; // this cant be used cause lambda knows only a and b 
		a++;
		b++;
		// d++;
	};
	lambda5();

	cout<<"After lambda5  : \n";
	cout<<"a = " << a <<endl;
	cout<<"b = " << b <<endl;
	cout<<"d = " << d <<endl;


	auto lambda6 = [a,&b]()
	{
		cout<<a <<" " << b<<endl;
		// cout<<d<<endl; // this cant be used cause lambda knows only a and b 
		// the variable passed with = so assignment cant be done on those
		// a++;
		b++;
		// d++;
	};
	lambda6();
	cout<<"After lambda6  : \n";
	cout<<"a = " << a <<endl;
	cout<<"b = " << b <<endl;
	cout<<"d = " << d <<endl;

	// the capture class with this cant be done cause this is main function not class 
	/*
	auto lambda7 = [this]()
	{
		cout<<a <<"  " << b << "  "  << d <<endl;
		
	};
	lambda7();
	cout<<"After lambda7  : \n";
	cout<<"a = " << a <<endl;
	cout<<"b = " << b <<endl;
	cout<<"d = " << d <<endl;
	*/
	A obj;
	obj.lambda();
	obj.lambda();
	obj.lambda1();
	obj.lambda1();
		
	std::function<int ()> lambda9 = []()
	{
		int er =2134;
		return er;
	};
}	