#include <iostream>
using namespace std;

template <typename T>
class Sample
{
	public :
		int size;
		T *ptr ;
		Sample() : ptr(nullptr)
		{
			cout<<"@ Sample class default constructor \n";
		}
		Sample(int size, T * arg =  nullptr) : size(size) 
		{
			ptr = new T[size];
			for(int i=0;i<size;i++)
			{
				ptr[i] = arg[i];
			}
		}

		~Sample()
		{
			cout<<"@ Sample class destructor \n";
			if(ptr!=nullptr)
			{
				delete [] ptr;
			}
			ptr = nullptr;
		}

};


int main()
{
	cout<<"this is the code for understanding the tempalte class and spec template class decl \n";
	Sample<int> obj;
	int arr[]= {12,23,34,45,56};

	auto * obj3 = new Sample(5, arr);
}