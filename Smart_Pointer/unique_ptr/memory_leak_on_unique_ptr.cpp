#include <iostream>
#include <memory>
using namespace std;

class Sample
{
	public :
	int a ;

		Sample()
		{
			cout<<"@Sample class constructor \n";
		}
		~Sample()
		{
			cout<<"@Sample class destructor \n";
		}
		
};

int main()
{
	Sample * ptr = new Sample();
	delete ptr;

	//auto ptr is deprecated after cpp 11
	// auto_ptr<Sample> autoPtr(new Sample());

	// use the unique_ptr 
	// unique_ptr<Sample> up = make_unique<Sample>(); 
	// unique_ptr<Sample[]> up1(new Sample[10]); // internally calls the delete []

	unique_ptr<Sample*> up2(new Sample*[10]);
	//Inside unique_ptr the pointer is stored as:
		// Sample**
	up2.get()[0] = new Sample();

	/*	What unique_ptr Will NOT Delete
	It does not delete the Sample objects pointed to by the pointers.
	delete [] will be called but the pointer the [0][1] wont be called 
	*/
	// to delete manually to avoid mem leak 
	for(int i=0;i<10;i++)
	{
		delete up2.get()[i];
	}

	Sample ** ptr1 = new Sample*[10];
	ptr1[0] = new Sample();
	delete ptr1[0];
	delete [] ptr1;
}