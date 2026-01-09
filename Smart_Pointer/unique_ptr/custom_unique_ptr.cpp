#include <iostream>
#include <memory>
using namespace std;

template <typename T>
class UniquePtr
{	
	T * ptr ;
	public:
		UniquePtr() : ptr(nullptr)
		{
			// ptr = new T(); 
			/*
			std::unique_ptr does NOT allocate by default

			Forces unwanted allocations
			*/
		}
		UniquePtr(T * args) : ptr(args)
		{

		}

		UniquePtr(UniquePtr && args) // move constructor working 
		{
			this->ptr = args.ptr;
			args.ptr = nullptr ; // to avoid double deletion issue 
		}

		UniquePtr(UniquePtr & out) = delete; // copy constructor delted 

		void operator= (UniquePtr & args ) = delete ;
		
		UniquePtr & operator= (UniquePtr && args ) 
		{
			// this->ptr = args.ptr;
			// args.ptr =nullptr ;
			// the above implementation leaks memory for the ptr 
			/*
			So a memory is assigned with new and then suddenly we are chaging the address of the ptr with other so the memory created by the new is leak is this crt
			As a result, the originally allocated memory becomes unreachable → memory leak.
			*/
			if (this != &args)
		    {
		        delete ptr;          // 🔑 release old resource
		        ptr = args.ptr;
		        args.ptr = nullptr;
		    }
		    return *this;
		}


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
UniquePtr<T> make_uniquee(TT&&... args )
{	
	return UniquePtr<T>(new T(std::forward<TT>(args)...));
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

class Sample1
{
	public:
		int * ptr ;
		Sample1(int number=10) :  ptr(new int[number]) 
		{
			cout<<"@ Sample1 class constructor \n";
		}

		void function()
		{
			cout<<"Sample1 class function \n";
		}

		~Sample1()
		{
			cout<<"@ Sample1 class destructor \n";
		}
		
};


int main()
{
	cout<<"@ Custom Unique Pointer \n";
	// Way 1 of initialization 
	UniquePtr<Sample> sampleObj;
	// UniquePtr<Sample> sampleObj1 = sampleObj; // this is working  // copy constructor deleted

	// Way 2 of initialization  
	UniquePtr<Sample> sampleObj2(new Sample()); // this is working as normal  	 
	
	// make unique 
	UniquePtr<Sample> sampleObj3 = make_uniquee<Sample>();

	// Move constructor 	
	UniquePtr<Sample> sampleObj4(std::move(sampleObj3));	
 
	// copy assignment deletion 
	// UniquePtr<Sample> sampleObj5(sampleObj3);	 // use of deleted function 

	// copy assignment operation deletion 
	UniquePtr<Sample> sampleObj5; 
	// sampleObj5 = sampleObj3;	 // use of deleted function s
	
	// move assignment operator 
	sampleObj5 = std::move(sampleObj3);	 

	// fixing the template handling for the UniquePtr 
	// UniquePtr<Sample1> sampleObj6 = make_uniquee<Sample> ();  // invalid conversion ‘UniquePtr<Sample>’ to non-scalar type ‘UniquePtr<Sample1>’ requested
	UniquePtr<Sample1> sampleObj6;
	UniquePtr<Sample1> sampleObj7;
	// sampleObj6 = std::move(sampleObj3);	 // no match operator = 
	sampleObj6 = std::move(sampleObj7);	 
}