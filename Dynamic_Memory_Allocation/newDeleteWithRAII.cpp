#include <iostream>
using namespace std;

template <typename T>
class A
{
	T * ptr ;
	public:
	T ** dptr;
		A() : ptr(new T[10]), dptr(new T*[10])
		{
			cout<<"@ A class constructor with RAII Implemented Where in constructor resource allocated \n";
		}

		// int ptrSize()
		// {
			// int sizee = sizeof(*ptr) / sizeof(ptr); // this will not work fine cause the *ptr is int sizeof(int) -- 4  
			// return sizee;
		// }

		~A()
		{
			cout<<"@ A class destructor with RAII Implemented Where in destructor resource deallocated \n";
			delete [] ptr;
			delete [] dptr;
		}		
};

int main()
{
	cout<<"New and Delete in Dynamic Memory Allocation \n";
	A<int> obj;
	int arr1[]= {12,23,34};
	int arr2[]= {22,23,24};
	int arr3[]= {32,33,34};
	int arr4[]= {42,43,44};
	int arr5[]= {52,53,54};

	obj.dptr[0] = arr1;
	obj.dptr[1] = arr2;
	obj.dptr[2] = arr3;
	obj.dptr[3] = arr4;
	obj.dptr[4] = arr5;
	cout<<"-----------------------\n";
	cout<< "0 0--"<< obj.dptr[0][0] <<endl;
	cout<< "0 1--"<< obj.dptr[0][1] <<endl;
	cout<< "0 2--"<< obj.dptr[0][2] <<endl;
	cout<<"-----------------------\n\n";

	cout<<"-----------------------\n";
	cout<< "1 0--"<< obj.dptr[1][0] <<endl;
	cout<< "1 1--"<< obj.dptr[1][1] <<endl;
	cout<< "1 2--"<< obj.dptr[1][2] <<endl;
	cout<<"-----------------------\n\n";
	

	cout<<"-----------------------\n";
	cout<< "2 0--"<< obj.dptr[2][0] <<endl;
	cout<< "2 1--"<< obj.dptr[2][1] <<endl;
	cout<< "2 2--"<< obj.dptr[2][2] <<endl;
	cout<<"-----------------------\n";


	
	// cout<<"Size of ptr = " << obj.ptrSize()<<endl;
}
