#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
class Vector
{
	public:
		// static T * ptr ;
		T * ptr ;
		int count ;
		int size;
		Vector() : count(0), size(0), ptr(nullptr)
		{

		}

		void push_back(T ele)
		{
			cout<<"void push_back(T ele) \n";
			T * cpyPtr  = new T[size+1];
			if(ptr!=nullptr)
			{
				// memcpy(cpyPtr, ptr, sizeof(4*size)); // sizeof(...), the expression 4 * size is evaluated as an int, not as bytes.
				memcpy(cpyPtr, ptr, size * sizeof(T));
			}
			ptr =  new T[size+1];
			for(int i=0;i<size;i++)
			{
				ptr[i] = cpyPtr[i];
			}
			ptr[size]=ele;
			size+=1;
		}
		void print()
		{
			cout<<"void print()\n";
			for(int i=0;i<size;i++)
			{
				cout<<ptr[i] << "  " ;
			}
			cout<<endl;	
		}
		void pop_back()
		{
			cout<<"void pop_back()\n";
			ptr[size] = 0;
			size--;
		}

		void resize(int resize)
		{
			cout<<"void resize(int size)\n";
			if(resize>size)
			{
				for(int i=size;i<resize;i++)
				{
					ptr[i]=0;
				}
			}
			size = resize;
		}
};
// if ptr is static 
// template <typename T>
// T * Vector<T>::ptr = nullptr;
int main()
{	
	Vector<int> vector_imp;
	vector_imp.push_back(12);
	
	vector_imp.print();

	vector_imp.push_back(23);
	vector_imp.print();

	vector_imp.push_back(34);
	vector_imp.print();
	
	vector_imp.push_back(45);
	vector_imp.print();
	
	vector_imp.push_back(56);
	vector_imp.push_back(67);
	vector_imp.print();


	vector_imp.pop_back();
	vector_imp.print();


	vector_imp.resize(4);
	vector_imp.print();


	vector_imp.resize(10);
	vector_imp.print();

}