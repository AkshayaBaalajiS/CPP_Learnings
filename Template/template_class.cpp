#include <iostream>
using namespace std;

template <typename T>
class Sample
{
	public :
		Sample()
		{
			cout<<"Sample template class in C++\n";
		}

		T * ptr ;
		
		~Sample()
		{
			cout<<"Sample template class in C++\n";
		}
};	

int main()
{
	cout<<"This is the program to understand the template class \n";

	Sample<int> * samplePtr = new Sample<int>();

	samplePtr->ptr = new int [234];

}