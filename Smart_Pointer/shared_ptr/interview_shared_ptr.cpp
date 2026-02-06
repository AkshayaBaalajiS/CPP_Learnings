#include<iostream>
#include <vector>
#include <memory>
using namespace std;

class Sample
{
	public :
	std::vector<int> vectt;
		Sample()
		{
			vectt.resize(10);
			vectt ={12,23,34,45,65};
			cout<<"@Sample class cons \n";
		}
		// des should not be there in rule 0 class 
		// ~Sample()
		// {
		// 	cout<<"@Sample class desc \n";
		// }
};

int main()
{
	cout<<"@ Shared pointer prgram\n";
	shared_ptr<Sample> sharePoint = make_shared<Sample>();
	cout<<"count = " << sharePoint.use_count() <<endl;

	shared_ptr<Sample> sharePoint1 = sharePoint;
	cout<<"count = " << sharePoint.use_count() <<endl;

	shared_ptr<Sample> sharePoint2 = sharePoint1;
	cout<<"count = " << sharePoint.use_count() <<endl;
	cout<<"sharePoint1 count = " << sharePoint1.use_count() <<endl;
	cout<<"Vect values before rest " << sharePoint->vectt[0] << " " << sharePoint->vectt[1] << " " << sharePoint->vectt[2] << " " << sharePoint->vectt[3] << " " <<endl;

	
	sharePoint.reset();
	cout<<"count after reset = " << sharePoint.use_count() <<endl; // reset will amke it as NULL 
	cout<<"sharePoint1 count = " << sharePoint1.use_count() <<endl;
	cout<<"Vect values after rest of main the chile hold " << sharePoint1->vectt[0] << " " << sharePoint1->vectt[1] << " " << sharePoint1->vectt[2] << " " << sharePoint1->vectt[3] << " " <<endl;

	// due to reset it become null and null dereference is seg fault 
	// cout<<"Vect values after rest " << sharePoint->vectt[0] << " " << sharePoint->vectt[1] << " " << sharePoint->vectt[2] << " " << sharePoint->vectt[3] << " " <<endl;

	// way of inita
	shared_ptr<Sample> sharedPtr (new Sample());

	shared_ptr<Sample> sharedPtr1 =  make_shared<Sample>();

		
}