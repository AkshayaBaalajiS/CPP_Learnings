#include<iostream>
using namespace std;


class Sample 
{
	public : 
	int a;
	double d;
	char c;
		Sample()
		{
			cout<<"@ sample class constructor \n";
		}

		void function()
		{
			
			auto lambda = [*this] ()
			{
				/* assignment of readonly member 
				a =21234;
				d =232.2342342;
				c = 'a';
				*/
			};
			lambda();
			int localVar;
			auto lambda1 = [this] ()
			{
				// localVar = 234; // cause this capture only the object pointer 
				a =21234;
				d =232.2342342;
				c = 'a';
			};
			lambda1();

			auto lambda2 = [&] ()
			{
				localVar = 234; // cause this capture all  
				a =21234;
				d =232.2342342;
				c = 'a';
			};
			lambda2();
		}
};

int main()
{
	cout<<"This is the program for understanding the lambda capture clause in cpp \n";

	int localiVar;
	char localcVar;
	double localdVar;
	void * localvoidPtrVar;
	static int statInt = 234;
	
	// normal capture clause 
	auto lambdaFunction = []()
	{
		/*localiVar = 24; // this line will create error 
		 error: ‘localiVar’ is not captured */
		cout<<" @ auto lambdaFunction = []()\n";
		statInt++;

	};
	cout<<"statInt = " <<  statInt <<endl;
	lambdaFunction();
	cout<<"statInt = " <<  statInt <<endl;


	auto lambdaFunction1 = [&]()
	{
		localiVar = 234;
		localcVar = 'a';
		localdVar = 234.2342;
		localvoidPtrVar = malloc(10 * sizeof(int));		
	};

	cout<<"localiVar = " << localiVar<<endl;
	cout<<"localcVar = " << localcVar<<endl;
	cout<<"localdVar = " << localdVar<<endl;
	cout<<"localvoidPtrVar = " << localvoidPtrVar<<endl;
	cout<<"After lambda function with & in capture clause called \n";
	lambdaFunction1();
	cout<<"localiVar = " << localiVar<<endl;
	cout<<"localcVar = " << localcVar<<endl;
	cout<<"localdVar = " << localdVar<<endl;
	cout<<"localvoidPtrVar = " << localvoidPtrVar<<endl;

	auto lambdaFunction2 = [=]()
	{
		/* error for the below lines cause aassignment is not possible 
		localiVar = 234;
		localcVar = 'a';
		localdVar = 234.2342;
		localvoidPtrVar = malloc(10 * sizeof(int));		*/
		int llvar= localiVar + localdVar;

	};

	auto lambdaFunction3 = [&localiVar, localdVar]()
	{
		localiVar = 342;
		// localdVar = 234.2342; // assignment cant be done 
		double variable =  localdVar + localdVar ;
	};
	cout<<"--------------------------------\n";
	cout<<"localiVar = " << localiVar<<endl;
	cout<<"lambdaFunction3 function call \n";
	lambdaFunction3();
	cout<<"localiVar = " << localiVar<<endl;
	cout<<"--------------------------------\n";


	int x = 10;
	int * ptr =  &x ;
	auto lambda = [ptr]()
	{
		*ptr = 3245;
		int localX = 1234;
		statInt++;
		// ptr =&localX; // assignment of readonly member 
	};
	cout<<"statInt = " <<  statInt <<endl;
	cout<<"*ptr = " <<  *ptr <<endl;
	lambda();
	cout<<"statInt = " <<  statInt <<endl;
	cout<<"*ptr = " <<  *ptr <<endl;
	

	auto lambda1 = [ptr]() mutable 
	{
		*ptr = 45;
		int localX = 567546;
		ptr =&localX; // modify local copy will not be reflected out 
	};
	cout<<"*ptr = " <<  *ptr <<endl;
	lambda1();
	cout<<"*ptr = " <<  *ptr <<endl;
	

	auto lambda2 = [&ptr]() mutable 
	{
		*ptr = 45;
		int localX = 567546;
		ptr =&localX; // modify local copy and reflected out due to & in capture clause 
		statInt++ ;
	};
	cout<<"*ptr = " <<  *ptr <<endl;
	cout<<"statInt = " <<  statInt <<endl;

	lambda2();
	cout<<"*ptr = " <<  *ptr <<endl;
	cout<<"statInt = " <<  statInt <<endl;

}

/*

✔️ static, global, namespace variables do not require capture
✔️ They are accessible in any lambda capture clause
✔️ Modifying static variables is allowed

*/