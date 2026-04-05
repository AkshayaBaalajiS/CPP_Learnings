#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cout<<"This is the code to understand the lambda function in cpp\n";

	int a ;
	vector<int> vectt;

	auto lambda = [&, a]()
	{
		cout<<"lambda function \n";
		// a++; // this cant be done cause this is a read only variable 
	};

	lambda();

}