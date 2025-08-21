#include <iostream>
#include "problem.h"
int main()
{
    cout<<"This is the program to understand the vector addition, substraction, division, multiplication \n";
    
    Problem obj ;
    
    cout<<"Enter the size of the vector \n";
    int sis;
    cin>>sis;
    obj.vec_int.resize(sis);
    
    for(int i=0;i<sis;i++)
    {
        int tmep;
        cin>>tmep;
        obj.vec_int[i] = sis;
    }
    
    cout<<"Enter the size of the vector 2\n";
    cin>>sis;
    vector<int> vec_int_1;
    vec_int_1.resize(sis);
    
    for(int i=0;i<sis;i++)
    {
        int tmep;
        cin>>tmep;
        vec_int_1[i] = sis;
    }
    
    vector<int> result_t = obj.vec_int + vec_int_1;
 
}