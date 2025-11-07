#include<iostream>
using namespace std;
#include<vector>

int main()
{
    int arr1,arr2 ;
    cin>>arr1>>arr2;

    cout<<arr1<<arr2<<endl;

    vector<vector<int>> vvec ;

    int arr[arr2*arr2];

    for(int i=0;i<arr1;i++)
    {
        int size;
        cin>>size;
        vector<int> vtempp;
        for(int j=0;j<size;j++)
        {
            int tmep;
            cin>>tmep;
            vtempp.push_back(tmep);
        }
        vvec.push_back(vtempp);
    }
    for(int i=0;i<arr1;i++)
    {
        for(int j=0;j<vvec[i].size();j++)
        {
            cout<<vvec[i][j] << "   " ;
        }
    }
}