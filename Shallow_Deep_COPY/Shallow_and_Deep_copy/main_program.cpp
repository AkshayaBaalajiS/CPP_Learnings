#include "SampleClass.h"

int main()
{
    cout<<"This is the main program to show the deep copy of the class ";
    int a = 10 ;
    int b = 12 ;
    int * ptr = &a;
    int * ptr_1 = &b;

    int aa = 20 ;
    int bb = 34 ;
    int * ptr_3 = &aa;
    int * ptr_4 = &bb;

    
#ifdef SAMPLE_CLASS
    Sample obj = {10,12.232f,'a',3545.23234 , ptr,ptr_1}; // for tihs kind of initialization the class needs a similar type of constructor 
    Sample obj_1 = {20, 20.20f, 'b', 4545.23232, ptr_3, ptr_4};

    Sample obj_2 = obj_1;

    cout<<"|-----------------------------------------------------------|\n";
    obj.printValues();
    cout<<"|-----------------------------------------------------------|\n";
    obj_1.printValues();
    cout<<"|-----------------------------------------------------------|\n";
    obj_2.printValues();
    cout<<"|-----------------------------------------------------------|\n";
    obj_2.setValues(45, 45.45f, 'c', 435.5656, 98 , 934);
    cout<<"After the set Values the object 1 and 2 holds \n";
    cout<<"|-----------------------------------------------------------|\n";
    obj_2.printValues();
    cout<<"|-----------------------------------------------------------|\n";
    obj_1.printValues(); // the shallow copy data will be same as the obj_2 and the deep copy wont change 
    cout<<"|-----------------------------------------------------------|\n";

#else
    cout<<"\nClass not defined \n";
#endif
}