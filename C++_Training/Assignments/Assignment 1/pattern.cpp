#include<iostream>
using namespace std ;

int main()
{
    int n ;
    cout<<"Enter the diamond size " ;
    cin>>n ;
    cout<<"\n";    
    for (int i=0;i<n;i++)
    {
        for(int j=i;j<n-1;j++)
        {
            cout<<" ";
        }
        for(int k=0;k<=i;k++)
        {
            cout<<"*";
        }
        for(int l=0;l<i;l++)
        {
            cout<<"*";
        }
        cout<<"\n";
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            cout<<" ";
        }
        for(int j=n-1;j>i;j--)
        {
            cout<<"*";
        }
        for(int k=n;k>i;k--)
        {
            cout<<"*";
        }
        cout<<"\n";
    }
}

/*int main()
{
    int n = 5 ;
    for (int i=0;i<n;i++)
    {
        for(int j=i;j<n-1;j++)
        {
            cout<<"+";
        }
        for(int k=0;k<=i;k++)
        {
            cout<<"*";
        }
        for(int l=0;l<i;l++)
        {
            cout<<"&";
        }
        cout<<"\n";
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            cout<<"+";
        }
        for(int j=n-1;j>i;j--)
        {
            cout<<"*";
        }
        for(int k=n-1;k>i;k--)
        {
            cout<<"&";
        }
        cout<<"\n";
    }
}*/