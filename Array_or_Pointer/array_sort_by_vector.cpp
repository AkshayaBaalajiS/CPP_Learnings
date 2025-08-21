#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

bool func(int a , int b)
{
    if(a<b)
    {
        return true;
    }
    else {
        return false;
    }
}

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
    vector<int> vector_i ;
    for(int i=0;i<size;i++)
    {
        vector_i.push_back(arr[i]);
    }
    sort(vector_i.begin(),vector_i.end(),func);
    for(int i=0;i<size;i++)
    {
        arr[i]=vector_i[i];
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