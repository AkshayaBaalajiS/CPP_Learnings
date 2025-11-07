#include "SomeClass.h"

#ifdef SOME_CLASS
SomeClass::SomeClass()
{
    cout<<"@ SomeClass Constructor \n";
}

SomeClass::~SomeClass()
{
    cout<<"@ SomeClass Destructor \n";
}

void SomeClass::someFunction(int a, int b)
{
    if(a<=0 || b<=0)
    {
        throw invalid_argument("Invalid Arguments\n");
    }
    else{
        cout<<"Operation performed and the result a+b = " << a + b <<endl;
        throw runtime_error("No Error simply throwing something\n");
    }
}
#endif
