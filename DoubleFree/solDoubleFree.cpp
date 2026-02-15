#include <iostream>
using namespace std;

int sze =10;

class Sample
{
	public:
		int * ptr ;
		int **pptr;
		Sample() : ptr(nullptr), pptr(nullptr)
		{
			cout<<"Sample class constructor\n";
		}
		Sample(int * p, int **p1) : ptr(p), pptr(p1)
		{
			cout<<"Sample class constructor\n";
		}
		Sample(const Sample & ref) : ptr(new int[sze]), pptr(new int*[sze])
		{
			for(int i=0;i<sze;i++)
			{
				ptr[i] = ref.ptr[i];
				pptr[i] = ref.pptr[i];
			}
		}
		Sample& operator=(const Sample & ref) // check the signature 
		{
			if(this!=&ref)
			{
				// deletion of existing mem
				delete [] ptr;
				delete [] pptr;
				
				for(int i=0;i<sze;i++)
				{
					ptr[i] = ref.ptr[i];
					pptr[i] = ref.pptr[i];
				}
			}
			return *this;
		}
		Sample(Sample && ref) noexcept: ptr(new int[sze]), pptr(new int*[sze])  
		{
			for(int i=0;i<sze;i++)
			{
				ptr[i] = ref.ptr[i];
				pptr[i] = ref.pptr[i];
			}
			ref.ptr = nullptr;
			ref.pptr = nullptr;
		}
		Sample& operator=( Sample && ref) noexcept
		{
			if(this!=&ref)
			{
				
				delete [] ptr;
				delete [] pptr;
				for(int i=0;i<sze;i++)
				{
					ptr[i] = ref.ptr[i];
					pptr[i] = ref.pptr[i];
				}
			}
			ref.ptr = nullptr;
			ref.pptr = nullptr;
			return *this;
		}
		~Sample()
		{
			delete [] ptr;
			delete [] pptr;
			cout<<"Sample class destructor\n";
		}
};

int main()
{
	cout<<"This is the code to understand the doubleFree / double Deletion in cpp \n";
	{
		Sample obj;
	}

	{
		Sample obj(new int[sze], new int*[sze]);
	}
	{
		Sample obj(new int[sze], new int*[sze]);
		Sample obj1(obj); // copy cons double deletiojn here 
	}
}