#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool sort_func(int a , int b)
{
	// if(a<b)
	// {
	// 	return true;
	// }
	// else
	// {
	// 	return false;
	// }

	return (a<b ? true : false );
}

int main()
{
	cout<<"This is the program for practising the Vector operations  \n";
	
	int n ;
	cout<<"Enter the number of elements : ";
	cin>>n ;
	cout<<endl;

	vector<int> vvecc;
	
	int tmep =0 ;
	for(int i=0;i<n;i++)
	{
		cin>>tmep ;
		vvecc.push_back(tmep);
	}

	cout<<endl;
	cout<<"The Vector before sort is  : " ;
	for(int i : vvecc)
	{
		cout<<i << "   " ;
	}
	cout<<endl;


	// sort is a fucntion from the algorithm to sort a vector 
	{
		sort(vvecc.begin() , vvecc.end() , sort_func);
		cout<<"\nThe Vector after sort is :  " ;
		for(int i : vvecc )
		{
			cout<< i << "   " ;
		}
		cout<<endl ;
	}

	


	// begin, end function in a vector 
	{
		cout<<endl ; 
		auto beginn = vvecc.begin() ; // this will work 
		auto endd = vvecc.end() ; // this wont work 

		cout<<"The begin element is : " << *beginn <<endl ;
		cout<<"The end always point to next of last : " << *endd <<endl ;
		cout<<"The *end-1 points to next of last and -1 : " << *endd-1 <<endl ; // the pointer arithmetic concept work here *end = 0 so 0 -1 =  -1 
		cout<<"The *(end-1) points to last element : " << *(endd-1) <<endl ; // the pointer arithmetic concept work here *end = 0 so 0 -1 =  -1 

	}

	// max_element, min_element, minmax_element 
	{
		cout<<endl;
		// max element function in a vector 
		int max_ele  = *max_element(vvecc.begin(),vvecc.end());
		cout<<"The Max Element is : " << max_ele <<endl ;
		
		// min element function in a vector 
		int min_ele  = *min_element(vvecc.begin(),vvecc.end());
		cout<<"The Max Element is : " << min_ele <<endl ;

		// single function to get the min and max element 
		auto it  = minmax_element(vvecc.begin(),vvecc.end());
		cout<<"Min Element is  it.first: " << *it.first <<endl ; // do not forget to derefer
		cout<<"Max Element is  it.second: " << *it.second <<endl ;  // do not forget to derefer
	}

	// reverse function in the vector 
	{
		cout<<endl ;
		reverse(vvecc.begin(),vvecc.end());
		cout<<"\nThe Vector after reverse is :  " ;
		for(int i : vvecc )
		{
			cout<< i << "   " ;
		}
		cout<<endl ;
	}


	// find and distance in the vector 
	// the find and distance will be from starting from the index 0 
	// if the ele is not there in the vector it returns the last element + 1 
	{
		cout<<endl;
		int ele ;
		cout<<endl;
		cout<<"Enter the element to find  : " ;
		cin>>ele;

		auto it = find(vvecc.begin(),vvecc.end(),ele);
		int diss = distance (vvecc.begin(),it);
		cout<<"The Distance of "<< ele <<" is : " << diss <<endl; 

		cout<<endl;
		cout<<"Enter the element to find : " ;
		cin>>ele;
		auto itt = find(vvecc.begin(),vvecc.end(),ele);
		int disss = distance (vvecc.begin(),itt);
		cout<<"The Distance of "<< ele <<" is : " << disss <<endl; 
	}

	cout<<endl ;
	{
		cout<<"The count function of the vector " <<endl;
		int ele ;
		cout<<"Enter the element  : " ;
		cin>>ele ;
		int count_number = count(vvecc.begin(),vvecc.end(),ele);
		cout<<"The ele " << ele << " occured " << count_number << " number of times" <<  endl;

	}

	
	

}