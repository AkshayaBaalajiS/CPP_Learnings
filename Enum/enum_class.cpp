#include <iostream>
using namespace std;


// the starting value will be 0

int main()
{
	enum class COLORS{
		GREEN, RED, BLUE,
	};

	cout<<"enum class / enumeration program \n";

	COLORS col_enum = COLORS::RED;
	// enum problems 
	
	// this cant be done here cause enum class cant be type casted to int  safe
    // if(col_enum == 1 )
	// {
	// 	cout<<"Yes the enum value is 1 \n";
	// }
	// else
	// {
	// 	cout<<"No the enum is not having the value of 1\n";
	// }

	// we cant create a variable with enum value 
	int RED= 12; // this can be done here 

	enum class Gender { Male,
                  Female };

    // Defining enum2 Color
    enum class Color { Red,
                 Green };

    // this cant be done here cause enum class are type safe
    // if(Gender::Male == Color::Red) // error: no match for ‘operator==’ (operand types are ‘main()::Gender’ and ‘main()::Color’)
    // {
    // 	cout<<"SAme \n";
    // }
    // else
    // {
    // 	cout<<"Not same \n"; // print this case enum class are type safe 
    // }
}
