#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
	cout<<"This is the program to understand the Char functions \n";
	string str  = "Ak()sh+a.y23a Baalaj;'i SE45nt745h6il85r85aj! . 23 234";

	// now we are trying to remove the non alphabetica charecter and return the alphabetic charecter 
	string temp_store ;

	for(int i=0;i<str.size();i++)
	{
		if(isalpha(str[i]))
		{
			// temp_store = temp_store + to_string(tolower(str[i]));
			temp_store = temp_store + static_cast<char>(tolower(str[i]));
		}
	}

	cout<<"The finalized string is : " <<  temp_store << endl;
}	
