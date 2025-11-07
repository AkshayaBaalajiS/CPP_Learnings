#include<iostream>
using namespace std;

int main()
{
    cout<<"This is the code to understand the const cast in C++\n";
    const int iVar=10;

    int iVar_1=56;
    
    int * sample_ptr ;
    sample_ptr = &iVar_1;


    const int * ptr ;
    ptr= &iVar;
    cout<<"The iVar  = " << iVar<<endl;
    cout<<"The *ptr = " << *ptr <<endl; 
    cout<<"The *sample_ptr = " << *sample_ptr <<endl; 
    cout<<"The &sample_ptr = " << *sample_ptr <<endl; 

    int * cast_ptr = const_cast<int *>(ptr);
    cout<<"The *cast_ptr = " << *ptr <<endl; 
    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n";
    cout<<"Changing the value to 20 NOW the values of the variable are :\n";
    *cast_ptr=20;
    
    cout<<"The iVar  = " << iVar<<endl;
    cout<<"The *ptr = " << *ptr <<endl; 
    cout<<"The *cast_ptr = " << *ptr <<endl; 
    


}