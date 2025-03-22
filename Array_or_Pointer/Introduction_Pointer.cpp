#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void function_to_do(int *a, int *b )
{
    int temp = *a;
    *a=*a+*b;
    if(temp>*b)
    {
        *b=temp-*b;
    }
    else
    {
        *b=*b-temp;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int a;
    int b;
    cin>>a>>b;
    
    function_to_do(&a, &b);
    
    cout<<a<<"\n"<<b;
    
    
    return 0;
}
