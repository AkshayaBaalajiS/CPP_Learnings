#ifndef CPP
#define CPP

#include <iostream>

#endif

using namespace std;

#ifdef CLASSIMP
#define SAMPLE_CLASS
class Sample
{
    int a;
    float b;
    char c;
    double d;
    // Shallow_Data 
    int * shallow_data ;

    // Deep_Data 
    int * deep_data ;

    public:
        Sample();
        Sample(int a, float b, char c, double d, int * val , int * val_1);
        ~Sample();
        Sample(Sample & ref );
        void setValues(int a=1, float b=1.1f, char c='a', double d=12.232, int val = 12 , int val_1=23);
        void printValues();
          
};
#endif