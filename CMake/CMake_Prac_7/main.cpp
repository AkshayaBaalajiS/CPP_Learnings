#include "Abstraction.h"

int main()
{
    cout<<"This is the program to understand the abstract class \n";
#ifdef ABSTRACT_CLASS
    // try
    // {
        // AbstractClass obj ; 

    // }

    inheritedClass object;
    object.vec = {3,3,453,32,23,23,23,4343,45,45,54};
    object.sort_vector();
    cout<<endl;
    object.print_vector();
    cout<<endl;
    object.reverse_vector();
    cout<<endl;
    object.print_vector();
    cout<<endl;

#endif
}