#include <iostream>
using namespace std ;

int main()
{
    cout<<"The program is to understand the array of pointer ..\n";
    int size;
    cout<<"Enter size of the array : ";
    cin>>size ;
    cout<<"\n";

    int *ptr[size];
    int temp_variable;
    for(int i=0; i<size; i++)
    {
        ptr[i] = new int ;
        cout<<"Enter the value : " ;
        cin>>temp_variable;
        *(ptr[i])=temp_variable;   
    }

    for(int i=0; i<size; i++)
    {
        cout<<"*ptr["<<i<<"] = " << *ptr[i] << "   ";

    }
    cout<<"\n";
    

} 