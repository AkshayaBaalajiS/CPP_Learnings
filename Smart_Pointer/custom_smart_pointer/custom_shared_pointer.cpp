#include <iostream>
using namespace std;

template <typename T>
class cshared_ptr
{

	int counter;			
	public :
		T * pointer;
		cshared_ptr() : pointer(nullptr), counter(1)
		{
			cout<<"@ cshared_ptr constructor \n";
		}

		cshared_ptr(T * ref ) :  counter(1)
		{
			pointer =  ref;
			cout<<"@ cshared_ptr parameterized constructor \n";
		}

		cshared_ptr(cshared_ptr& ref)
		{
			++ref.counter;
			this->pointer = ref.pointer;
			this->counter =  ref.counter;
		}

		int use_count()
		{
			return counter;
		}

		~cshared_ptr()
		{
			cout<<"@ cshared_ptr destructor \n";
		}
};

class classA
{
	public :
		int * data;
		int size; 
		classA()
		{
			cout<<"# classA constructor \n";
		}
		classA(int * arr, int s)
		{
			data=arr;
			size = s;

			cout<<"# classA parameterized constructor \n";
		}
		~classA()
		{
			cout<<"# classA destructor\n";
		}
		
};
/* here I tried with NO ARGUMENT 
template <typename T>
cshared_ptr<T>  make_shared()// it should take variable number of argument as of now we keep as default 
{
	return *(new cshared_ptr<T>(new T()));
}
*/
template <typename T, typename... V>
cshared_ptr<T>  make_shared(V&&... ref)// it should take variable number of argument as of now we keep as default 
{
	return *(new cshared_ptr<T>(new T(std::forward<V>(ref)...)));
}

/*
V&&... ref is a variadic forwarding reference, just like in std::make_shared.

std::forward<V>(ref)... perfectly forwards all arguments to T’s constructor.

So in theory, you can call make_shared<MyClass>(1, "abc", 3.14) if MyClass has a matching constructor.
*/


int main()
{
	cout<<"This is the program to understand the custom_shared_ptr in C++\n";
	int array[] = {12,23,34,45,56,67};
	int array1[] = {67,43,65,67,98,98};
	cshared_ptr shared_ptr_1 (new classA(array, 6));

	for(int i=0;i<6;i++)
	{
		cout<<shared_ptr_1.pointer->data[i] <<endl;
	}
	cout<<endl;


	cshared_ptr shared_ptr_2 = shared_ptr_1;

	cout<<"shared count of the shared pointer = " << shared_ptr_1.use_count()<<endl;

	// creating the custom_shared_ptr as pointer 
	cshared_ptr<classA> * shared_ptr_ptr = new cshared_ptr(new classA(array1, 6)); // put the assmein the make_shared overrided definition toi return this 

	classA object ;
	object.data  = array1;
	object.size  = 6;

	// make shared usage 
	// cshared_ptr<classA>  shared_ptr_3 = make_shared<classA>();
	int array2[] = {89,67,56,345,56,67};
	cshared_ptr<classA>  shared_ptr_3 = make_shared<classA>(array2,6);
	for(int i=0;i<shared_ptr_3.pointer->size;i++)
	{
		cout<<shared_ptr_3.pointer->data[i] << "  " ;
	}
	cout<<endl;

}