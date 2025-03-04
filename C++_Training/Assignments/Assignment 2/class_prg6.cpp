#include<iostream>
using namespace std ;
class time_class
{
    friend void sum_time(time_class &a , time_class &b);
    int hours;
    int mins;
    public :
        void settime(int a , int b )
        {
            this->hours=a;
            this->mins=b;
        }
        void show_time()
        {
            cout<<"Time : "<<hours<<":"<<mins <<"\n";
        }
};
void sum_time(time_class &a , time_class &b)
{
    int sum_hours= a.hours + b.hours ;
    int sum_mins= a.mins + b.mins ;
    int min_temp;
    while(sum_mins>60)
    {
        min_temp = sum_mins - 60 ;
        sum_mins = sum_mins -60 ;
        sum_hours =sum_hours+1;
    }
    cout<<"The sum of the time is : "<<sum_hours << ":" << sum_mins <<"\n";
}
int main()
{
    time_class object1 , object2;
    object1.settime(7,59);
    object2.settime(8,59);

    object1.show_time();
    object2.show_time();
    
    sum_time(object1,object2);
}



 

