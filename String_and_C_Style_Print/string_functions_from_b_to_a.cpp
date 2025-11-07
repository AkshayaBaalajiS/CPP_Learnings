#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std; 
int main()
{
	cout<<"This is the program for ths tring practice \n";
	string str_string ;

	// string input 
	{
		getline(cin,str_string);
		cout<<"Entered string is : " << str_string <<endl ;	
	}

	// size 
	{
		cout<<endl<<"String length  \n";
		cout<<"Way 1 .size() function result  = " << str_string.size() <<endl;
		cout<<"Way 2 .strlen() function result  = " << strlen(str_string.c_str()) <<endl;
		cout<<"Way 3 .length() function result  = " << str_string.length() <<endl;
		cout<<endl;
	}

	// sort 
	{
		cout<<"Sort function  : " <<endl ;
		sort(str_string.begin(),str_string.end());
		cout<<"The reversed string is : " << str_string <<endl ;
	}

	// begin, end 
	{
		cout<<"\nBegin and End  \n";
		cout<<"The begin ele is : " << *str_string.begin() <<endl;
		cout<<"The end ele is : " << *str_string.end() <<endl;
		cout<<"The end -1  ele is : " << *(str_string.end()-1) <<endl;
	}

	// reverse 
	{
		cout<<"\nReverse is \n";
		reverse(str_string.begin(),str_string.end());
		cout<<"The reverse of the string is : " << str_string <<endl ;
	}
	
	// count 
	{
		cout<<"Count function \n";
		cout<<"Enter the element  : ";
		char ch;
		cin>>ch;
		int count_1 = count(str_string.begin(),str_string.end(),ch); 
		cout<<"The charecter " << ch << " occur " << count_1<< " number of times \n";

	}

	//find and distance  
	{
		cout<<endl<<"Find and Distance : " << endl ;
		cout<<"Enter the element  : ";
		char ch;
		cin>>ch;
		auto it = find(str_string.begin(),str_string.end(),ch) ;
		int dista = distance(str_string.begin(),it);
		cout<<"The ele " <<ch << " found at index  " << dista <<endl ; 
	}

	
}