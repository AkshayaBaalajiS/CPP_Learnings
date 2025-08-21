#include<iostream>
using namespace std;
#define ARRAY_SIZE (8)
int main()
{
    cout<<"This is the program to understadn the reintrepret class \n";

    int array[]={1,2,3,4,5,6,7,8};
    int * ptr = array ; 
    cout<<"Interger array = ";
    for(int i=0;i<ARRAY_SIZE;i++)
    {
        cout<<ptr[i]<<" ";
    }
    cout<<endl;

    float * ptr_1 = reinterpret_cast<float *>(ptr);
    cout<<"Float array = ";
    for(int i=0;i<ARRAY_SIZE;i++)
    {
        cout<<ptr[i]<<" ";
    }
    cout<<endl;
    
}