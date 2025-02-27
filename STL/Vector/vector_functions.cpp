#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool function_sort(int a , int b)
{
	if(a>b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	cout<<"This is the program to understand the vector functions \n";

	int size ;
	cout<<"Enter the size of the vector : ";
	cin>>size ;

	vector<int> int_vector ;
	// insert element 
	{
		int tmep ;
		for(int i=0;i<size;i++)
		{	
			// int_vector[i]  // this cant be done because there is no ele so indexing cant be done 
			cout<<"Enter the ele for " << i << " : ";
			cin>>tmep;
			int_vector.push_back(tmep);
		}
	}

	// printing the vector  
	{
		// way 1 
		cout<<"Way 1 of printing the vector  : ";
		for(int i: int_vector)
		{
			cout<<i << "   ";
		}
		cout<<endl;

		// way 2 
		cout<<"Way 2 of printing the vector  : ";
		for(int i=0;i<int_vector.size();i++)
		{
			cout<<int_vector[i]<< "   ";  
		}
		cout<<endl;

		// way 3 
		cout<<"Way 3 of printing the vector  : ";
		vector<int>::iterator it  = int_vector.begin();
		for( ; it!=int_vector.end();it++ )
		{
			cout<< *it <<"   " ; 
		}
		cout<<endl;
	}

	// begin and end 
	{
		cout<<endl;
		cout<<"Begin and End \n";
		cout<<"The begin element of the vector  : " <<*int_vector.begin()<<endl;
		cout<<"The end element of the vector  : " <<*int_vector.end()<<endl;
		cout<<"The end -1 element of the vector  : " <<*(int_vector.end()-1)<<endl;
		cout<<endl;

	}

	// sort vector 
	{	
		sort(int_vector.begin(),int_vector.end());
		cout<<"After sort the vector way 1   : ";
		for(int i=0;i<int_vector.size();i++)
		{
			cout<<int_vector[i]<< "   ";  
		}
		cout<<endl;

		// way 2 of sorting 
		sort(int_vector.begin(),int_vector.end(),function_sort);
		cout<<"After decending sort way 2  the vector  : ";
		for(int i=0;i<int_vector.size();i++)
		{
			cout<<int_vector[i]<< "   ";  
		}
		cout<<endl;
	}

	// reverse a vector 
	{
		cout<<endl;
		cout<<"Reverse of the vector is  : ";
		reverse(int_vector.begin(),int_vector.end());
		cout<<"Descending of the vector  : ";
		for(int i=0;i<int_vector.size();i++)
		{
			cout<<int_vector[i]<< "   ";  
		}
		cout<<endl;
	}

	// max_element, min_element , max_minelement 
	{
		cout<<"The maximum element is  : " << *max_element(int_vector.begin(),int_vector.end())<<endl;
		cout<<"The minimum element is  : " << *min_element(int_vector.begin(),int_vector.end())<<endl;
		auto it = minmax_element(int_vector.begin(),int_vector.end());
		cout<<"The max is " << *it.first << " The Min is  " << *it.second   <<endl;

	}

	//count 
	{
		cout<<endl<<"count function \n";
		int eke;
		cout<<"Enter the element to count in the vector   : ";
		cin>>eke ;
		int count_ele = count(int_vector.begin(),int_vector.end(),eke);
		cout<<"Element : " << eke <<" occurs " << count_ele <<" number of times \n";
	}


	// find and distance 
	{
		cout<<endl<<"find and position in vector \n";
		int eke ;
		cout<<"Enter the element to find : ";
		cin>>eke ;
		auto it  = find(int_vector.begin(),int_vector.end(),eke);
		int distance_result =  distance(int_vector.begin(),it);
		cout<<"The distance is : " << distance_result<<endl;
	}

	// insert 
	{
		cout<<endl<<"Before the vector insert : ";
		for(int i=0;i<int_vector.size();i++)
		{
			cout<<int_vector[i]<< "   ";  
		}

		cout<<endl<<"The vector insert \n";
		int ele ;
		cout<<"Enter the ele to be inserted ";
		cin>>ele;

		int pos ;
		cout<<"Enter the position to be inserted ";
		cin>>pos;
		int_vector.insert(int_vector.begin()+pos,ele);
		cout<<"After insert of the vector  : ";
		for(int i=0;i<int_vector.size();i++)
		{
			cout<<int_vector[i]<< "  ";  
		}
		cout<<endl;
	}

}