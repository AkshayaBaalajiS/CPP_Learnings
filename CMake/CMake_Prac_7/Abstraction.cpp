#include "Abstraction.h"

AbstractClass::AbstractClass()
{
    cout<<"@ AbstractClass constructor \n";
}

AbstractClass::~AbstractClass()
{
    cout<<"@ ~AbstractClass destructor \n";
}

void AbstractClass::print_vector()
{
    for(int i : vec)
    {
        cout<< i << "  ";
    }
}

inheritedClass::inheritedClass()
{
    cout<<"@ inheritedClass Constructor \n";
}
inheritedClass::~inheritedClass()
{
    cout<<"@ ~inheritedClass Destructor \n";
}


bool func(int a , int b)
{
    return (a>b ? true: false);
}
void inheritedClass::sort_vector()
{
    sort(vec.begin(), vec.end(), func);
}

void inheritedClass::reverse_vector()
{
    reverse(vec.begin(), vec.end());
}
