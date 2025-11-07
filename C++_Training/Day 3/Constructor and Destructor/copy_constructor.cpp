#include<iostream>

using namespace std ;

class new_class
{
    
    int x,y,z ;
    public :
        new_class(int a =-1 ,int b=-2,int c=-3)  //this can run even on a default , single , two , three parameterized constructor 
        {
            x=a ;
            y=b;
            z=c;
            cout<<"X = " << x << "      Y = " << y << "     Z = " << z <<"\n";
        }

        //copy constructor
        new_class(new_class & obj)
        {
            cout<<"Copy constructor : " << this << "\n";
            this->x = x;
            this->y = y;
            this->z = z;
            cout<<"X = " << x << "      Y = " << y << "     Z = " << z <<"\n";
            
        }
};


int main()
{   
   
    new_class c_object4(12,54,34);

    //copy constructor  -- assume always 
    new_class c_object5 (c_object4);
    

}