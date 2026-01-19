#include <iostream>
using namespace std;

class Exception
{
	public :
		Exception()
		{
			cout<<"Exception class constructor \n";
		}
		
		friend ostream & operator<< (ostream & out, Exception & obj)
		{
			out<<"Exception class obj printed";
			return out;
		} 

		~Exception()
		{
			cout<<"Exception class destructor \n";
		}
};

int main()
{
	cout<<"try catch throw code \n";

	try
	{
		Exception obj;
		throw(obj);
	}
	catch(Exception exp)
	{
		cout<<"Catch called \n";
		cout<<exp <<endl;
	}	
}