/*
A data member Flight number of type integer 
A data member Destination of type string 
A data member Distance of type float 
A data member Fuel of type float 
A member function CALFUEL() to calculate the value of Fuel as per the following 
criteria 
 Distance Fuel 
 <=1000 500 
 more than 1000 and <=2000 1100 
 more than 2000 2200 
Public Members
A function FEEDINFO() to allow user to enter values for Flight Number, Destination, 
Distance & call function CALFUEL() to calculate the quantity of Fuel 
A function SHOWINFO() to allow user to view the content of all the data members*/
#include<iostream>
using namespace std;
class A
{
    int flight_number;
    string destination ;
    float distance ;
    float fuel;
    int cal_fuel()
    {
        if(distance<=1000)
        {
            return 500;
        }
        if(distance>1000 &&  distance<=2000 )
        {
            return 1100;
        }
        if(distance>2000 )
        {
            return 2200;
        }
    }
    public :
        void feed()
        {
            cout <<"Enter the flight_number : ";
            cin>>flight_number;
            cout<<"Enter the Destination : ";
            cin>> destination;
            cout<<"Enter the Distance  : ";
            cin>> distance;
            fuel = cal_fuel() ;
        }
        void show_data()
        {
            cout <<"The flight_number :  " << flight_number <<"\n";
            cout<<"The Destination : " <<  destination <<"\n";
            cout<<"The Distance  : " <<  distance <<"\n";
            cout<<"The fuel needed : " <<  fuel << "\n" ; 
        }
        
};
int main()
{
    A object;
    object.feed();
    object.show_data();
}