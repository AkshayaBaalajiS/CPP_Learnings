#include <iostream>
using namespace std;

class Sample
{
	public:
		Sample()
		{
			cout<<"@ Sample class constructor\n";
		}

		~Sample()
		{
			cout<<"@ Sample class destructor\n";
		}
};

int main()
{
	cout<<"This is the code to understand the new working in cpp \n";
	Sample * ptr = (Sample *)malloc(sizeof(Sample));

	free(ptr);
}