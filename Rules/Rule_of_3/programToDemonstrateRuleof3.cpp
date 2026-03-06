#include <iostream>
using namespace std;

namespace common
{	
	template <typename T>
	class A
	{
		T * ptr ;
		int size ;
		public :
			A(int size, T * ptr = nullptr) : ptr(ptr), size(size)
			{
				cout<<"@ A class default constructor\n";
			}

			A(const A & ref)
			{
				cout<<"@ A class copy constructor \n";
				this->size = ref.size;
				this->ptr = new T[size];
				// I am doing deep copy to avoid double delete 
				for(int i=0;i<this->size;i++)
				{
					this->ptr[i] = ref.ptr[i];
				}
			}

			A operator= (const A & ref)
			{
				cout<<"@ A class copy assignment operator \n";
				delete [] ptr;
				this->size = ref.size;
				this->ptr = new T[size];
				// I am doing deep copy to avoid double delete 
				for(int i=0;i<this->size;i++)
				{
					this->ptr[i] = ref.ptr[i];
				}
				return *this;
			}

			~A()
			{
				cout<<"@ A class destructor\n";
				// delete  ptr;
				delete [] ptr;
			}
	};
}

template <typename T>
using TAclass = common::A<T>;
// the above is the crt way to typedef 

// the below typedef with template is error cause typedef dont accept tempalte 
//template declaration of ‘typedef’
// template <typename T>
// typedef common::A<T> TClass;


// Below are the wrong way to do aliasing 
// below the A is not a complete type A with the template is the complete type 
// using TAclass = common::A;
// typedef  common::A TAclass;

int main()
{
	cout<<"This is the program to demonstrate Rule of 3 \n";
	// TAclass<float> obj;
	double arr[] = {12,23,34,45,56};
	double * ptr = new double[5] ;
	for(int i=0;i<5;i++)
	{
		ptr[i] = arr[i];
	}
	// TAclass * ptr = new TAclass(arr);
	TAclass ptr1 (5, ptr); //  Class Template Argument Deduction latest cpp feature  

	TAclass ptr2(ptr1); //  Class Template Argument Deduction latest cpp feature 
}