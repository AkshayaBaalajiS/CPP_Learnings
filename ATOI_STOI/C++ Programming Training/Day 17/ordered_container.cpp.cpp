#include<iostream>
#include <unordered_set>
#include<vector>
#include<set>
#include <map>
using namespace std ;


int main()
{
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	//unique values in descending order 
	unordered_set <int> s1 = {1,2,3,4,5,6,7,1,2,3,4,5,6,7,8};
	for(auto it : s1 )
	{
		cout<< " ,"<<"it : " << it  ; 	
	}	
	cout<<"\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	//unique values in ascending order 
	set <int> s2 = {1,2,3,4,5,6,7,1,2,3,4,5,6,7,8};
	for(auto it : s2 )
	{
		cout<< " ,"<<"it : " << it  ; 	
	}	
	cout<<"\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	
	map <int , string > aadhar ;
	aadhar.insert(pair<int , string > (1,"Akshay"));
	aadhar.insert(pair<int , string > (2,"Baalaji"));
	aadhar.insert(pair<int , string > (3,"Chris"));
	aadhar.insert(pair<int , string > (4,"Deepak"));
	aadhar.insert(pair<int , string > (5,"Elavarasan"));
	aadhar.insert(pair<int , string > (6,"Farhan"));
	aadhar.insert(pair<int , string > (7,"Gunal"));
	
	for(auto it : aadhar)
	{
		cout<<"it = " << it.first <<"---" << it.second  <<"\n";
	}
	
	cout<<"\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	map <int , vector<string>> multi_name;
	vector<string> first_person = {"Akshay" , "Baalaji" ,"Chakarapani"};
	multi_name.insert(pair<int,vector<string>> (1,first_person));
	
	for(auto it : multi_name)
	{
		cout<<"it = " << it.first ;
		for(auto it2 : it.second )
		{
			cout<<"---" << it2  <<" , ";
		}
	}
	
}
