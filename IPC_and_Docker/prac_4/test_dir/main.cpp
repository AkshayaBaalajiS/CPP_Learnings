#include <iostream>
#include "Solutions.h"
#include "Obj_Slicing.h"


int main()
{
	cout<<"This is the program to make the solutions for problem in a class and test it\n";

	cout<<"1. Odd_Even Problem \n";
	cout<<"2. Sort an array \n";
	cout<<"3. Object Slicing \n";
	cout<<"4. Remove Vowel \n";

	
	cout<<"Enter a input \n";
	
	int input;
	cin>>input;

	Problem * pptr = new Solutions(); 
	switch(input)
	{
		case 1:
			int inpt;
			cout<<"Enter a number to check\n";
			cin>>inpt;
			pptr->odd_even(inpt) ? cout<<"Entered number is Even " : cout<<"Entered number is Odd \n"; 
			break;
		
		case 2:
			{
				int sizee;
				cout<<"Enter a size of array \n";
				cin>>sizee;
				int * arr_1 = new int[sizee];
				for(int i=0;i<sizee;i++)
				{
					int asf;
					cin>>asf;
					arr_1[i] =asf; 
				} 
				pptr->array_sort(arr_1, sizee);
				break;
			}
		case 3:
			{
				Derived dobj;
				Base bobj = dobj; // Object Slicing 

				bobj.print_something();
				bobj.some_print();


				Derived dobj_1;
				Base & bobj_1 = dobj_1;  // No Object slicing 

				bobj_1.print_something();
				bobj_1.some_print();
				break;
			}
		case 4:
			{
				char * input = new char[1000];

				cin.ignore(); // 🔧 Flush the leftover newline

				cin.getline(input, 100);
				cout<< "Result "<<  pptr->remove_vowel(input);
			}
		
		default:
			cout<<"Choose correctly\n";
			break;

	}

}