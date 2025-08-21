#include<iostream>
#include<vector>
using namespace std;

int main()
{
    cout<<"This is the program to understand the iterator in c++ \n";

    int arr[]={1,2,3,4,5,6,7,8,9};
    // int arr[](12,3,4,5,5); 
    int size(sizeof(arr)/sizeof(arr[0])); // this type of initialization is only possible for the non array type 

    auto it = arr ;

    for(int i=0;i<size;i++)
    {
        cout<<"*it  = " << *it << endl;
        it=it+1;
    }

    vector<int> ivec ={1,2,3,4,5,6,7,8,9};

    auto itt = ivec.begin();
    vector<int>::iterator ittt  = ivec.begin(); // this can be done like this also 
    cout<<"\nVector iterator starts from here \n";
    for(int i=0;i<size;i++)
    {
        cout<<*itt<< "  ";
        itt++;
    }

    cout<<"\nAnother way of iterating vector \n";

    vector<int>::iterator iterateVec ;
    for(iterateVec=ivec.begin();iterateVec!=ivec.end();iterateVec=iterateVec+1)
    {
        cout<<*iterateVec<<"  "; 
    }
    cout<<endl;


}