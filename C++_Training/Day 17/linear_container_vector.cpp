#include<iostream>
#include<vector>
using namespace std ;


int main()
{
	vector <int> vec ;
	
	vec.reserve(5); // only the capacity of 5 will be created if space is not there the capacity doubled 
	
//	# size and capacity will give the number of ele 
	cout<< " vec.size() = "	<< vec.size() <<"\n";
	cout<< " vec.capacity() = "	<< vec.capacity() <<"\n";
	cout<<"..............................................\n";
	
//	push a element 
	vec.push_back(21) ;// push_back() is the std way of inserting the element in vector 
	cout<< " vec.size() = "	<< vec.size() <<"\n";
	cout<< " vec.capacity() = "	<< vec.capacity() <<"\n";
	cout<<"..............................................\n";
	
//	push a element 
	vec.push_back(22) ;// push_back() is the std way of inserting the element in vector 
	cout<< " vec.size() = "	<< vec.size() <<"\n";
	cout<< " vec.capacity() = "	<< vec.capacity() <<"\n";
	cout<<"..............................................\n";
	
//	push a element 
	vec.push_back(23) ;// push_back() is the std way of inserting the element in vector 
	cout<< " vec.size() = "	<< vec.size() <<"\n";
	cout<< " vec.capacity() = "	<< vec.capacity() <<"\n"; // capacity doubles with the prev 
	cout<<"..............................................\n";
	
//	push a element 
	vec.push_back(24) ;// push_back() is the std way of inserting the element in vector 
	cout<< " vec.size() = "	<< vec.size() <<"\n";
	cout<< " vec.capacity() = "	<< vec.capacity() <<"\n"; // here wont doubles capacity with the prev because the size ois there for holding 
	cout<<"..............................................\n";
	
//	push a element 
	vec.push_back(25) ;// push_back() is the std way of inserting the element in vector 
	cout<< " vec.size() = "	<< vec.size() <<"\n";
	cout<< " vec.capacity() = "	<< vec.capacity() <<"\n"; // here doubles capacity with the prev because the size is not there for holding 
	cout<<"..............................................\n";
	
	
	
	// iterator 
	vector<int>::iterator it = vec.begin();
	for(;it!=vec.end();++it)
	{
		cout<<"*it = " << *it <<"\n";
	}
	cout <<"++++++++++++++++++++++\n";
	for(auto it2 : vec )
	{
		cout<<"it2 = " << it2 <<"\n";
	}
	cout <<"++++++++++++++++++++++\n";
	
	
}
