#include<iostream>
using namespace std;

int main()
{
    cout<<"This is the program to understand the try catch in c++ \n";

    int val =13;
    int div =0 ;

    try{
        val = val / div;
        throw runtime_error("Zero Division Error ");
    }
    catch(exception & e){
        cerr<<"This is the error " << e.what() <<endl; 
    }
}
/*
This is the wrong way cause the check for the floating point is not there so it should be handled 
if(div==0)
{
    throw runtime_error("Zero Diving Error");
}
*/