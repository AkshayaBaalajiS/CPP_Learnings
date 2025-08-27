#include <iostream>
#include <vector>
#include <functional>
using namespace std;

int main()
{
	cout<<"lambda function prac \n";
	int a = 123;
	int b = 123;
	int c = 123;
	
	vector <int> vector_1 = {0,12,21,234,2234,23,42};
	cout<<"Vector print before lambda call \n";	
	for(auto i : vector_1)
	{
		cout<<i << "  "; 
	}
	cout<<endl;

	// auto lambda_1 = [=,&vector_1]()
	std::function<void()> lambda_1 = [=,&vector_1]()
	{
		vector_1[0]=123;
		vector_1[1]=123;
		vector_1[2]=123;
		vector_1[3]=123;
		vector_1[4]=123;

		// a = 334;	 this cant be done 
	};
	lambda_1();
	
	cout<<"Vector print after lambda call \n";	
	for(auto i : vector_1)
	{
		cout<<i << "  "; 
	}
	cout<<endl;




}