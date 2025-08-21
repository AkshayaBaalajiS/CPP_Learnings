#include <iostream>
using namespace std;

int main()
{
    cout<<"This is the program to get the smallest and larget ele in array \n";
    
    int arr[] = {34,45,56,23,12,45,65};
    
    bool aas=false;
    int count =0;
    // sorting the array 
    while(!aas)
    {
        for(int i=0;i<6;i++)
        {
            if(arr[i] > arr[i+1])
            {
                // cout<<"+";
                int temp =  arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                count=0;
            }
            else
            {
                // cout<<"_"<<count<<"_";
                ++count;
            }
        }
        if(count==6)
        {
            // cout<<"HIT+++++++++++++++++\n";
            aas=true;
        }
        else
        {
            count=0;
        }
    }
    
    for(int i=0;i<7;i++)
    {
        cout<<" " <<arr[i] <<  " " ; 
    }
}