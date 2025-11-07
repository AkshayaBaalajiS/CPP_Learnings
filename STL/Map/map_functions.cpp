#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
	cout<<"This is the program to understand the Map in c++ \n";

	int sizee ;
	cout<<"Enter the size of the vector \n";
	cin>>sizee;

	vector<string> vec_string ;
	
	// input for the vector 
	{
		for(int i = 0; i<sizee;i++)
		{
			string temp ;
			// getline(cin,temp);
			cin>>temp;
			vec_string.push_back(temp);
			// cin.ignore();
		}
	}


	map<int, string > map_is;
	
	// map input load 
	{
		for(int i=0;i<sizee;i++)
		{
			map_is[i]=vec_string[i];
		}
	}

	// printing the output 
	{
		cout<<endl;
		cout<<"Way 1 of printing through for index \n";
		cout<<"Vector is : \n" ;
		for(int i=0;i<sizee;i++)
		{
			cout<<"Key = " << i << "  Value = " << map_is[i] <<endl ;
		}
		cout<<endl<<endl;

		cout<<"Way 2 of printing through Iterator  \n";
		cout<<"Vector is  : \n" ;
		for(auto it = map_is.begin(); it!=map_is.end();it++)
		{
			cout<<"it->first = " << it->first << "  it->second =  " << it->second<<endl;
		}
		cout<<endl<<endl;

		cout<<"Way 3 of printing by Iterator variable created  \n";
		cout<<"Vector is  : \n" ;
		map<int,string>::iterator map_is_it = map_is.begin();

		for(; map_is_it!=map_is.end() ;map_is_it++)
		{
			cout<<"map_is_it->first = " << map_is_it->first << "  map_is_it->second =  " << map_is_it->second<<endl;
		}
		cout<<endl<<endl;

		cout<<"Way 4 of printing by for each loop  \n";
		cout<<"Vector is  : \n" ;
		for(auto it  : map_is )
		{
			cout<<" it.first =  " <<it.first  << "  it.second = "<<it.second  <<endl;
		}
		cout<<endl<<endl;
		
	}	

	map<int , int > map_ii ;
	{
		vector<int> vec = {1,1,2,3,3,2,1,1,1,2,3,4};
		cout<<"Count the number of occurence "<<endl;
		for(int i : vec)
		{
			map_ii[i]++;
		}

		cout<<"Printing the map to find the ele and occurences \n";
		for(auto it : map_ii)
		{
			cout<<" it.first  = " << it.first << "  it.second = " << it.second<<endl; 
		}
	}



}