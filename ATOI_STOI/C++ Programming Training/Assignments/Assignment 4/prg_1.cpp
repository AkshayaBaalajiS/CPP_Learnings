#include<iostream>
using namespace std ;
class MyType{
public:
    int value ;
    MyType(int args ) : value(args) {}
    void display ()
    {
        cout<<"The value is : " << value  << "\n"; 
    }
    // normal + operator overloading 
    void operator + (int arg) {
        this->value += arg ;
        cout<<"void operator + (int arg): arg = "<< this->value <<"\n";
    }
    // normal += operator overloading 
    void operator += (int arg) {
        this->value += arg ;
        cout<<"void operator += (int arg): arg = "<< this->value <<"\n";
    }
    // normal - operator overloading 
    void operator - (int arg) {
        this->value -= arg ;
        cout<<"void operator - (int arg): arg = "<< this->value <<"\n";
    }
    // normal -= operator overloading 
    void operator -= (int arg) {
        this->value -= arg ;
        cout<<"void operator -= (int arg): arg = "<< this->value <<"\n";
    }
    // normal * operator overloading 
    void operator * (int arg) {
        this->value *= arg ;
        cout<<"void operator * (int arg): arg = "<< this->value <<"\n";
    }
    // normal / operator overloading 
    void operator / (int arg) {
        this->value /= arg ;
        cout<<"void operator / (int arg): arg = "<< this->value <<"\n";
    }
    // == operator overloading 
    int operator == (MyType & rhs )
    {
        int temp =0;
        if(this->value == rhs.value )
        {
            temp = 23 ;
        }
        return temp ;
    }
    // object + object    + operator overloading 
    friend MyType operator + (MyType & firstOperand ,MyType & secondOperand) ;
    // << operator overloading 
    friend ostream & operator << ( ostream & os, MyType &rhs);
    // >> operator overloading 
    friend iostream & operator >> ( iostream & is, MyType &rhs);
    // new keyword overloading 
    friend void * operator new (size_t size ,int arg );
    //delete with subscript [] operator 
    void  operator delete [] (void * empty );
	~MyType()
	{
		cout<<"@ Destructor " << this << "\n";
	}
};
// + operator overloading 
MyType operator + (MyType & firstOperand ,MyType & secondOperand) {
        MyType temp(0) ;
        temp.value = secondOperand.value + firstOperand.value ; 
        cout<<"void operator + (MyType & secondOperand): "<< "\n";
        return temp ;
}
//< operator overloading 
int operator < ( MyType & lhs, MyType &rhs) {
    cout<<"int operator < ( MyType & lhs, MyType &rhs).\n";
    int temp;
    if(lhs.value < rhs.value)
    {
        temp= 21;
    }
    return temp ;
}
//> operator overloading 
int operator > ( MyType & lhs, MyType &rhs) {
    cout<<"int operator > ( MyType & lhs, MyType &rhs).\n";
    int temp;
    if(lhs.value > rhs.value)
    {
        temp= 22;
    }
    return temp ;
}
// << operator overloading 
ostream & operator << ( ostream & os, MyType &rhs) {
    os <<"ostream operator << ( ostream & os, MyType &rhs). " << "Value of the object is  : "<< rhs.value <<  "\n";
    return os ;
}
// >> operator overloading 
istream & operator >> ( istream & is, MyType &rhs) {
    cout <<"istream & operator >> ( istream & is, MyType &rhs) \n" ;
    int val ;
    cout <<"Enter a number : ";
    is >>val ; 
    rhs.value = val ;
    cout<< "Value of the object is  : "<< rhs.value <<  "\n";
    return is ;
}
//new operator overloading 
void * operator new (size_t size ,int arg )
{
    cout<<"void * operator new (size_t size ,int rhs )  \n";
    size=sizeof(MyType);
    MyType * ptr = new MyType(arg);
    return ptr ;
}
//delete with subscript [] operator overloading 
//void  operator delete [] (void * empty , MyType * ptr [] , int size  )
void  MyType::operator delete [] (void * empty )
{
    cout<<"operator delete [] (void * empty , MyType * ptr [] )  \n";
    MyType * temp= (MyType * ) empty ;
    // delete [] ptr ; // not working why ?
     // Calculate the number of elements in the array
    for (int i = 0; i < 3; ++i) {
        delete temp;
    }
}

