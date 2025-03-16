#ifdef CPP
#include <iostream>
using namespace std;
#endif

#include <vector>
#include <map>
#include <algorithm>


#ifdef INTERFACE
class SampleClass
{
    public:
        vector<int> vector_var;
        map<int, int> map_var;
        virtual void set_vector()=0;
        virtual void print_vector()=0;
        virtual void sort_vector()=0;
        virtual void reverse_vector()=0;
        virtual void count_repeat()=0;
};
class InheritedClass : public SampleClass
{
    public :
        InheritedClass();
        ~InheritedClass();
        void set_vector();
        void print_vector();
        void sort_vector();
        void reverse_vector();
        void count_repeat();
};
#endif

