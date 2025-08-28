#include <iostream>
#include <memory>
using namespace std;

namespace NewNameSpace
{
	class Sample 
	{
		public:
			Sample()
			{
				cout<<"Sample class constructor \n";
			}

			friend ostream & operator << (ostream & ref, NewNameSpace::Sample & reff)
			{
				ref << "Sample class instance \n";
				return ref;
			}

			~Sample()
			{
				cout<<"Sample class destructor \n";
			}
	};	
}

int main()
{
	cout<<"Unique, Shared, Weak pointer in Smart Pointer \n";
	
	// unique_ptr 
	cout<<"---------------------------------------------------\n";
	unique_ptr <NewNameSpace::Sample> unique_ptr_1 = make_unique<NewNameSpace::Sample>();
	unique_ptr <NewNameSpace::Sample> unique_ptr_2(new NewNameSpace::Sample());
	NewNameSpace::Sample * samplePtr = new NewNameSpace::Sample();
	unique_ptr <NewNameSpace::Sample> unique_ptr_3(samplePtr);
	cout<<"---------------------------------------------------\n";

	cout<<"===================================================\n";
	// shared_ptr
	shared_ptr <NewNameSpace::Sample> shared_ptr_1 = make_shared<NewNameSpace::Sample>();
	shared_ptr <NewNameSpace::Sample> shared_ptr_2(new NewNameSpace::Sample());
	NewNameSpace::Sample * samplePtr_2 = new NewNameSpace::Sample();
	shared_ptr <NewNameSpace::Sample> shared_ptr_3(samplePtr_2);
	shared_ptr <NewNameSpace::Sample> shared_ptr_4 = shared_ptr_3;
	shared_ptr <NewNameSpace::Sample> shared_ptr_5 = shared_ptr_4;
	cout<<"Shared pointer shared count " << shared_ptr_3.use_count() <<endl;
	shared_ptr_3.reset();
	cout<<"Shared pointer shared count after reset " << shared_ptr_3.use_count() <<endl;
	cout<<"===================================================\n";

	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	// weak_ptr
	weak_ptr <NewNameSpace::Sample> weak_ptr_1 = shared_ptr_1;
	if(!weak_ptr_1.expired())
	{
		cout<<*(weak_ptr_1.lock())<<endl;
	}
	// weak_ptr <NewNameSpace::Sample> weak_ptr_2(new NewNameSpace::Sample());
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	
}