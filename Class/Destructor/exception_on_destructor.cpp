#include <iostream>
using namespace std;

class Sample
{
	public :
		Sample()
		{
			cout<<"SAmple class constructor\n";
		}
		~Sample()
		{
			cout<<"@ SAmple class destructor \n";
			throw std::runtime_error("Destructor failed");
		}
};	

int main()
{
	cout<<" Exception throw on destructor \n";
	Sample obj;
}