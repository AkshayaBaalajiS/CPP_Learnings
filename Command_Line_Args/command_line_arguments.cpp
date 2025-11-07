#include<iostream>
using namespace std;


int main (int args , char ** str_arg )
{
    cout << "The number of arguments to this code  :   " << args  << endl;
    cout << "The string arguments are   : ";
    for (int i=0;i<args ; i++)
    {
        cout <<  (str_arg[i]) << "~";
    }     
    cout<< "\n";
      
}