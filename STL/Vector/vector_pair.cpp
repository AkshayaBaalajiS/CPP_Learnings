#include <iostream>
#include <map>
#include<vector>
using namespace std;

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
}