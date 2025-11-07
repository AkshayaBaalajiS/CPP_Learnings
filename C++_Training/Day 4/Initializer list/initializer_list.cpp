#include<iostream>
using namespace std ;

namespace Group1 
{
    class A 
    {
        
        
        const int variable_1;
        
        int random = 5 ;
        const int variable_2;
        public :
            A(int variable_1,int variable_2) : variable_1(random+variable_1) , variable_2(variable_2+random )
            {
                // int random = 5 ;
                // this->variable_1 = variable_1 + random;
                // this->variable_2 = variable_2 + random;
            }
            ~A()
            {
                cout << "variable_1: " << variable_1 << ", variable_2: " << variable_2 << endl;
            } 
    };
   
}
// int Group1::A::variable_1 =10;
// int Group1::A::variable_2 =10;



int main()
{
    Group1::A object(10,20);

}