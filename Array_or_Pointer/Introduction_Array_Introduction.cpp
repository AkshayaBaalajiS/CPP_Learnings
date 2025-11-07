#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int input;
    cin>>input;
    
    vector<int> vector_i;
    for(int i=0;i<input;i++)
    {
        int temp;
        cin>>temp;
        vector_i.push_back(temp);
    }
    reverse(vector_i.begin(),vector_i.end());
    for(int i : vector_i)
    {
        cout<< i <<  " " ;
    }
    return 0;
}
