#include<iostream>
using namespace std;

int main()
{
    char arr[20];
    cout<<"Enter Name to be printed in box :";
    cin>>arr;
    static int count ;
    for(int i=0;arr[i]!='\0';i++)
    {
        ++count;
    }
    const int final_count = count ;
    cout<<"The final count =" << final_count<<"\n";

    for(int i=0;arr[i]!='\0';i++)
    {
        if(i==0)
        {
            for(int i=0;arr[i]!='\0';i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<"\n";
        }
        else if(i==final_count-1)
        {
            count = final_count;
            for(int i=count-1 ; i>=0;i--)
            {
                cout<<arr[i]<<" ";   // here the /0 also printed 
            }
        }
        else 
        {
            count = final_count-1;
            int temp = count - i;
            cout << arr[i] ; 
            for(int i=1;i<final_count-1;i++)
            {   
                cout<<"  ";
            }
            cout <<" "<<arr[temp]<<"\n";  // here the space missed 
        }
        
       
    }
}