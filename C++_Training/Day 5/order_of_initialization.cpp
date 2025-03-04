#include<iostream>
using namespace std ;

namespace Group1 
{
    class A 
    {       
        
        // int random = 5 ; if the random is at first the random(5) will be done by the compailer in the initializer list at first
        const int variable_1;
        const int variable_2;
        int random = 5 ; // random(5) will be done by the compailer in the initializer list at last 
        //declaration :
        public :
            A(int variable_1,int variable_2) : variable_1(random+variable_1) /*garbage + 10*/ , variable_2(variable_2+random ) /*garbage + 20*/  /* ,random(5) this will be done by the compailer because of order of execution */
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

int main()
{
    Group1::A object(10,20);

}
/*
#include <iostream>
using namespace std;
 
namespace DataMember_Puzzle {
    class cA {
        int i, j, k;
    public:
        // Correcting the constructor initialization order
 
        //cA(int arg = -1) :j(arg),i(j),k(j) {}
        cA(int arg = -1) : k(i), i(arg), j(i) {}
        ~cA() {
            cout << "i = " << i << " j = " << j << " k = " << k << "\n";
        }
    }; // Missing semicolon after class definition
 
    void main() {
        cA obj(10);
        cout << "----------\n";
    }
}
 
int main() {
    DataMember_Puzzle::main(); // Correct namespace access
    return 0;
}
 
*/