/*
When you mark a constructor as explicit, it prevents implicit conversions and copy-initialization. This means you can't use the constructor in a way that allows the compiler to automatically convert types or initialize objects without an explicit call.

To call the constructor explicitly, you simply use the normal constructor syntax. However, if you want to see how implicit calls would work without the explicit keyword, you can remove it and then try the following examples:

Implicit Conversion (without explicit):

sampleClass_A obj = {12, 45}; // This would work without `explicit`
Copy Initialization (without explicit):

sampleClass_A obj = sampleClass_A(12, 45); // This would work without `explicit`


*/

#include<iostream>
using namespace std;

class sampleClass_A
{
    public :
        sampleClass_A()
        {
            cout<<"sampleCLass_A constructor \n";
        }
        sampleClass_A(int a=0 , int b=0)
        {
            cout<<"PArameterized constructor \n";
        }
        
};

class sampleClass_A_B
{
    public :
        explicit sampleClass_A_B()
        {
            cout<<"sampleCLass_A_B constructor \n";
        }
        explicit sampleClass_A_B(int a=0 , int b=0)
        {
            cout<<"PArameterized constructor \n";
        }
        
};

int main()
{
    // normal way 
    sampleClass_A obj(12,45);

    // implicity way  
    sampleClass_A obj_1 = {34,45};

    // copyu constructor which is written by the c++
    sampleClass_A obj_2 = obj_1 ;

    cout<< "+++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";

    //way 1 
    sampleClass_A_B object(45,65);

    //way 2
    // sampleClass_A_B object_1 = {12,45}; // this cant be done 

    // way 3 
    // sampleClass_A_B object_2 =object ; // this also cant be done s

    
}
