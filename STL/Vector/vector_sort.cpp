#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool vector_sort(int a , int b )
{
    if(a>b) // for decending 
    {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n ;
    cin>>n;
    vector<int>temp;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t ;
        temp.push_back(t);
    }
    sort(temp.begin(),temp.end(),vector_sort);
    for(int i: temp)
    {
        cout<< i << " " ;
    }
    return 0;
}

