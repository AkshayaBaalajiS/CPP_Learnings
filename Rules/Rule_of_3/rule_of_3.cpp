#include <iostream>
using namespace std;

class Sample
{	
	int * ptr ;
	float * fptr;
	public :
		Sample() : ptr(new int [10]), fptr(new float[10])
		{
			cout<<"@Sample class constructor \n";
		}

		// the below is move behaviour not copy 
		// Sample(const Sample& a)
		// {
		// 	this->ptr = a.ptr;
		// 	this->fptr = a.fptr;
		// 	a.ptr = nullptr ;
		// 	a.fptr = nullptr;
		// }
		// Sample & operator = (const Sample & a)
		// {
		// 	this->ptr = a.ptr;
		// 	this->fptr = a.fptr;
		// 	a.ptr = nullptr ;
		// 	a.fptr = nullptr;
		// 	return *this;
		// }

		Sample(const Sample& a)
		{
			this->ptr = new int[10];
			this->fptr = new float[10];
			for(int i=0;i<10;i++)
			{
				this->ptr[i]= a.ptr[i];
				this->fptr[i]= a.fptr[i];
			}	
		}
		Sample & operator = (const Sample & a)
		{
			if(this!=&a)
			{
				this->ptr = new int[10];
				this->fptr = new float[10];
				for(int i=0;i<10;i++)
				{
					this->ptr[i]= a.ptr[i];
					this->fptr[i]= a.fptr[i];
				}
			}
			return *this;
		}

		~Sample()
		{
			cout<<"@Sample class destructor \n";
			delete [] ptr;
			delete [] fptr;
		}
};

int main()
{
	cout<<"Rule of 3 \n";
	Sample obj;
	// Sample obj2 = obj;  // here double deletion occur cause we are doing the deletioon and copy and copy assignment opertor not trhere 
	Sample obj3 ;
	Sample obj4  = obj3;
	Sample obj5 ;
	obj5  = obj4;
	// obj3  = obj; // here double deletion occur cause we are doing the deletioon and copy and copy assignment opertor not trhere 

}