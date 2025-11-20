#include <iostream>

using namespace std;

template <typename T, typename... TT>
class Sample
{
	public :
		Sample()
		{

		}
		Sample(int, int, float, string, double, char)
		{	
			cout<<"Sample(int, int, float, string, double, char)\n";
			cout<<"This constuctor is called but thhis is useless cause no arg name \n";
		}
		Sample(TT&&... args)
		{
			cout<<"Sample class constructor \n";
		}

		~Sample()
		{
			cout<<"@ Sample class destructor \n";
		}
};

int main()
{
	cout<<"Variable template on a class \n";
	Sample <int, int , float, string, double, char> obj(12,23,34.23f, "Akshaya Baalaji S", 45.4554, '2');

}