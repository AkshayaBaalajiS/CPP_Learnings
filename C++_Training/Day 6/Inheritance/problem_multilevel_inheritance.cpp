#include<iostream>
using namespace std;
 
class base{
    int i;
    public :
        base (int arg =-1){
            i=arg;
            cout<<"constructor1\n";
        }
        ~base();
        void f1();
};
 
class derived_1 : public base{
    int j;
    public:
        derived_1 (int arg2 =-2) : base (arg2){
            j=arg2;
            cout<<"constructor2\n";
        }
        derived_1 (int arg1,int arg2 ) : base (arg2){
            j=arg1;
            cout<<"constructor2\n";
        }
         ~derived_1();
        void f2();
};
class derived_2 : public derived_1{
    int k;
    public:
        derived_2 (int arg1) : k(arg1)
        {
            // k=arg3;
            cout<<"constructor3\n";
        }
        derived_2 (int arg1 , int args2 ) : k(args2)
        {
            // k=arg3;
            cout<<"constructor3\n";
        }
        derived_2(int arg1=1,int arg2=1 ,int arg3=1) : k(arg3)
        {
           // k=arg3;
           cout<<"derived_2 multi :\n";
        }
         ~derived_2();
        void f3();
};
base ::~base(){
    cout <<"destructor1\n";
}
void base :: f1(){
    cout << "f1 = "<<i<<"\n";
   
};
derived_1 ::~derived_1(){
    cout <<"destructor2\n";
}
void derived_1 :: f2(){
    cout << "f2 = "<<j<<"\n";
   
};
derived_2 ::~derived_2(){
    cout <<"destructor3\n";
}
void derived_2 :: f3(){
    cout << "f2 = "<<k<<"\n";
   
};
 
 
int main(){
    derived_1 obj(10);

//     derived_2 obj(45);
//     derived_2 obj(45,34);
//     derived_2 obj1(10,20,30);
//     cout <<"______________________\n";
// //    obj.f1();
// //    obj.f2();
// //    obj.f3();
//     cout<<"___________________________\n";
//    // derived_2 obj2(20);
 
}