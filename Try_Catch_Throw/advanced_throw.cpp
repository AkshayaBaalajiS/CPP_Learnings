#include<iostream>
using namespace std;



void some_function()
{
    if(1)
    {
        throw ("Some exception");
    }
    
}

int main()
{
    try
    {
        if(0)
        {
            throw runtime_error("Some thing \n");
        }
        some_function();

    }
    // catch(const char * e)
    // // catch(std::runtime_error & e)
    // {
    //     cerr<<"This is the error  : " << e<<endl;
    // }
    catch(std::exception & e)
    // catch(std::runtime_error & e)
    {
        cerr<<"This is the error  : " << e.what()<<endl;
    }
}