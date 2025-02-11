#include<iostream>
using namespace std ;

// Global variable 
float pi =3.14 ;
int main()
{
    // local variable 
    float pi=4.14 ;
    cout<< "The local pi value is : " << pi << " \n";
    cout<< " the address of the local pi : " << &pi << "\n"; 

    {
        extern float pi ;
        cout<< "\n--------------------------------\n";
        cout<< "The global pi value is : " << pi << " \n";   
        cout<< "The address of the global pi : " << &pi << "\n"; 
    }
    // the below cant be doneas there is a previous declaration of float pi 
    // extern float pi; 
    // cout<< "The pi value is : " << pi << " \n";
    
    
    {
        // changing the globlal variable value 
        extern float pi ;
        pi = 33.14;
    }

    pi = 23.14;


    {
        // printing the global variable value 
        extern float pi ;
        cout<< "\n--------------------------------\n";  
        cout<< "The global pi value is : " << pi << " \n";   
        cout<< " the address of the global pi : " << &pi << "\n"; 
    }
    cout<< "\n--------------------------------\n";
    cout<< "The local pi value is : " << pi << " \n";
    cout<< " the address of the local pi : " << &pi << "\n"; 

}