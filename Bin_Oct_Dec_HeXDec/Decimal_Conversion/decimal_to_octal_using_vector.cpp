#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main()
{
    cout<<"This is the program to convert the decimal to octal\n";
    int number ;
    cout<<"Enter the nunmber  : " ;
    cin>>number ;

    vector<int> octal_number ;
    while(number!=0)
    {
        int rem = number% 8 ;
        octal_number.push_back(rem);
        number=number/8;
    }

    reverse(octal_number.begin(),octal_number.end());

    for(int i :  octal_number )
    {
        cout<< i   << "    "; 
    }
    cout<<endl;
}