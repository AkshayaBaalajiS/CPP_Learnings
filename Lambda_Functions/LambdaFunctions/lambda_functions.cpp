#include <iostream>
#include <functional>
using namespace std;
// Lambda function callback 
void callBackFunc(std::function<int (void *, int)> someFunction)
{
	cout<<"@ void callBackFunc(std::function<int (void *, int)> someFunction)\n";
	someFunction(malloc(sizeof(int)), 23);
}

// function callback 
void functionCallback(std::function<void (std::function<int (void * , int)>)> callBackFunc34)
{
	cout<<"@void functionCallback(std::function<void (std::function<int (void * , int)>)> callBackFunc34)\n";
	std::function<int (void * , int)> lambda1 = [] (void * , int)
	{
		cout<<"@std::function<int (void * , int)> lambda1\n";
		return 234;
	};
	callBackFunc34(lambda1);
}

int main()
{
	cout<<"This is the program to understand the lambda function \n";
	std::function<void (int, int)> lambdaFunc = [](int, int)
	{
		cout<<"Lambda function\n";
	};
	lambdaFunc(234,234);

	std::function<int (void *, int)> lambdaFunc1 = [](void *ptr, int)
	{
		cout<<"Lambda function11\n";
		return 12;
	};
	 // lambdaFunc1(malloc(sizeof(int)),234);
	int result = lambdaFunc1(malloc(sizeof(int)),234);
	cout<<"Result  ==  " << result <<endl;	

	callBackFunc(lambdaFunc1);

	std::function<void (std::function<int (void * , int)>)> callBackFunc2 = callBackFunc; // this line is to check the std::function is crt for the callBackFunc

	cout<<"-------------------------------------------\n";
	functionCallback(callBackFunc2);
	cout<<"-------------------------------------------\n";
	

}	