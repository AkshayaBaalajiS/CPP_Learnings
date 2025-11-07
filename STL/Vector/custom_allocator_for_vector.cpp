#include <iostream>
#include <vector> 
#include <memory> // for allocator usage 
using namespace std;

template <typename T>
class CustomAllocator : public allocator<T>
{
	public:
		CustomAllocator()
		{
			cout<<"@ CustomAllocator constructor \n";
		}

		T * allocate(size_t size)
		{
			cout<<"@ allocate for allocating "<< size << " objects  \n";
			return std::allocator<T>::allocate(size);
		}

		void deallocate(T *p, size_t size)
		{
			cout<<"@ deallocate for deallocating "<< size << " objects  \n";
			std::allocator<T>::deallocate(p,size);
		}

		~CustomAllocator()
		{
			cout<<"@ CustomAllocator destructor \n";
		}
};

int main()
{
	cout<<"This is the program for custom allocator of vector in C++\n"; 

	vector<int, CustomAllocator<int>> vector_i;
		
	cout<<"----------------------\n";
	vector_i.push_back(12);
	cout<<"----------------------\n\n";

	cout<<"----------------------\n";
	vector_i.push_back(12);
	vector_i.push_back(12);
	cout<<"----------------------\n\n";

	cout<<"----------------------\n";
	vector_i.push_back(12);
	vector_i.push_back(12);
	vector_i.push_back(12);
	cout<<"----------------------\n\n";
	
	cout<<"----------------------\n";
	vector_i.push_back(12);
	vector_i.push_back(12);
	vector_i.push_back(12);
	vector_i.push_back(12);
	cout<<"----------------------\n\n";
	
}