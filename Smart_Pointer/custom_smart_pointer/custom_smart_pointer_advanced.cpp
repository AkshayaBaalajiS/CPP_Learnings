#include <iostream>
// #include <memory>
using namespace std;

class Sample
{
	public:
		int a,b,c,d;
		Sample(int a, int b, int c, int d ) : a(a), b(b), c(c), d(d)
		{

		}
};

template <typename T > 
class Shared_Ptr
{
	public :
		int counter;
		T * ptr ;
		Shared_Ptr()
		{

		}
		Shared_Ptr(T * ptr) : ptr(ptr), counter(0)
		{

		}
		
		Shared_Ptr(Shared_Ptr & ref) 
		{
			this->ptr = ref.ptr;
			ref.counter++;
		}

		Shared_Ptr(Shared_Ptr && ref) 
		{
			this->ptr = ref.ptr;
			this->counter = ref.counter;
			

			ref.ptr = nullptr;
			ref.counter = 0;
		}

		T * operator ->()
		{
			return ptr ;
		}
};

template <typename T, typename ... TT >
Shared_Ptr<T> * make_shared(TT ... ptr)
{
	Shared_Ptr<T> * newPtr = new Shared_Ptr<T>();
	newPtr->ptr = new T(ptr...);
	return newPtr;
}

int main()
{
	cout<<"This is the program for custom smart pointer in CPP \n";


	Shared_Ptr <Sample> * obj = make_shared<Sample>(12,23,43,45);
	// cout<<obj->ptr->a <<endl;
	// cout<<obj->ptr->b <<endl;
	// cout<<obj->ptr->c <<endl;
	// cout<<obj->ptr->d <<endl;
	// the accessing with operator overloading 
	cout<<(*obj)->a <<endl;
	cout<<(*obj)->b <<endl;
	cout<<(*obj)->c <<endl;
	cout<<(*obj)->d <<endl;
	

	Shared_Ptr <Sample>  obj1 = *(make_shared<Sample>(12,23,43,45));
	cout<<obj1.ptr->a <<endl;
	cout<<obj1.ptr->b <<endl;
	cout<<obj1.ptr->c <<endl;
	cout<<obj1.ptr->d <<endl;


}