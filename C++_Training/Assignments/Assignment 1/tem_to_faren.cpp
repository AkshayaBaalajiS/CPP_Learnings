#include<iostream>
using namespace std ;
int celcius_to_faren(int cel)
{
    int faren = (cel * 1.8 ) + 32 ;
    return faren;
}
int faren_to_cel(int faren)
{
    int cel = (faren -32)*(0.555) ;
    return cel;
}

int main() {
    cout<<"Convert temperature in Celsius to Fahrenheit : \n" ; 
    cout<<"--------------------------------------------------- \n";
    cout<<"Input the temperature in Celsius : \n" ;
    cout<< "The temperature in Celsius : "  ;
    int temp ;
    cin>> temp;
    cout<<"The temperature in Fahrenheit : " << celcius_to_faren(temp) <<"\n";
    cout<<"Convert temperature in Fahrenheit to Celsius : " ;
    cout<<"--------------------------------------------------- \n";
    cout<<"Input the temperature in Fahrenheit : \n" ; 
    cout<<"The temperature in Fahrenheit : " ;
    int faren ;
    cin >> faren ;
    cout<<"The temperature in Celsius : " << faren_to_cel(faren) <<"\n"; 


}