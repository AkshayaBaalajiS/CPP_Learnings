#include<iostream>
using namespace std;

int main()
{
    cout<<"This program is to understand how the const on pointer works .....\n ";
    int * iptr ;
    *iptr = 100 ;
    
    int * iptr_1;
    *iptr_1 = 1234;

    // in the below const pointyer the value cant be changed but the address can be changed 
    const int * ciptr = iptr;
    cout<<"Before changing .... \n";
    cout<<"*iptr : " << *iptr<<endl;
    cout<<"*iptr_1 : " << *iptr_1<<endl;
    cout<<"*ciptr : " << *ciptr<<endl;

    // value cant be changed when const is on first 
    //*ciptr=123; 
    
    // But the address can be changed when const is on first 
    ciptr= iptr_1;

    cout<<"After changing .... \n";
    cout<<"*iptr : " << *iptr<<endl;
    cout<<"*iptr_1 : " << *iptr_1<<endl;
    cout<<"*ciptr : " << *ciptr<<endl;

    cout<<"------------------------------------------------------------------\n";
    // in the below const pointer the value can be changed and the address cant be changed 
    int  * const  ciptr_1 = iptr;

    cout<<"Before changing .... \n";
    cout<<"*iptr : " << *iptr<<endl;
    cout<<"*iptr_1 : " << *iptr_1<<endl;
    cout<<"*ciptr : " << *ciptr<<endl;
    cout<<"*ciptr_1 : " << *ciptr_1<<endl;

    *ciptr_1 = 456457;
    // ciptr_1=iptr_1;

    cout<<"After  changing .... \n";
    cout<<"*iptr : " << *iptr<<endl;
    cout<<"*iptr_1 : " << *iptr_1<<endl;
    cout<<"*ciptr : " << *ciptr<<endl;
    cout<<"*ciptr_1 : " << *ciptr_1<<endl;
        
    
}