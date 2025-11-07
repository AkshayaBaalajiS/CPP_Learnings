#include <iostream>
#include <string> 
#include <algorithm>
#include <cstring>

using namespace std ;

int main()
{
	cout<<"The string understanding \n";
	string str ;
	{
		cout<<"Enter the string  : ";
		getline(cin,str);
		cout<<endl;
	}
	cout<<"Entered string is : " <<str <<endl;
	
	// sort of the string is 
	{
		cout<<endl;
		sort(str.begin(),str.end());
		cout<<"The Sorted string is :  " << str;
		cout<<endl;
	}	

	// reverse of the string is
	{
		cout<<endl;
		reverse(str.begin(),str.end());
		cout<<"The reverse of the string is  : " << str;
		cout<<endl; 
	}

	// the count of letter is 
	{
		cout<<endl;
		char ele ;
		cout<<"Enter the Charecter  : " ;
		cin>>ele ;
		int countt = count(str.begin(),str.end(),ele);
		cout<<"The charecter " << ele << " occured  " << countt << " number of times \n";
	}

	// find and distance with char 
	{
		cout<<endl<<"The String is : " << str <<endl;
		char ele ;
		cout<<"Enyer the element to find : " ;
		cin>>ele;

		auto it  = find (str.begin(),str.end(),ele);
		int dis = distance(str.begin(),it);

		cout<<"The first index of " << ele <<  " is " << dis << endl ;
	}

	// begin and end 
	{
		cout<<endl<<"The String is : " << str <<endl;
		cout<<"Begin and End understanding  \n";

		cout<<"Begin ele is : " << *str.begin()<<endl ; 
		cout<<"End ele is : " << *str.end()<<endl ; 
		cout<<"End ele -1  is : " << *(str.end()-1)<<endl ; 

	}

	// substr 
	{
		cout<<endl<<"The String is : " << str <<endl;
		int stele ;
		cout<<"Enter the start ele : " ;
		cin>>stele ;
		cin.ignore();
		int endele ;
		cout<<"Enter the end ele : "  ;
		cin>>endele ;

		cout<<"The substrin is  : " << str.substr(stele,endele)<<endl;

	}


	// find and distance with string // this is the proof that find compared ele by elemnt so string cant be done 
	{
		// cout<<endl<<"The String is : " << str <<endl;
		// string ele ;
		// cout<<"Enter the element to find : " ;
		// cin>>ele;
		// auto it  = find (str.begin(),str.end(),ele);
		// int dis = distance(str.begin(),it);

		// cout<<"The first index of " << ele <<  " is " << dis << endl ;
	}

	{

		string strt ;
		cout<<"\nEnter the substring to find  : ";
		cin>>strt;

		if(str.find(strt)!=string::npos)
		{
			cout<<"The Substring present in String at index : "<<str.find(strt) << "\n";
		}
		else
		{
			cout<<"The Substring not present in String \n";
		}
	}

	// function to find the string length 
	{
		cout<<"\nFunction to find the string length \n1. size: " <<str.size()<<endl;
		// cout<<"2.sizeof : " << sizeof(str) <<endl;// this returns the size of the object 
		cout<<"2.length : " << str.length() <<endl;
		cout<<"3.strlen : " << strlen(str.c_str())<<endl;
		// cout<<"4.capacity : " << str.capacity()<<endl; // capacity will return the max 
		  
	}


}