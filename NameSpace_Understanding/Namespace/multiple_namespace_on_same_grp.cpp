#include<iostream>

using namespace std;

namespace A {
    int int_variable =12;
}

namespace A{
    float float_variable=4.324;
    struct Sample_structure 
    {
        int size;
        char * name ;
        void funciton_to_print_all( );
    };
    void Sample_structure::funciton_to_print_all( )
    {
        cout<<"Integer variable = " << int_variable<<endl;
        cout<<"Float variable = " << float_variable<<endl;
        for (int i=0;i<size ; i++)
        {
            cout<< name[i]<< " ";
        }
        cout<<"\n";
    }
}
int main()
{
    cout<<"This is the main function : \n";
    A::Sample_structure * ptr = new A::Sample_structure ;
    
    int size ;
    cout<<"Enter size for entering a string...\n";
    cin>>size;
    cin.ignore(); 
    char name[size];
    cout<<"Enter your name  : " ;
    cin.getline(name,size);
    cout<<"\n";
    
    ptr->size=size;
    ptr->name=name;
    ptr->funciton_to_print_all();
}

