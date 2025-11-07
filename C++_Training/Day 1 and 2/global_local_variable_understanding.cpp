#include<iostream>
using namespace std;
int gi =10;
int main()
{
    int gi =20;
    {
        extern int gi ;  // this makes the local variable to keep quite and make the global variable to run 
        cout<<"Value of the global variable is :  ";
        cout << "gi : " << gi << " &gi :  " << &gi <<"\n" ;  
        gi = 78 ; //trying to change the global variable 
        cout<<"After changing Global variable :  " ;
        cout << "gi : " << gi << " &gi :  " << &gi <<"\n" ;  
        
    }
     cout<<"Local variable :  " ;
    cout << "gi : " << gi << " &gi :  " << &gi <<"\n";

    {
    extern int gi ;  // this makes the local variable to keep quite and make the global variable to run 
    cout<<"After change Value of Global variable is  :  ";
    cout << "gi : " << gi << " &gi :  " << &gi <<"\n" ;  
   
    }
}