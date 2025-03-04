
#include<iostream>
using namespace std ;


void function_1 ();

int main()
{
    cout<<"Main started \n" ;
    try{
        function_1();
    }
    catch(int error_number)
    {
        cout<<"The error occurs at : " << error_number <<"\n";
    }
    cout<<"Main Ended \n" ;
    

}
void function_1()
{
    cout<<"Fucntion started \n" ;
    throw(10);
    cout<<"Fucntion Ended \n" ;
}
/*
#include <iostream>
using namespace std;

void gfun();
int main()
{
    cout << "main start" << "\n";
    try{
        gfun();
    }
    catch(int errno)
    {
        cout << "Error no : " << errno << "\n";
    }
    catch(...)
    {
        cout<<"Any error will be catched here \n";
    }
    cout << "main end" << "\n";
}

void gfun()
{
    cout << "gfun start" << "\n";
    throw(-1);
    cout << "gfun end" << "\n";
}
*/


/*
This abrupty stop when it finds the throw stmt on function 
#include<iostream>
using namespace std ;

void function_1()
{
    cout<<"Fucntion started \n" ;
    throw(-1);
    cout<<"Fucntion Ended \n" ;
    
}

int main()
{
    cout<<"Main started \n" ;
    function_1();
    cout<<"Main Ended \n" ;
    

}*/


