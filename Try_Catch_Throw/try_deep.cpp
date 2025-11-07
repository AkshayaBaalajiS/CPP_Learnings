#include<iostream>
using namespace std;

void function_to_do_something()
{

    // throw runtime_error("Simple throw from a function call "); // this will be caught by the first catch 
    // throw(10); // this will be caught by the second catch stmt 
    throw('c'); // this will caught in the last catch           king catch 

}
int main()
{
    cout<<"This is the program to understand the try to the deep..\n";
    try
    {
        function_to_do_something();
        throw("This is a local throw from main function");
    }
    catch(exception & e)
    {
        cout<<"The Error occured is : " << e.what() <<"\n";
    }
    catch(int error_number)
    {
        cout<<"The Error occured at: " << error_number <<"\n";
    }
    catch(...) // this is king of all catch this will catch any type of error which is not get caught on prev catch 
    {
        cout<<"This is king of all exception will catch all type of exception\n";
    }

}