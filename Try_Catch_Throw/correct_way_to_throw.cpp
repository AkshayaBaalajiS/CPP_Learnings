#include <iostream>
using namespace std;

int main()
{
    cout<<"This is the code to show the proper throw \n";

    int val =19;
    int rem = 0 ;

    try{
        if(rem==0)
        {
            throw runtime_error("Zero Division try ");
        }
    }
    // catch(exception e ) // if we do this we will get the std::exception itself so do & 
    catch(exception & e )
    {
        cerr << "This is the error  : " << e.what()<<endl;
    }
}