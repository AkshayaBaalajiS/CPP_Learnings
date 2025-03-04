#include<iostream>
using namespace std ;

class Complex
{
    private :
        int real_num;
        int img_num;
    public :
        // here we have given the default argument because 
        // it act as single parameterized , dual parameterized , and default parameterized constructor    
        Complex(int a=0 , int b=0 ) 
        {
            real_num = a;
            img_num = b;
            
        }
        ~Complex()
        {
            cout<<"Real_num = " << real_num <<"  Imaginory_num = " << img_num <<"\n";   
        }
        int get_real()
        {
            return real_num ; 
        } 
        int get_img()
        {
            return img_num ; 
        } 
        void set_real(int val )
        {
            this-> real_num = val ;
        }
        void set_img(int val )
        {
            this-> img_num = val ;
        }

        // invalid operands of types 'void' and 'int' to binary 'operator+'   object + 5 + 3;
        // void operator + (int operand ) {
        //     cout<<"Void complex + (int operand  ) " << operand << "\n";
        //     this->img_num+=operand ;
        // }
        
        //(Complex * const this , int rhs  )
        Complex & operator + (int operand ) {
            cout<<"Void complex + (int operand  ) " << operand << "\n";
            this->img_num+=operand ;
            return *this ;
        }
        
};

/*
THis is unnecessary this can be easily done by
//This convert the expression to a funciton call 
Complex operator + (Complex & obj , int operand)
{
    cout<<"\nEntered the function ......................\n";
    obj.set_real(obj.get_real());
    obj.set_img(obj.get_img());
    
    Complex temp ;
    temp.set_img(obj.get_img() + operand);
    return temp ;
    
}
*/

int main()
{
    // Complex object ;  // -1  -1 because of the default constructor and there we have used default arguments 

    // Complex object_1(2);

    Complex object(10,23) ;

    object + 5 + 3;
    //object +5  (object.operator+(5)) +(object.operator(3))
    //then object + 3
       
    /*
    object +5 
    object.operator + (5);
    */

    // object + 4 ;
    /*
    object +4 ;
    This creates error so we use the operator overloading 
    
    */

}

//These are executed bottom to top because C++ is bottom up approach 