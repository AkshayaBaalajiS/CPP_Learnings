#include<iostream>
using namespace std;

int main()
{
    char* arr = "Akshay";
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
                cout<<arr[i];
            }
            cout<<"\n";
        }
        
        if(i==1)
        {
            count = final_count-2;
            cout<<arr[i]<<"     "<<arr[count]<<"\n";

        }
        if(i==2)
        {
            count = final_count-i-1;
            cout<<arr[i]<<"     "<<arr[count]<<"\n";
        }
        
        if(i==3)
        {
            count = final_count-i-1;
            cout<<arr[i]<<"     "<<arr[count]<<"\n";
        }
        
        if(i==4)
        {
            count = final_count-i-1;
            cout<<arr[i]<<"     "<<arr[count]<<"\n";
        }

        if(i==5)
        {
            count = final_count-i-1;
            cout<<arr[i]<<"     "<<arr[count]<<"\n";
        }
        if(i==6)
        {
            count = final_count;
            for(int i=count ; i>=0;i--)
            {
                cout<<arr[i];
            }
        }
    }
}