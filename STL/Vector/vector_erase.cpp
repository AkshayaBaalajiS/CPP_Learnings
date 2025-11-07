// #include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"This is the program to understadn the vector erase operation \n";

    vector<int> vec ;
    vec={1,2,3,4,5,6,7,8,9};

    for(int i: vec)
    {
        cout<< i << "   " ;
    }
    cout<<endl;

    vec.erase(vec.begin());
    cout<<"vec.erase(vec.begin())   : ";
    for(int i: vec)
    {
        cout<< i << "   " ;
    }
    cout<<endl;


    // vec.erase(vec.end()); // this will make the core dumped because there is no value at that index  
    
    // vec.erase(2); // proof that the erase will git only pointer 

    // another proof thta the erase will only take pointer 
    vector<int>::iterator iterVec = vec.begin()+2;  // 0 1 2   --- 2 
    vec.erase(iterVec);
    cout<<"vec.erase(2)   : ";
    for(int i: vec)
    {
        cout<< i << "   " ;
    }
    cout<<endl;

    
}