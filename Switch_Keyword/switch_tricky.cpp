#include<iostream>
using namespace std;
int main()
{
    int arr[]={10,20,30,40,50,60,70,80,90,100};
    int * ptr;
    ptr =arr;
    cout<<"*ptr+1  = " << *ptr+1 <<endl;
    // switch can have the expression 
    switch(*ptr+1) // * ptr + 1  is 11
    {
        case 11 :
            cout<<"11 " << endl ;
            break;
        case 20 :
            cout<<"20 " << endl ;
            break;
        case 10: 
            cout<<"10 " << endl ;
            break;
        default:
            cout<<"Nothing\n";
            break;
    }
}