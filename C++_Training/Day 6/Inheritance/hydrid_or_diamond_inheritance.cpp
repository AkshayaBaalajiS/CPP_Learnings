#include<iostream>
using namespace std ;

struct base  {  //4 bytes 
    int public_variable; 
};
struct base_derived_1  :  base { // 8 bytes 
    int public_variable_1;
};
struct base_derived_2 :   base { // 8 bytes 
    int public_variable_2;
};
struct bd_derived_1  : base_derived_1{ // 12 bytes 
    int public_variable_3;
};
struct bd_derived_2  : bd_derived_1{ // 16 bytes 
    int public_variable_4;
};

void sizes()
{
    cout <<"Size of struct base " << sizeof(base) << "\n";
    cout <<"Size of struct base " << sizeof(base_derived_1) << "\n";
    cout <<"Size of struct base " << sizeof(base_derived_2) << "\n";
    cout <<"Size of struct base " << sizeof(bd_derived_1) << "\n";
    cout <<"Size of struct base " << sizeof(bd_derived_2) << "\n";
    
}

int main()
{
    sizes();
}
