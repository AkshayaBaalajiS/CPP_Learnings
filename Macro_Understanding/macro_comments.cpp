#include<iostream>
using namespace std;
#define VALUE 3

int main()
{
    cout<<"This program is for understanding what not to do with namespace \n";
    int number ;
    
// logical comments 
#if VALUE>10 
    cout<<"The macro value is greater than 10 \n";
#elif VALUE <10 && VALUE >5 
    cout<<"The macro value is greater than 5 and less than 10 \n";
#elif VALUE <=5 && VALUE >2 
    cout<<"The macro value is greater than 2 and less than or equal to 5 \n";
#else 
    cout<<"The macro value is less than or equal to 2\n";
#endif

}