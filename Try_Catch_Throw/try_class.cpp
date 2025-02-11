#include<iostream>
using namespace std;

class Error
{
    public:
        int error_number;
        Error() : error_number(0)
        {
            cout<<"Error Constructor is called ..\n";
        }
        void error_occured()
        {
            ++error_number;
        }

        void handle()
        {
            cout<<"The error number is : " << error_number<<"\n"; 
        }        

        ~Error()
        {
            cout<<"Error class Destructor Called ..\n";
        }

};

void function_to_do_something()
{
    Error object;
    object.error_occured();
    throw(object);
}
int main()
{
    cout<<"This is the program to try the Error Class ..\n";

    try 
    {
        function_to_do_something();
    }
    catch(Error & obj)
    {
        obj.handle();
    }
}