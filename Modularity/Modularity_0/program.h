#ifdef HEADER
// #define HEADER // we are defining this in thje cmake 
#include <iostream>

using namespace std;

class Sample
{
    static int consCounter;
    static int desCounter;
    
    int a;
    float b;
    char c;
    double d;
    public :
        Sample();
        void setDataMember(int a=1, float b=1.12f, char c = 'a', double d =4.121312);
        void printDataMember();
        virtual ~Sample();
};
#endif /* HEADER */
