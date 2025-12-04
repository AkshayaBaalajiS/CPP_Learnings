#include <iostream>
using namespace std;

void callback_function(int * ptr, char * ptr1)
{
	cout<<"@void callback_function(int * ptr, char * ptr1)\n";
}

void  function(void (*function_callback) (int *, char *))
{
	cout<<"@ void  function(void (*function_callback) (int *, float *))\n";
	int * ptr = new int;
	char * ptr1 = new char [10];
	function_callback(ptr, ptr1); 
}

int main()
{
	cout<<"This is program to understadn the function pointer and callback\n";

	void (*function_callback) (int *, char *) =  callback_function;

	function(function_callback);

}