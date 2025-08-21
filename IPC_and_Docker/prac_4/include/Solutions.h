#include "Problem.h"

class Solutions :public  Problem 
{
	public :
		Solutions() ;

		bool odd_even(int number) override ;

		void array_sort(int * arr , int sizee) override ;


		string remove_vowel(char * array) ;

		~Solutions();
};
