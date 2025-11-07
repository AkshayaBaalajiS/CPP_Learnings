/*
adno 4 digit admission number 
name 20 characters 
marks an array of 5 floating point values 
average average marks obtained 
GETAVG() a function to compute the average obtained in five subject 
Public members:
READINFO() function to accept values for adno, name, marks. Invoke the function 
GETAVG() 
DISPLAYINFO() function to display all data members of report on the screen.
*/
#include<iostream>
using namespace std ;
class A
{
    int adno;
    char name[20];
    float marks[5];
    float average ;
    float cal_avg ()
    {
        int sum ;
        for(int i=0;i<5;i++)
        {
            sum = sum + marks[i];
            average = sum / 5;
        }
        // cout<<"Average = " << average <<"\n";
        return average;
    }
    public :
        void read_info()
        {
            cout<<"Enter the adno :" ;
            cin>>adno;
            cout<<"Enter the name : ";
            cin>>name;
            int mark ; 
            for(int i=0;i<5;i++)
            {
                cout<<"Enter Mark " << i+1 <<":" ;
                cin >> mark;
                marks[i]=mark;
            }
            average = cal_avg();
        }
        void display()
        {
            cout<<"The addno is : " << adno << "\n";
            cout<<"The name is  : "  << name <<"\n";
            for(int i=0;i<5;i++)
            {
                cout<<"Mark " << 1+i << " is  " << marks[i] <<"      ";
            }
            cout<<"\nAverage obtained : " << average ;
        }
};
int main()
{
    A object ;
    object.read_info();
    object.display();
}