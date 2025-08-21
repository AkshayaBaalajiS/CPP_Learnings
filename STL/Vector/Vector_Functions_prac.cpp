#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;
int main()
{
	cout<<"This is the program to understand the vector operation \n";
	vector<int> vec_i ;

	// push back
	{
		int count ;
		cout<<"Enter the count of ele in vector : ";
		cin>> count ;

		for(int i =0;i<count;i++)
		{
			int temp ; 
			cout<<"Enter the ele  : " << i <<  " = "  ;
			cin >> temp ;

			vec_i.push_back(temp);

		}
	}


	// cout for the vector 
	{
		cout<<endl;
		cout<<"The Vector is  :  " ;
		for(int i : vec_i)
		{
			cout<< i << "  " ;
		}
		cout<<endl ;
	}


	// sort 
	{
		cout<<endl;
		sort(vec_i.begin(),vec_i.end());
		cout<<"The sort vector is  :  " ;
		for(int i : vec_i)
		{
			cout<< i << "  " ;
		}
		cout<<endl ;
	}	


	// insert 
	{
		cout<<"Enter the index to insert ";
		int tmep ;
		cin>>tmep ;
		int ele ;
		cout<<"Enter the element to insert  : " ;
		cin>>ele ;
		vec_i.insert(vec_i.begin()+tmep , ele);

		cout<<"The Vector after insert is  :  " ;
		for(int i : vec_i)
		{
			cout<< i << "  " ;
		}
		cout<<endl ;
	}
}