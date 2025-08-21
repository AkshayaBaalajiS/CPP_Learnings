#include<iostream>
using namespace std ;

int main()
{
    int * ptr = new int ;
    
    *ptr = 1232  ;

    cout<< "* ptr =  " << *ptr<<endl;

    // delete ptr; // for deallocating the memory delete is used 
    
    // we are ending the program without deleting / deallocating the memory usign delete   
    return 0;
}