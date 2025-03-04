#include <iostream> 
using namespace std; 
 
int main(void) 
{ 
    const int val = 10; 
    const int *ptr = &val; 
    int *ptr1 = const_cast <int *>(ptr); 
    *ptr1 = 30;
    cout << "*ptr1 = " << *ptr1 <<" *ptr =" << (*ptr) << " Value is ="  << val ; 
    return 0; 
} 