int main(){
    MyType obj1(5), obj2(78) , obj3(0);
    
    cout<<"------------  object + num   + operator overloading  ---------------\n";
    //addiƟon
    obj1 + 16;
    cout<<"------obj1 + 16 :------->" << obj1.value << "<------------------\n";
    cout<<"-------------  - operator overloading  --------------\n";
    obj1 - 16;
    cout<<"-------obj1 - 16 :------>" << obj1.value << "<------------------\n";
    cout<<"-------------  -= operator overloading  --------------\n";
    obj1 -= 16;
    cout<<"-------obj1 -= 16 :------>" << obj1.value << "<------------------\n";
    cout<<"-------------  += operator overloading  --------------\n";
    obj1 += 16;
    cout<<"-------obj1 += 16 :------>" << obj1.value << "<------------------\n";
    cout<<"-------------  * operator overloading  --------------\n";
    obj1 * 5;
    cout<<"-------obj1 * 5 :------>" << obj1.value << "<------------------\n";
    cout<<"-------------  / operator overloading  --------------\n";
    obj1 / 5;
    cout<<"-------obj1 / 5 :------>" << obj1.value << "<------------------\n";
    cout<<"-------------  object + object    + operator overloading  --------------\n";
    obj3 = obj1 + obj2;
    cout<<"---------------------------\n";
    cout<<"------------->" << obj3.value << "<------------------\n";
    cout<<"--------------  < operator overloading  -------------\n";
    int result ;
    result = obj2 < obj1; 
    if(result==21)
    {
        cout<<"result = obj2 < obj1 :           Object 1 is greater \n";
    }
    
    cout<<"------------  > operator overloading  ---------------\n";
    result = obj2 > obj1; 
    if(result==22){
        
        cout<<"result = obj2 > obj1 :       Object 2 is greater \n";
    }
    
    cout<<"-----------  == operator overloading  ----------------\n";
    result =( obj2 == obj1); 
    if(result == 23 )
    {
        cout<<"result =( obj2 == obj1)             True \n";
    }
    else{
        cout<<"result =( obj2 == obj1)             False \n";
    }
    cout<<"-------------  + operator overloading  --------------\n";
    obj1 + 73; // for making it equal  
    cout<<"-------obj1 + 73 :------>" << obj1.value << "<------------------\n";
    cout<<"-------------  == operator overloading  --------------\n";
    result =( obj2 == obj1); 
    if(result == 23 )
    {
        cout<<"result =( obj2 == obj1)             True \n";
    }
    cout<<"------------  << operator overloading  ---------------\n";
    cout<<"cout<<obj1        : " << obj1 ;
    cout<<"\n";
    cout<<"-------------  >> operator overloading  --------------\n";
    cout<<"cin >> obj1   \n";
    cin >> obj1 ;
    cout<<"\n";
    cout<<"-------------  << operator overloading  --------------\n";
    cout<<"cout<<obj1        : " << obj1 ;
    cout<<"\n";

    cout<<"-------------  new  operator overloading  --------------\n";
    MyType *object = new (sizeof(MyType)) MyType (4);   // why it wont work without the size 
    object->display();
    cout<<"\n";
    
    cout<<"-------------  delete with [] subscript operator overloading  --------------\n";
    MyType * object_array[] = {new MyType(5) , new MyType(7) , new MyType(8)};   // why it wont work without the size 
    int size = sizeof(object_array) / sizeof(object_array[0]);
    delete [] object_array  ;
    cout<<"sizeof(object_array)      " << sizeof(object_array) <<"\n";
    cout<<"sizeof(object_array) / sizeof(MyType *)       " << sizeof(object_array) / sizeof(MyType *) <<"\n";
//    for(int i=0;i<(sizeof(object_array) / sizeof(MyType *));i++)
//	{
//		cout <<"object_array["<< i << "]  = " << object_array[i] <<"\n";
//		delete object_array[i];
//	}
    
    cout<<"\n";

    
    cout<<"-------------  some other operator will be overloaded in future   --------------\n";
    

} 