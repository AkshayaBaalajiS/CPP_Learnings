#include<iostream>
#include<cstring>
using namespace std ;

class A
{
    public :
        // friend char * operator + (A & ref1 , A & ref2); 
        friend A & operator + (A & ref1 , A & ref2 ) ;
        friend ostream & operator << (ostream &  , A & ref1 );
        char *pubilc_variable ;
        A()
        {
            cout<<"@A Constructor \n"; 
        }
        A(char *str ) 
        {
            pubilc_variable = new char[strlen(str) + 1 ];   // strlen if dor the char array 
            strcpy(pubilc_variable,str);
        }
        A(string str )
        {
            // // strcpy(pubilc_variable,str);
            pubilc_variable = new char[str.length()+1];   // variable.lebgth is for calculation the length of variable of string type 
            strcpy(pubilc_variable,(str.c_str()));    //c_str() is for converting the string to const char * type 
        }

        


        void display()
        {
            cout<<"The value of the String is " << pubilc_variable <<"\n" ;
        }
        ~A()
        {
            cout<<"@A Destructor \n"; 
        }
};
/* This is the logic for concatenation with the return typr of char *
char * operator + (A & ref1 , A & ref2 )
{
    // int size = strlen(ref1.pubilc_variable) + strlen(ref2.pubilc_variable) +1 );
    int size1 = strlen(ref1.pubilc_variable);
    cout <<"strlen(ref1.pubilc_variable) : " << strlen(ref1.pubilc_variable) << "\n";
    int size2 = strlen(ref2.pubilc_variable);
    cout <<"strlen(ref2.pubilc_variable) : " << strlen(ref2.pubilc_variable) << "\n";
    int total = size1+size2;

    char * ptr = new char [total+1];

    for(int i=0;i<size1;i++)
    {
        ptr[i]=ref1.pubilc_variable[i];
    }
    cout<<"At first copy  : " << ptr <<"\n";

    for(int i=0 ; i<total ;i++)
    {
        ptr[size1+i] = ref2.pubilc_variable[i];
    }
    ptr[total] = '\0';
    cout<<"At second copy  : " << ptr <<"\n";

    return ptr ;

}
*/
A global_object ;
A &  operator + (A & ref1 , A & ref2 )
{
    // int size = strlen(ref1.pubilc_variable) + strlen(ref2.pubilc_variable) +1 );
    int size1 = strlen(ref1.pubilc_variable);
    cout <<"strlen(ref1.pubilc_variable) : " << strlen(ref1.pubilc_variable) << "\n";
    int size2 = strlen(ref2.pubilc_variable);
    cout <<"strlen(ref2.pubilc_variable) : " << strlen(ref2.pubilc_variable) << "\n";
    int total = size1+size2;

    global_object.pubilc_variable = new char [total+1];  // allocating the space With Res To total length 


    for(int i=0;i<size1;i++)
    {
        global_object.pubilc_variable[i]=ref1.pubilc_variable[i];
    }
    cout<<"At first copy  : " << global_object.pubilc_variable <<"\n";

    for(int i=0 ; i<total ;i++)
    {
        global_object.pubilc_variable[size1+i] = ref2.pubilc_variable[i];
    }
    global_object.pubilc_variable[total] = '\0';
    cout<<"At second copy  : " << global_object.pubilc_variable <<"\n";

    return global_object ;

}

ostream & operator << (ostream & os , A & ref1 )
{
    os <<"At cascading operator overloading   : " << global_object.pubilc_variable <<"\n";
    return os ;

}


int main()
{
    A object ;
    // object("Akshaya"); this cant be done error
    cout<<"\n---------------------------\n"; 
    char array[] = "Akshaya ";
    A object_2(array);
    cout<<"----------------------------\n";
    string str ="Baalaji Senthilraj";
    A object_3(str);
    object_3.display();
    cout<<"----------------------------\n";
    /* We have done this so we are commenting bothe the function and call 
    // +  operator overloading and return a char * 
    char * result = object_2+object_3;
    cout<<"Final concat is " << result << " \n";
    cout<<"----------------------------\n";
    */
    A object_new ;
    object_new = object_2 + object_3 ;
    cout <<"The object_new.public_varaible :  "<<object_new.pubilc_variable<<"\n";
    cout<<"----------------------------\n";
    //Cascading operator overloading 
    cout<<object_new;

}
