#include<iostream>
namespace A 
{
    int a =100;
}
namespace AA
{
    int a =1000;
}

int main()
{
    std::cout<<"a from namespace A  : " << A::a <<"\n";
    std::cout<<"a from namespace AA  : " << AA::a <<"\n";
    
}