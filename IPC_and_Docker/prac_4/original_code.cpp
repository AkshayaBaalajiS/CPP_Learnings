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

class Solutions :public  Problem 
{
	public :
		Solutions()
		{
			cout<<"Solutions class constructor \n";
		}

		bool odd_even(int number) override 
		{
			if(number%2==0)
			{
				return true;
			}
			return false;
		}

		void array_sort(int * arr , int sizee) override 
		{
			bool vari = true;
			int count =0;
			while(vari)
			{
				for(int i=0;i<sizee;i++)
				{
					if(arr[i] >  arr[i+1])
					{
						int tmep   =  arr[i];
						arr[i] = arr[i+1];
						arr[i+1] = tmep; 
						vari = true;
						count=0;
						break;
					}
					else
					{
						count++;
					}
				}
				if(count==sizee)
				{
					vari =  false;
				}
			}
			cout<<"After sort \n";
			for(int i=0;i<sizee;i++)
			{
				cout<<arr[i ] << "   " ;  
			}
		}


		string remove_vowel(char * array) 
		{
			string result ="";
			int sizee = strlen(array);
			for(int i=0;i<sizee;i++)
			{
				if(tolower(array[i])=='a' ||tolower(array[i])=='e' ||tolower(array[i])=='i' ||tolower(array[i])=='o' ||tolower(array[i])=='u')
				{

				}
				else
				{
					result=result+array[i];
				}
			}
			return result;
		}

		~Solutions()
		{
			cout<<"Solutions class destructor \n";
		}
};



class Base 
{
	public :
		Base()
		{
			cout<<"Base class constructor \n";
		}

		void print_something()
		{
			cout<<"This is the print stmt from the Base class print_function\n";
		}

		virtual void some_print()
		{
			cout<<"Some Print function definition from the Base class \n";
		}

		~Base()
		{
			cout<<"Base class destructor \n";
		}
};

class Derived : public Base 
{
	public :
		Derived()
		{
			cout<<"Derived class constructor \n";
		}

		void print_something()
		{
			cout<<"This is the print stmt from the Derived class print_function\n";
		}

		void some_print() override
		{
			cout<<"Some Print function definition from the Derived class \n";
		}

		~Derived()
		{
			cout<<"Derived class destructor \n";
		}
};


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