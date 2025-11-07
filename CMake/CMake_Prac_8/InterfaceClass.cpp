#include "InterfaceClass.h"

InheritedClass::InheritedClass()
{
    cout<<"@ InheritedClass constructor \n";
}

InheritedClass::~InheritedClass()
{
    cout<<"@ ~InheritedClass destructor \n";
}

void InheritedClass::set_vector()
{
    int input ;
    cout<<"Enter the number of element to be pushed in vector \n";
    cin>>input;
    cout<<"Enter the elements\n";
    for(int i =0 ;i<input;i++)
    {
        int tmep;
        cin>>tmep;
        vector_var.push_back(tmep);
    }
}

void InheritedClass::print_vector()
{
    cout<<"The vector holds : " ;
    for(int i:vector_var)
    {
        cout<<i<< "  " ;
    }
    cout<<endl;
}

void InheritedClass::sort_vector()
{
    sort(vector_var.begin(),vector_var.end());
}

void InheritedClass::reverse_vector()
{
    reverse(vector_var.begin(),vector_var.end());
}

void InheritedClass::count_repeat()
{
    for(int i:vector_var)
    {
        map_var[i]++;
    }

    for(auto it : map_var)
    {
        cout<<it.first << "  =  " << it.second<<endl;
    }
}

