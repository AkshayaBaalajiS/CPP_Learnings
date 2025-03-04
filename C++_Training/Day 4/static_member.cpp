/*#include<iostream>
using namespace std ;


int count =0 ; //  make it common for every object  

class A 
{
    public :
        // int count ; // make it unique for every object 
        A()
        {
            ++count; // this is the best place to place to increment
            cout<<"Count @ constructor  " << count <<" times \n"; 
        }
        
        void display()
        {
            cout<<"The A class object called " << count <<" times \n";
            
        }
        ~A()
        {
            --count;
            cout<<"Count @ destructor  " << count <<" times \n";
        }
};
int main()
{
    A obj_0;
    // cout<<"THe count on one obj created :  " ;
    // obj_0.display();
    
    A obj_1 ;
    // cout<<"THe count on one obj created :  " ;
    // obj_1.display();
    
    A obj_2 ;
    // cout<<"THe count on one obj created :  " ;
    // obj_2.display();
    
    A obj_3 ;
    // cout<<"THe count on one obj created :  " ;
    // obj_3.display();
    
    
}*/
/*
#include<iostream>
using namespace std ;


// int count =0 ; //  make it common for every object  

class A 
{
    
    int count =0; // make it unique for every object 
    public :
        A()
        {
            ++count; // this is the best place to place to increment
            cout<<"Count @ constructor  " << count <<" times \n"; 
        }
        
        void display()
        {
            cout<<"The A class object called " << count <<" times \n";
            
        }
        ~A()
        {
            --count;
            cout<<"Count @ destructor  " << count <<" times \n";
        }
};
int main()
{
    A obj_0;
    // cout<<"THe count on one obj created :  " ;
    // obj_0.display();
    
    A obj_1 ;
    // cout<<"THe count on one obj created :  " ;
    // obj_1.display();
    
    A obj_2 ;
    // cout<<"THe count on one obj created :  " ;
    // obj_2.display();
    
    A obj_3 ;
    // cout<<"THe count on one obj created :  " ;
    // obj_3.display();
    
    
}
*/
#include<iostream>
using namespace std ;


// int count =0 ; //  make it common for every object  

class A 
{
    static int count ; // static member function declaration only 
    public :
        A()
        {
            ++count; // this is the best place to place to increment
            cout<<"Count @ constructor  " << count <<" times \n"; 
        }
        
        ~A()
        {
            --count;
            cout<<"Count @ destructor  " << count <<" times \n";
        }
        static int funciton()
        {
            return count;
        }

};

int A::count=0; // if we not initialized it will search in whole file and if it is not found it will through link error 
int result = A::funciton();


int main()
{
    A obj_0;
    // cout<<"THe count on one obj created :  " ;
    // obj_0.display();
    
    A obj_1 ;
    // cout<<"THe count on one obj created :  " ;
    // obj_1.display();
    
    A obj_2 ;
    // cout<<"THe count on one obj created :  " ;
    // obj_2.display();
    
    A obj_3 ;
    // cout<<"THe count on one obj created :  " ;
    // obj_3.display();
    
    {
        A obj_4;
        cout<<"The main count from static funtion : " << A::funciton << "\n";
        // cout<<"The main count : " << A::count << "\n"; this is a error 
        
    }

    cout <<"\n\n Result " << result <<"\n";
}