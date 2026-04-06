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
	cout<<"This is the program to understand the vector in cpp \n";
	vector<int> vect;
	log(vect);

	cout<<"----- insert -------\n";
	vect.push_back(12);
	printVect(vect);
	vect.push_back(12);
	printVect(vect);

	cout<<endl;
	vect.push_back(12);
	printVect(vect);

	vect.push_back(12);
	printVect(vect);

	vect.push_back(12);
	printVect(vect);

	vect.push_back(12);
	vect.push_back(12);
	vect.push_back(12);
	printVect(vect);


	cout<<"--------------------\n";

	cout<<"----- delete -------\n";
	vect.pop_back();
	printVect(vect);
	// vect.pop_back();
	// vect.pop_back();
	// vect.pop_back();
	// vect.pop_back();
	// vect.pop_back();
	// vect.pop_back();	
	// vect.pop_back();	 // deleted all element 
	
	// use clear 
	vect.clear();

	printVect(vect); // capacity is not updated 
	cout<<"--------------------\n";

	cout<<"----- shrink  -----\n";
	vect.shrink_to_fit();
	printVect(vect);
	cout<<"--------------------\n";


	cout<<"----- resize vs reserve  -----\n";
	vector<int> v1 ;
	vector<int> v2 ;
	cout<<"Before resize and reserve\n";
	printVect(v1);
	printVect(v2);

	cout<<"After resize and reserve \n";
	v1.reserve(1000);
	v2.resize(1000);

	printVect(v1);
	printVect(v2);


	cout<<"--------------------\n";



}