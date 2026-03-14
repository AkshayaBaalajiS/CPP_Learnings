#include <iostream>
#include <memory>
using namespace std;

class Sample
{
	public :
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
	unique_ptr<Sample> up = make_unique<Sample>(); 
	

}