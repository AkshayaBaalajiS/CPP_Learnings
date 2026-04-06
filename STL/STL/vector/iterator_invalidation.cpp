#include <iostream>
#include <vector>
using namespace std;

void log(const vector<int>& vec)
{

	cout<<"vector size  = " << vec.size()<<endl;
	cout<<"vector capacity  = " << vec.capacity()<<endl;
	
}
// void printVect(vector<int> vec) // here we are passing the vector by value the pass by value of the vector will have diff behavioir here the unnecessary copy happens 
void printVect(vector<int>& vec) // so pass a by reference 
{
	cout<< "   - - - - - - -  \n";
	log(vec);
	for(int i: vec)
	{
		cout<< i << " " ; 
	}
	cout<<endl;
	cout<< "   - - - - - - -  \n";

}

int main()
{
	cout<<"This is the program to understand the iterator invalidation in cpp\n";

	vector<int> vect;
	vect.push_back(12);
	printVect(vect);
	auto it =  vect.begin();
	cout<<"*it = " << *it <<endl;
	vect.push_back(12);
	vect.push_back(12);
	printVect(vect);
	
	cout<<"invalid *it = " << *it <<endl;
	vect.clear();
	cout<<"invalid *it = " << *it <<endl;
	
}