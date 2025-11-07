#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout<<"This is the program for prac the type casting \n";
	// int to string 
	{
		int a = 12;
		string strr = to_string(a);
		cout<<"Int value is = " << a  << " Same string is = " << strr <<endl; 

		// voice versa 
		int b= stoi(strr);
		cout<<"Int value from string  = " << b  << " String is = " << strr <<endl; 
		cout<<endl;
	}

	// int to char 
	{
		int a =34;
		char ch = a;
			
		// voice versa 
		int ina = ch ;
		cout<<"Int value is  : " << ina  << "  char ele is  " << ch <<"--"<<endl ;
		cout<<endl;
		
	}

	// char to string 
	{
		char ch = 'a';
		string result (1,ch);
		cout<<"The char  " << ch << " to string is " << result <<endl;

		result="b";
		ch = result[0];
		cout<<"The string  " << result << " to char is " << ch <<endl;
		cout<<endl;

	}


	// chhar * to string 
	{

		char * name = "Akshaya Baalaji S";
		string sname (name);
		cout<<"THe char * is : " << name  << " strign is : " << sname <<endl; // proof that the cout conside the char * as cstring in c++

		// voice versa 
		string result="asfafds";
		char * char_res  = const_cast<char *>(result.c_str());
		cout<<"THe string is  " << result << " the char is " << *char_res<<endl;
		cout<<endl;

	}

}