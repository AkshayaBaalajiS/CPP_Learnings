#include <iostream>
#include <cstring>
using namespace std;

class Problem 
{
	public :
		Problem()
		{
			cout<<"Problem class constructor \n";
		}

		virtual bool odd_even(int number) = 0 ;

		virtual void array_sort(int * arr, int sizee ) = 0 ;
		
		virtual string remove_vowel(char * array) = 0 ;

		~Problem()
		{
			cout<<"Problem class constructor \n";
		}
};
