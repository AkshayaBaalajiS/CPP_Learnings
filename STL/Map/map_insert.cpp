#include <iostream>
#include <map>
#include<vector>
using namespace std;


// the key should be unique 
int main()
{
	cout<<"This is the sample program to understand the map \n";
	vector<pair<int,string>> vp ;
	
	// char arr[20];
	string arr="";					
	for(int i=0;i<5;i++)
	{
		// cin.getline(arr,20);
		getline(cin,arr);
		// vp[i]=arr; // we cant directly do this this is not map 
		// since there is no ele in vector we cant directly do indexing 
		// vp[i].first=i;
		// vp[i].second=arr;	
		vp.push_back(make_pair(i,arr));

	}

	for(int i=0;i<5;i++)
	{
		cout<<vp[i].first<< "   "<<vp[i].second<<endl;	
	}

	map<int , string> mMap ;
	// way 1 of map insert 
	for(auto & it : vp  )
	{
		mMap.insert(it);
	}

	for(auto &it : mMap )
	{
		cout<<"it.first  = " << it.first << "   " << "it.second = " << it.second << endl ;
	}

	// way 2 of map insert 
	map<string,int> mMap_1;
	for(auto &it :vp  )
	{
		mMap_1[it.second]=it.first;
	}
	for(auto &it : mMap_1 )
	{
		cout<<"mMap_1["<< it.first <<"]  = " << it.second << endl;
	}

	map<string,int> mMap_2;
	// way 3
	for(int i=0;i<5;i++)
	{
		string tmep ;
		cin>>tmep;
		mMap_2.insert(make_pair(tmep,i));
	}

	for(auto &it : mMap_2 )
	{
		cout<<"mMap_2["<< it.first <<"]  = " << it.second << endl;
	}


}