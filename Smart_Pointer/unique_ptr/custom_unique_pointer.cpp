#include <iostream>

using namespace std;

template <typename T>
class Unique_ptr
{
	public :
		T * ptr;

		Unique_ptr(T * ptr) : ptr(ptr) { }

		// Deletion of the copy constructor 
		Unique_ptr(Unique_ptr & ref ) = delete;
		// deletion of move constructor 
		Unique_ptr(Unique_ptr && ref ) 
		{
			this->ptr = ref.ptr;
			ref = nullptr;
		}

};

template <typename T, typename TT>
Unique_ptr<T> * make_shared(TT * ptr)
{
	// return static_cast<Unique_ptr<T> *>(malloc(sizeof(T)));//  no constructor call so accessing ther data member is wrongs
	return new Unique_ptr<T>(ptr);
}		

int main()
{
	cout<<"This is the code to understand the custom unique pointer \n";

	int array[] = {12,23,34,45,56,67,78,89};

	int * ptr = array;

	Unique_ptr <int>  * unique_ptr = new Unique_ptr(array);	

	Unique_ptr  unique_ptr_1 (ptr);	

	Unique_ptr <int>  * unique_ptr_2 =make_shared<int>(array);	
	cout<<"Access and check \n";

	cout<<"Pointer 0 : ";
	for(int i=0;i<sizeof(array)/sizeof(array[0]);i++)
	{
		cout<<i<<" -- ";
		cout<<unique_ptr->ptr[i]<< " ";
		cout<<"++";
	}
	cout<<endl;
	cout<<"Pointer 1 : ";
	for(int i=0;i<sizeof(array)/sizeof(array[0]);i++)
	{
		cout<<i<<" -- ";
		cout<<unique_ptr_1.ptr[i]<< " ";
		cout<<"++";
	}
	cout<<endl;
	cout<<"Pointer 2 : ";
	for(int i=0;i<sizeof(array)/sizeof(array[0]);i++)
	{
		cout<<unique_ptr_2->ptr[i]<< " ";
	}
	cout<<endl;
	


}