#include<iostream>
using namespace std ;
struct A{};
struct B : A {};
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
    b_ptr = new B(); // dynamic mem allocation 

    a_ptr = d_ptr ; // here the compiler internally type cast automatically 
    // not in the above line both a_ptr and c_ptr will point to same address 

    a_ptr = static_cast <A *> (c_ptr);  // when there is a upcasting from derived to base then static_cast done 
}