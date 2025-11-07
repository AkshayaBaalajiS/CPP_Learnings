#include "SomeClass.h"

int main()
{  
    cout<<"This is the program to understand the types of exceptions\n ";

    #ifdef SOME_CLASS
    
    SomeClass object;
    try
    {
        cout<<"Came inside thr try block \n";
        cout<<"Enter two values  : " ;
        int a, b;
        cin>>a>>b;
        object.someFunction(a,b);
        cout<<"Came out of the function \n";
    }
    catch(exception & e )
    {
        cerr<<"The exception raised is : " << e.what();
    }
#else
    cout<<"This is the program to practice the try catch the header is not defined please add header to see how the try catch works \n";
#endif
}