#include <iostream>
#include <memory>
using namespace std;

template <typename T>
class UniquePtr
{	
	T * ptr ;
	public:
		UniquePtr()
		{
			ptr = new T();
		}
		UniquePtr(T * args) : ptr(args)
		{

		}

		UniquePtr(UniquePtr && args)
		{
			this->ptr = args.ptr;
		}
		UniquePtr(UniquePtr & out) = delete;

		void get()
		{
			cout<<"Address  = " << ptr <<endl;
		}

		~UniquePtr()
		{
			delete ptr;
		}
		
};	

template <typename T, typename... TT>
UniquePtr<T> make_uniquee(TT... args )
{	
	return UniquePtr<T>();
}	

class Sample
{
	public:
		int * ptr ;
		Sample(int number=10) :  ptr(new int[number]) 
		{
			cout<<"@ Sample class constructor \n";
		}

		void function()
		{
			cout<<"Sample class function \n";
		}

		~Sample()
		{
			cout<<"@ Sample class destructor \n";
		}
		
};

int main()
{
	cout<<"@ Custom Unique Pointer \n";
	UniquePtr<Sample> sampleObj;
	// UniquePtr<Sample> sampleObj1 = sampleObj; // this is working  // copy constructor deleted 
	UniquePtr<Sample> sampleObj2(new Sample()); // this is working as normal  	 
	
	UniquePtr<Sample> sampleObj3 = make_uniquee<Sample>();	
	UniquePtr<Sample> sampleObj4(std::move(sampleObj3));	
 
	
	// sampleObj.function();
}