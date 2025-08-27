#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main()
{
	cout<<"Range based loop prac\n";

	int arr[]={1,2,3,4,5,6,7,8,9,10};

	cout<<"Array printing \n";
	for(auto i:arr)
	{
		cout<<i << "  " ;
	}
	cout<<endl;

	vector<string> vec_str;
	vec_str.push_back("Akshay");
	vec_str.push_back("Baalaji");
	vec_str.push_back("Chris");
	vec_str.push_back("Deepak");
	vec_str.push_back("Ethi");

	cout<<"Vector string print \n";
	for(auto i : vec_str)
	{
		cout<<i<<"  " ;
	}

	cout<<endl;
	vector<int> vec_int = {1,2,3,4,5};
	cout<<"Vector int print \n";
	for(auto i : vec_int)
	{
		cout<<i<<"  " ;
	}

	cout<<endl;
	map<int,string> map_1 ;
	map_1[0] = "Akshay" ;
	map_1[1] = "Baalaji" ;
	map_1[2] = "Chris" ;
	map_1[3] = "Deepak" ;
	map_1[4] = "Ethi" ;
	map_1[5] = "Ethi" ;
	
	for(auto i : map_1)
	{
		cout<<"First " << i.first<<"   " ;
		cout<<"Second " << i.second<<endl; 
	}

	set<string> set_1 ;
	set_1.insert("Akshay");
	set_1.insert("Baaaji");
	set_1.insert("Chris");
	set_1.insert("Deepak");
	set_1.insert("Ethiraj");
		
	cout<<"Set print \n";
	for(auto i : set_1)
	{
		cout<<i<< "  " ;
	}
	cout<<endl;
	cout<<"Set printing in for loop\n";
	for(auto i=set_1.begin();i!=set_1.end();i++)
	{
		cout<<*i<<"  ";
	}



}