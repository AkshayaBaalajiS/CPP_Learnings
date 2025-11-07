#include <iostream>
#include <map>
#include <vector>

using namespace std;
int main()
{
	cout<<"This is the program to understand the map \n";
	map<int,int> mmapp ;
	vector<int> nums = {11,2,3,2,2,2,1,2,2,1,1,11,2,2,1,1,11,1};
	
	// it will automatically add the key and if key found ++ on the value 
	for(int  i :  nums)
	{
		mmapp[i]++;
	}

	// iterate and print 
	{
		cout<<"Way 1 to iterate \n";
		cout<<"Map items : \n";
		for(auto it :mmapp)
		{
			cout<< it.first << "   " << it.second <<endl; 
		}
		cout<<endl;
	}

	// this is the proof that the key should be unique 
	{
		// for(int  i :  nums)
		// {
		// 	mmapp[i] = i ;
		// }

		// // iterate and print 
		// {

		// 	cout<<"Map items : \n";
		// 	for(auto it :mmapp)
		// 	{
		// 		cout<< it.first << "   " << it.second <<endl; 
		// 	}
		// }
	}

	// another way to iterate 
	{	
		cout<<"Way 2 to iterate \n";
		// for(auto it = mmapp.begin();it!=mmapp.end();it++)
		for(auto it = mmapp.begin();it!=mmapp.end();++it)
		{
			cout<<it->first <<  "    " << it->second <<endl ;
		}
		cout<<endl;
	}
}