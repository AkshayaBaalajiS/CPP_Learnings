#include "InterfaceClass.h"
#include <memory> // for unique_ptr 
int main()
{
#ifdef INTERFACE
    // unique_ptr <InheritedClass> uptr = new InheritedClass();
    /*
std::unique_ptr is a smart pointer in C++ that automates the management of dynamically allocated memory. It ensures that:

The dynamically allocated object is properly deleted when the unique_ptr goes out of scope.

It owns the dynamically allocated object (i.e., the object it points to is its responsibility).

What does new do?
new is a low-level memory allocation operator in C++ that allocates memory on the heap for an object. When you use new, you are responsible for calling delete later to free the memory.

*/
// unique_ptr <InheritedClass> uptr;
    // This will cause a segmentation fault because uptr is null
    unique_ptr <InheritedClass> uptr = std::make_unique<InheritedClass>();

    uptr->set_vector();

    uptr->print_vector();

    uptr->sort_vector();

    uptr->print_vector();

    uptr->reverse_vector();

    uptr->print_vector();

    uptr->count_repeat();
#else
    cout<<"No interface implemented so bye \n";
#endif
}