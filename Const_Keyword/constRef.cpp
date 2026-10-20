#include <iostream>
using namespace std;

int main()
{
	cout<<"This is the const reference \n";
	{
			int number = 34;
		int * const ptr = &number ;
		*ptr = number +34 ;
		//ptr = &number1 ; // this cant be done 

		cout<<"NUmber = " << number << "  *ptr = " << *ptr<<endl;

	}
	{
		int number = 34;
		int number1 = 45;
		const int * ptr = &number ;
		// *ptr = number +34 ; // this cant be done 
		ptr = &number1 ; // this can be done 


		cout<<"NUmber = " << number << "  *ptr = " << *ptr<<endl;

	}
	
}