#include<iostream>
using namespace std;

int main()
{
    cout<<"This is the program to understand the try throw and catch in c++ \n";
    int a =1234;
    bool flag= false;
    cout<<"|-----------------------------------------------------------------|\n";
    try
    {
        
        cout<<"Enter the input for the flag : " ;
        cin>>flag;

        if(flag)
        {
            cout<<"The flag is : " << flag << endl;
            throw 0;
        }
        else{
            throw("The flag is false");
        }
    }
    catch(exception & e)
    {
        cerr<<"The error is : " << e.what() << endl;
    }
    catch(int a)
    {
        cerr<<"The error the try block throwed is : " << a <<endl;
    }
    catch(...)
    {
        cout<<"This catch is called if there is no proper catch for the above throw \n";
    }
    cout<<"|-----------------------------------------------------------------|\n";


    cout<<"Came out of the try block \n";
}