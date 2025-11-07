#include<iostream>
using namespace std ;
int main()
{
    cout<<"This is for practicing the array\n";
    int size_of_Array;
    cin>>size_of_Array;
    int array[size_of_Array];
    int temp;
    for(int i=0;i<size_of_Array ; i++)
    {
        cout<<"Enter the " << i << " element of array \n";
        cin>>temp;
        array[i]=temp;
    }
    cout<<"The array elements are : \n";
    for (int i=0;i<size_of_Array;i++)
    {
        cout<<array[i] << " " ; 

    } 
    cout << "\n";
    // char arr
}