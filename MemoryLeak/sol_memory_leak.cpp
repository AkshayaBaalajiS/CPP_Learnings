#include <iostream>
#include <memory>
using namespace std;

int main()
{
	cout<<"Program to understand the memory leak \n";
	int arr[] ={12,23,34,45,56,76};

	unique_ptr<int *> uniq = make_unique<int*>(arr);
	cout<<"Ptr holds arr " << (*uniq)[0] << " " << (*uniq)[1] << " " << (*uniq)[2] << " " << (*uniq)[3] <<endl;

	uniq = make_unique<int *>(new int[20]); // here the old pointer is auto freed 

}