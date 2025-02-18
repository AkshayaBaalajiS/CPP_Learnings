#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    cout<<"This is the program to Sort array \n";
    int arr [] ={1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9};

    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<"The initial array is : ";
    for(int i=0;i<size;i++)
    {
        cout<<arr[i] << "   " ;

    } 
    cout<<endl;
    
    for(int i=0;i<size-1;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(arr[i]>arr[j])
            {
                int tmep = arr[i];
                arr[i]=arr[j];
                arr[j]=tmep;
            }
        }
    }

    cout<<"\n\nThe Array after sort is : ";
    for(int i=0;i<size;i++)
    {
        cout<<arr[i] << "   " ;
    } 
    cout<<endl;
    // testing  : 
    // const char *  name = "Akshaya Baalaji Senthilraj ";
    // cout<<"Size of name : "<<strlen(name);
}