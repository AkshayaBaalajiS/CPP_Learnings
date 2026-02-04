#include <iostream>
using namespace std;

int number = 234;
bool varia =false;

int main()
{
	cout<<"lambda function in cpp \n";

	auto lam = [=] ()
	{
		cout<<"number = " << number <<endl;
		// number++; // read only variable 
	};

	auto lam1 = [&] (int n = 1)
	{
		number+=n; // read only variable 
		cout<<"number = " << number <<endl;
	};

	// the below is how the lambda is for the condition variable 

	// A predicate is simply a callable that returns bool.
	// the bel;ow is predicate and this is how the lambda function will be on conditional variable wait fucntiion
	auto clam1 = [] 
	{
		return varia;
	};


	lam();
	lam1(234);
	int res = clam1();
	cout<< "Result === " << res <<endl;
}