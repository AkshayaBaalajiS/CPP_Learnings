#include <iostream>
#include <vector>
using namespace std;

using INT = int; // simple usecase 

// complex uc can be only done by the using 
template <typename T>
using Vec = std::vector<T>;

int main()
{
	cout<<"This is the program to demonstrate the using in cpp \n";
	INT a = 12;
	cout<<"A = " << a <<endl;
	cout<<"Type of A = " << typeid(a).name() <<endl;
	
	Vec<int> vector_var ;
	vector_var.push_back(12);

	cout<<"Vector var = " << vector_var[0] <<endl;
	cout<<"Type of Vector var = " << typeid(vector_var).name()<<endl;
	
}	