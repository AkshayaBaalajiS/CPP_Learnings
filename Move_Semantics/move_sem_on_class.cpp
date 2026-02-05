#include <iostream>
using namespace std;

class Sample
{	
public:
	Sample()
	{
		cout<<"@Sample class cons\n";
	}

	~Sample()
	{
		cout<<"@Sample class desc\n";
	}
};	

int main()
{	
	Sample obj;
	Sample obj1 = std::move(obj);
}