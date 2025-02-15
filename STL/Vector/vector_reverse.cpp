#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


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
    reverse(temp.begin(),temp.end());
    for(int i: temp)
    {
        cout<< i << " " ;
    }
    return 0;
}

