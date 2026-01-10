#include <iostream>
using namespace std;

class Sample final 
{
	public :
		Sample()
		{
			cout<<"@ Sample class constructor \n";
		}

		~Sample()
		{
			cout<<"@ Sample class destructor \n";
		}
};

class Sample1 : Sample // cannot derive from ‘final’ base ‘Sample’ in derived type ‘Sample1’
{
	public :
		Sample1()
		{
			cout<<"@ Sample1 class constructor \n";
		}

		~Sample1()
		{
			cout<<"@ Sample1 class destructor \n";
		}
};


int main()
{
	cout<<"@ final usage in cpp and working \n";

	Sample obj;

}