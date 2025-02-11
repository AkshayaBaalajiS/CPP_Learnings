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
    

    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n";
    cout<<"Const understanding ...\n";
    const int * cPtr ;
    cPtr = &iVar ;
    cout<<"The cPtr  = " << cPtr <<endl;
    cout<<"The *cPtr  = " << *cPtr <<endl;
    cout<<"The iVar  = " << iVar<<endl;


    int  * const ptrC  = cast_ptr;
    cout<<"The ptrC  = " << ptrC <<endl;
    cout<<"The *ptrC  = " << *ptrC <<endl;
    cout<<"The iVar  = " << iVar<<endl;

    cout<<"+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n";

    cout<<"Using the const placement on the pointer \n ";
    int iVar_2=12;
    cPtr = &iVar_2 ;
    // *cPtr = 1234; // this cant be done because of the placement of the pointer 
    
    cout<<"The cPtr  = " << cPtr <<endl;
    cout<<"The *cPtr  = " << *cPtr <<endl;
    cout<<"The iVar  = " << iVar<<endl;
    cout<<"The iVar_2  = " << iVar<<endl;

    *ptrC =45;
    // ptrC = &sample_ptr; // this cant be done because of the placement of pointer 
    cout<<"The ptrC  = " << ptrC <<endl;
    cout<<"The *ptrC  = " << *ptrC <<endl;
    cout<<"The iVar  = " << iVar<<endl;
    cout<<"The iVar_2  = " << iVar<<endl;    

    


}