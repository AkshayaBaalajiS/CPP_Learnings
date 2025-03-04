#include<iostream>
using namespace std ;

// #define GETMAX(x,y) (x>y?x:y)  // preprocessor way  
/*
Macro :
    Advantage :
        inlined 
        Formula need to bec hanged at a palce 
        No need of funtion call frames of memory or context-switch
        Generic  - as it is generic it can be applied even for the doubl datatype 
        it imporoves performance 
        There is no need of prologue and epilogue 

    Disadvantage :
        Code segment blockage 
        Not that much intelligent 
*/




//inline is similar to preprocessor way of execution and 
// it a form of request to compailer it can also be ignored by compailer 
// inline int GETMAX(int x , int y ) // this is compailer function way 
// {
//     return(x>y?x:y);
// }
/*
Inline : INstructs the compiler the return value to validate automatically instead of storing it in a variable and using it 
    Advantage : 
        Function overloading with inline keyword gives all advantage of macro
        Reduce the function call overhead 

    Disadvantage :
        NOt generic if we give the double instead of int argument the floating point is ignored 
        - function overloading is the solution of this for GETMAXii to GETMAXdd  
*/


//for making the inline work similar to macro we are doing this 
template<typename type1> //template is a blueprint 
inline type1 GETMAX (type1 x , type1 y) // function overloading done here 
{
    return(x>y?x:y);
}


template<typename type1, typename type2> //template is a blueprint for the function overloading 
//                  create multiple copies of different (datatypes parameters ) and (different return type )  
inline type1 GETMAX (type1 x , type2 y) // function overloading done here 
{
    return(type2(x>y?x:y));
}

int main()
{
    int i=10 , j=20 ;
    cout << " i = " << i << " j = " << j << "\n";
    cout << "GETMAX(i,j)  :" << GETMAX(i,j) << "\n";
    cout << " i = " << i << " j = " <<j << "\n";
    cout <<"\n\n";
    cout << " i = " << i << " j = " << j << "\n";
    cout << "GETMAX(i,j)  :" << GETMAX(i++,j++) << "\n";
    //                          i++ > j++ ? i++ : j++ ;  10 >20 ? i++ : j++
    //                                                              11   21
    //                                                                    j++ -> 22 
    cout << " i = " << i << " j = " <<j << "\n";
    
    cout <<"\n\n";

    double x=21.23 , y=324.234; 
    cout << " x = " << x << " y = " << y << "\n";
    cout << "GETMAX(x,y)  :" << GETMAX(x++,y++) << "\n";
    cout << " x = " << x << " y = " <<y << "\n";

    //Explicit way of generating the templates 
    cout << "GETMAX(x,y)  :" << GETMAX<int>(x++,j++) << "\n";
    // GETMAX ii - GETMAX <int> every thing is converted to int 
    // GETMAX dd  - GETMAX <double> every thing is converted to double 

    
    //Explicit way of generating the templates for reducing the chance of the ambiguity 
    cout << "GETMAX(i,j)  :" << GETMAX<int>(i,j) << "\n"; 
    // GETMAX ii - GETMAX <int> every thing is converted to int 
    cout << "GETMAX(x,y)  :" << GETMAX<int>(x,y) << "\n"; 
    // GETMAX dd  - GETMAX <double> every thing is converted to double 
 


    //the below is at the time of craetion of template with 2 args typename
    cout << "GETMAX(x,j)  :" << GETMAX(x,j) << "\n"; 
    // GETMAX di due to //template<typename type1, typename type2> //template is a blueprint 


    // overloading 
    cout << "GETMAX(x,j)  :" << GETMAX<int,float>(j,x) << "\n";
    // GETMAXid 
    cout << "GETMAX(x,j)  :" << GETMAX<int>(x,j) << "\n"; 
    //GETMAXii



}