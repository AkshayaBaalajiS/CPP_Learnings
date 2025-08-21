#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    cout<<"This is the program to understand the memcpy and strcpy\n";
    string name = "Akshaya Baalaji";
    cout<<"I MEMCPY STARTS \n";
    
    char * arr = new char [50];
    // char arr[];

    cout<<"The char *  = " << arr <<endl;
    cout<<"The String   = " << name <<endl;
    
    memset(arr,'a',50);
    cout<<"After the memset : "<<endl;
    cout<<"The char *  = " << arr <<endl;
    cout<<"The String   = " << name <<endl;
    
    memcpy(arr,name.c_str(),name.size());
    cout<<"After the memcpy : "<<endl;
    cout<<"The char *  = " << arr <<endl;
    cout<<"The String   = " << name <<endl;

    // memcpy is doing a byte by byte copy and only do till the size of destination even if the source has more space left  
    cout<<"|--------------------------------------------------------------------|\n";

    cout<<"II STRCPY STARTS \n";
    memset(arr,0,50);
    cout<<"After the memset : "<<endl;
    cout<<"The char *  = " << arr <<endl;
    cout<<"The String   = " << name <<endl;
    
    strcpy(arr,name.c_str());
    cout<<"After the strcpy : "<<endl;
    cout<<"The char *  = " << arr <<endl;
    cout<<"The String   = " << name <<endl;

    // strcpy copies the entire string irrespective of the source size 
    // strcpy will do a entire copy of the string from destination to source 
    // At the end the source will the the destination exactly 
}