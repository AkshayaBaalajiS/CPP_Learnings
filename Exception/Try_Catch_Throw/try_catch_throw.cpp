#include <iostream>
// #include <memory>
#include <cstring>
using namespace std;

namespace common
{
	// Custom exception class
	class Exception : public std::exception
	{
		char * error_data ;
		public :
			Exception(char * errormes ) : error_data(new char[100])
			{
				cout<<"@ Exception class constructor \n";
				memcpy(error_data, errormes , strlen(errormes));
			}

			const char * what() const noexcept override
			{
				return error_data;
			}

			~Exception()
			{
				cout<<"@ Exception class destructor \n";
			}
	};
}

int main()
{
	cout<<"This is the program to understand the try catch throw in cpp \n";
	int number =0 ;
	int ac = 32;
	try
	{
		if(number>0)
		{
			cout<<"Some operation\n";
		}
		else
		{
			char * ptr = new char [100];
			strcpy(ptr,"Number less than 0");
			// cout<<ptr;
			throw (new common::Exception(ptr));
			delete ptr;
		}
	}
	catch(const common::Exception * ptr)
	{
		cout<<"Error captured : " <<ptr->what();
	}
	catch(...)
	{
		cout<<"All kind of Exception caught here \n";
	}
}