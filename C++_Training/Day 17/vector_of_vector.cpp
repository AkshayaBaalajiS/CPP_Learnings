#include<iostream>
#include<vector>
using namespace std ;


int main()
{
	vector <int> vec_1;
	vector <int> vec_2 ;
	vector <vector <int>> vvec ;
	
	for(int i=0;i<5;i++)
	{
		vec_1.push_back(10+i);
	}
	for(int i=0;i<5;i++)
	{
		vec_2.push_back(20+i);
	}
	
	cout<<"+++++++++++++++++++++++\n";
	for (auto range_it : vec_1) // range 
	{
		cout<<"range_it   : " << range_it << "\n";
	}
	cout<<"+++++++++++++++++++++++\n";
	for (auto range_it : vec_2) // range 
	{
		cout<<"range_it   : " << range_it << "\n";
	}
	cout<<"+++++++++++++++++++++++\n";
	
	// push the vex inside the vvec 
	
	cout<<".......................\n";
	vvec.push_back(vec_1);
	vvec.push_back(vec_2);
	cout<<".......................\n";
	
	
	for(auto it1 : vvec )
	{
		for(auto it2 : it1)
		{
			cout<<"it2 = " << it2 <<",";
		}
	}
	cout<<"+++++++++++++++++++++++\n";
	
	
	
		
}
