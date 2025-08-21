#ifdef CPP
#include <iostream>
#endif

#include <algorithm>

#ifdef STL
#include <vector>
#include <map>
#endif

using namespace std;

#ifdef ABSTRACT_CLASS
class AbstractClass
{
    public:
        vector<int>  vec;
        AbstractClass();
        ~AbstractClass();
        virtual void sort_vector() =0; 
        virtual void reverse_vector() =0; 
        void print_vector(); 

};
#endif

class inheritedClass : public AbstractClass
{
    public:
        inheritedClass();
        ~inheritedClass();
        void sort_vector();
        void reverse_vector();

};
