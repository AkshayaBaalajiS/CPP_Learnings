#include<iostream>
#include <sstream>
using namespace std;

int main()
{
    cout<<"This is the program to understand the ostringstream \n";
    int a =100 ;
    char arr[]="Akshaya Baalaji Senthilraj";

    ostringstream oss;
    oss<<a << "  " << arr <<"\n";

    // final string afetr the ostringstream
    string stre = oss.str();
    // 100  Akshaya Baalaji Senthilraj\n
    // 01234567890123
    cout<<"The final output is : " << stre;
    cout<<"The string size is  : " << stre.size() << "\n";

    

}