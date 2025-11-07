#include<iostream>
using namespace std;

class sampleClass
{
    int iVar ;
    float fVar ;
    char cVar ;
    
    public :
        static int siVar ;
        static float sfVar ;
        static char scVar ;
        
        sampleClass()
        {
            cout<<"This is the default constructor called for sampleClass \n";
        }
        static void function_to_do_something_1(int a , float b , char c )
        {
            siVar=a;
            sfVar=b;
            scVar=c;
            
            cout<<"static void function_to_so_something_1()..\n";
            // in a static function a non static data member cant be used
            // cout<<"iVar = "<<iVar;
            // cout<<"fVar = "<<fVar;
            // cout<<"cVar = "<<cVar;

            // this is the proof that the static function is associated with the class and not with the instance of the class           
            // cout<<"cVar = "<<this->cVar;

            // we can access the static data member in a static function 
            cout<<"siVar = "<<siVar<<endl;
            cout<<"sfVar = "<<sfVar<<endl;
            cout<<"scVar = "<<scVar<<endl;
         
        }
        void function_to_do_something(int a , float b , char c )
        {
            iVar=a;
            fVar=b;
            cVar=c;


            cout<<"void function_to_so_something()..\n";
            cout<<"this->iVar = "<<this->iVar<<endl;
            cout<<"this->fVar = "<<this->fVar<<endl;
            cout<<"this->cVar = "<<this->cVar<<endl;   
        }
};

// the static variable need to be assigned with values before used  
int sampleClass::siVar = 12;
float sampleClass::sfVar = 34.4545;
char sampleClass::scVar = 'r';


int main()
{
    cout<<"This is the program to understand static keyword on class data member and member function ..\n ";
    sampleClass * classObj = new sampleClass ;

    classObj->function_to_do_something(10,10.2323,'c');

    static int a=45;
    static float b=56.67;
    static char c ='t';

    // this is the error where the object cant call the static function 
    // classObj->function_to_do_something_1(12,13.2323,'d');
    
    // sampleClass::function_to_do_something_1(12,13.2323,'d');
    
    sampleClass::function_to_do_something_1(a,b,c);

    // classObj->function_to_do_something_1(a,b,c);
    
}