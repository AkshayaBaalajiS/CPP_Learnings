#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main()
{
    cout<<"This is the program to convert the decimal to hexadecimal \n";
    int number ;
    cout<<"Enter the nunmber  : " ;
    cin>>number ;

    vector<int> octal_number ;
    while(number!=0)
    {
        int rem = number% 16 ;
        octal_number.push_back(rem);
        number=number/16;
    }

    reverse(octal_number.begin(),octal_number.end());

    for(int i :  octal_number )
    {
        cout<< i   << "    "; 
    }
    cout<<endl;
}