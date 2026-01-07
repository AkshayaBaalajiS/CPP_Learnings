#include <iostream>
#include <memory>
#include <sstream>

using namespace std;

namespace Common
{
	class Sample 
	{
		public :
			Sample()
			{
				cout<<"Sample class constructor \n";
			}

			ostream & function()
			{
				cout<<"@ Sample class function \n";
				return cout;
			}

			string function1()
			{	
				std::ostringstream oss;
				oss<<"@ Sample class function1 \n";
				return oss.str();
			}

			~Sample()
			{
				cout<<"Sample class constructor \n";
			}
	};
}

int main()
{
	cout<<" unique pointer in cpp \n";
	unique_ptr<Common::Sample> uniquePtr ;
	shared_ptr<Common::Sample> sharedPtr ;
	// ostream ref = uniquePtr->function(); // use of deleted function 
	// ostream ref (uniquePtr->function()); // use of deleted function 
	/* cause 
		basic_ostream(const basic_ostream&) = delete;
		basic_ostream& operator=(const basic_ostream&) = delete; 
		So any attempt to copy or construct an ostream from another stream is illegal.
	*/
	
	// ostringstream oss = uniquePtr->function().rdbuf();
	// string output = oss.str();


	cout<<"Count = " <<  uniquePtr->function1() << endl;
	// cout<<"Count = " <<  uniquePtr->use_count() << endl; // unique ptr has no member named use_count 
	// cout<<"Use Count = " <<  uniquePtr1.use_count() << endl; // shared_ptr has this 

	// Ways of initialization of unique ptr
	unique_ptr<Common::Sample> uniquePtr2; // way 1 
	unique_ptr<Common::Sample> uniquePtr3 (new Common::Sample()); // way 2 
	unique_ptr<Common::Sample> uniquePtr4 = make_unique<Common::Sample>(); // way 3 

	// assignment 
	unique_ptr<Common::Sample> uniquePtr5 ;
	// uniquePtr5 = make_unique<Common::Sample>(new Common::Sample()); // this cant be done cause copy assignmen is not permitted 
	uniquePtr5 = std::move(uniquePtr2); // this cant be done cause copy assignmen is not permitted 
	uniquePtr5 = std::move(uniquePtr2); // this cant be done cause copy assignmen is not permitted 

	cout<<"Function Return " << uniquePtr2->function1();
	/*
	Using uniquePtr2->... is undefined behavior.
	If your program appears to work, it is accidental, not guaranteed.
	*/
	cout<<"Function Return " << uniquePtr5->function1();

	// getting the address 
	cout<<"Address  = " << uniquePtr5.get() <<endl;
	cout<<"Address  = " << uniquePtr4.get() <<endl;
	cout<<"Address  = " << uniquePtr3.get() <<endl;
}