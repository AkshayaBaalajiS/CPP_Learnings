#include "program.h"

#ifndef HEADER
#define HEADER
#include<iostream>
#endif // !HEADER

int Sample::consCounter = 0;
int Sample::desCounter = 0 ;

Sample::Sample()
{
    consCounter++;
    desCounter++;
    cout<<"@ Sample Class Constructor Called "<< consCounter << " Number of times \n";
}

Sample::~Sample()
{
    desCounter--;
    cout<<"\n@ Sample Class Destructor called " << desCounter <<  " Number of times \n";
}

// Sample::setDataMember(int a, float b , char c, double d) // this is the proof that if we give the default parameter to a function oin defining it also we have give the default parameter
void Sample::setDataMember(int a, float b, char c, double d)
{
    this->a = a;
    this->b = b;
    this->c = c;
    this->d = d;
}

void Sample::printDataMember()
{
    cout<<"\n@ void Sample::printDataMember()\n";
    cout<<"Class Data members are ..\n";

    cout<<"Int : " <<this->a<<"  ";
    cout<<"Float : " <<this->b<<"  ";
    cout<<"Char : " <<this->c<<"  ";
    cout<<"Double : " <<this->d<<"  ";
}

int main()
{
    cout<<"This is the program to understand the Modularity\n";
    cout<<"Modularity is seperating the interface and implementation \n";

#ifdef HEADER 
    Sample * samplePtr = new Sample();
    Sample * samplePtrArray = new Sample[10];

    int a = 12;
    float b =23.234f;
    char c = 'a';
    double d =12.34434;

    samplePtr->printDataMember();


    for(int i=0;i<10;i++)
    {
        samplePtrArray[i].setDataMember(a,b,c,d);
        samplePtrArray[i].printDataMember();
        a++;
        b++;
        c++;
        d++;
    }

    delete [] samplePtrArray;
#else 
    cout<<"The Sample class is not defined \n";
#endif

    return 0;
}

