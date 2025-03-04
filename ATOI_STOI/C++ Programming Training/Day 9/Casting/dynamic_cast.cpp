#include<iostream>
using namespace std ;
// the dynamic polymorphism has to be applied on the multilevel inheritance and the class has to be polymorphic 
// for mkaing it polymorphic we are making the virtual function on destructor  
struct A{virtual ~A(){}}; 
struct B : A { };
struct C : B {};
struct D : C {};

int main()
{
    double dble= 2342.32432;
    short srt = dble;
    int inte = dble ;
    char chare = dble ;
    char chare_1 = static_cast<char> (dble)  ;
    cout<<"dble = " << dble << "\n";
    cout<<"srt = " << srt << "\n";
    cout<<"inte = " << inte << "\n";
    cout<<"chare = " << chare << "\n";
    cout<<"chare_1 = " << chare_1 << "\n";


    A * a_ptr = NULL ; // due to LSP it can point to A , B , C , D kind of object 
    B * b_ptr = NULL ; // due to LSP it can point to B , C , D kind of object 
    C * c_ptr = NULL ; // due to LSP it can point to  C , D kind of object 
    D * d_ptr = NULL ; // due to LSP it can point to  D kind of object 
    
    cout<<"-------------------------------\n";
    a_ptr = new B(); // dynamic mem allocation 

    // d_ptr = a_ptr ; // here the compiler throw error for the downcasting (base to derived )  

    a_ptr = dynamic_cast <A *> (c_ptr);  // when there is a downcasting from derived to base then static_cast done 

}