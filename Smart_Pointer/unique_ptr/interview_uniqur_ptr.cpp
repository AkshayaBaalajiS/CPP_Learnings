#include <iostream>
#include <memory>
using namespace std;

template <typename T>
class Sample
{
	T * ptr ;
	public :
	Sample() : ptr(new T[10])
	{
		cout<<"@ Sample class cons\n";
	}

	// deep copy done on copy cons 
	Sample(const Sample & a ): ptr(new T[10])
	{
		cout<<"@ Sample class copy cons\n";

		for(int i=0;i<10;i++)
		{
			ptr[i] = a.ptr[i];
		}
	}
	
	Sample & operator= (const Sample & a)
	{	
		if(this!=&a)
		{
			delete [] ptr; // this is undefined behaviour cause obj = obj if the this!=&a checked 
			ptr =  new T[10];
			for(int i=0;i<10;i++)
			{
				ptr[i] = a.ptr[i];
			}
		}
		return *this;
	}

	Sample(Sample && a ) noexcept // : ptr(new T[10]) // allocate mem and leak 
	{
		cout<<"@ Sample class move cons\n";
		ptr = a.ptr;
		a.ptr = nullptr;
	}

	Sample & operator=(Sample && a ) 
	{	
		if(this != &a)
		{
			delete [] ptr;
			ptr = a.ptr;
			a.ptr = nullptr;
		}
		return *this;
	}

	~Sample()
	{
		delete [] ptr;
		cout<<"@Sample class des\n";
	}
};

void function1( unique_ptr<Sample<float>> ref )
{
	cout<<"@void function1(const unique_ptr<Sample<float>> ref )\n";
}

unique_ptr<Sample<float>> function2(  )
{
	cout<<"@void function2(  )\n";
	return make_unique<Sample<float>>();
}

void function3(Sample<float> * ptr)
{
	cout<<"@void function3(Sample<float> * ptr)\n";
}

int main()
{
	cout<<"Unique ptr program for interview purpose \n";
	// initializations
	//1
	unique_ptr<int> uniPtr;
	//2 
	unique_ptr<Sample<float>> uniPtr1= make_unique<Sample<float>>();
	//3
	unique_ptr<Sample<float>> uniPtr2 (new Sample<float>());
	//4
	Sample<float> * sampleObj = new Sample<float>(); // we are assigning the obj to a pointer exc=pect 
	// Sample<float> sampleObj; // we are assigning the obj to a pointer exc=pect 
	unique_ptr<Sample<float>> uniPtr3 (sampleObj); // this should not be done cause if sampleObj is deleted somewhere it will be the issue 
	unique_ptr<Sample<float>> uniPtr31 (new Sample<float>); // this is prefered 	
	// so in unique_ptr deletion we get || free(): invalid pointer

	// copy and move the unique pointer 
	// unique_ptr<Sample<float> > uniPtr4  = uniPtr3; // use of deleted function 
	unique_ptr<Sample<float> > uniPtr4  = std::move(uniPtr3); // move constructor is there in the unique pot it transfer ownership and free the moved one 

	// passing the uniqur ptr to a function 
	// function1(uniPtr4); // sue of del functoin 
	function1(std::move(uniPtr4)); // sue of del functoin 
	

	// returing a unique_ptr 
	unique_ptr<Sample<float> > uniPtr5 = function2();

	// get address from the unique ptr 
	function3(uniPtr5.get());
}	