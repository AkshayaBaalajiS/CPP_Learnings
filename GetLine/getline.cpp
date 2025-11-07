#include<iostream>
using namespace std;

int main()
{
    cout<<"This is a program to understsand the getline in c++\n";

    
    int size;
    cout<<"ENter a size of name  : ";
    cin>>size;
    cout<<"\n";
    cin.ignore();

    /* Here we will face another problem where the getline reads input till new line 
     found and the cin return the neww line after the input read so the getline takes that as input    
        so we have to use the cin.ignore to remove the new line for making the getline to get input properly 
    */
    //to overcome the below error we use the getline from cin 
    cout<<"Enter your name  : ";
    char name[size];
    cin.getline(name,size) ; 

    
    // the problem here is this cin will get input till first space is found 
    // cout<<"Enter your name  : ";
    // char name[size];
    // cin>>name ; 

    for(int i=0;i<size;i++)
    {
        cout<<name[i] << " ";
    }
    cout<<endl;



}