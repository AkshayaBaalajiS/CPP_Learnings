#include <iostream>
using namespace std;


// the starting value will be 0

int main()
{
	enum COLORS{
		GREEN, RED, BLUE,
	};

	cout<<"enum / enumeration program \n";

	COLORS col_enum = COLORS::RED;
	// enum problems 
	// it can be type converted to int 
	if(col_enum ==1 )
	{
		cout<<"Yes the enum value is 1 \n";
	}
	else
	{
		cout<<"No the enum is not having the value of 1\n";
	}

	// we cant create a variable with enum value 
	// int RED= 12; // if the enum is in glob scope no error but if it is in local redefition error


	enum Gender { Male,
                  Female };

    // Defining enum2 Color
    enum Color { Red,
                 Green };

    if(Gender::Male == Color::Red)
    {
    	cout<<"SAme \n"; // prints same 
    }
}
