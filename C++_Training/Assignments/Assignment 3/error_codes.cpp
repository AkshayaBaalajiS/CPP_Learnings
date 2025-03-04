/*
1.
#include<iostream>
using namespace std;
void dummy (int ix=10 , int=200, float=777);
main()
{
int iNum1 = 5,iNum2 = 10, iNum3 = 100;
float fNum1 = 0.999999f,fNum2 = 100.99999f;
double dNum1 = 9999.9999,dNum2 = 68795.55555;
dummy(iNum1);
dummy(iNum1,iNum2);
dummy(iNum1,iNum2,iNum3);
 
}
void dummy(int ix, int iy, float iz)
{ cout <<ix <<" "<<iy<<" "<< iz <<endl; }
void dummy(int ix , int iy)
{ cout <<ix <<" "<<iy<<endl ;}

*/
/*
2.
#include<iostream>
using namespace std;
template <typename type1,typename type2>
// inline int max (int ,int );
// inline float max (float , float);
// inline double max (double , double );

// inline type1 max (type1 , type2 );
inline type1 max (type1 x ,type2 y )
{
    return (x>y?x:y);
} 
int main()
{
 int ival1,ival2;
 float fval1,fval2;
 double dval1,dval2;
 cout <<"Enter integers vals:" <<endl;
 cin >> ival1>>ival2;
 cout <<"Enter float vals:" <<endl;
 cin >> fval1>>fval2;
 cout <<"Enter double vals:" <<endl;
 cin >> dval1>>dval2;
 cout << max(ival1,ival2)<<endl;
 cout <<max (fval1,fval2)<<endl;
 cout <<fixed<<max (dval1,dval2)<<endl;
}

// int max(int x ,int y){
//  return(x>y?x:y);
// }
// float max (float x, float y){
//  return(x>y?x:y);
// }
// double max (double x, double y){
//  return(x>y?x:y);
// }
*/
/*
3.
#include<iostream>
using namespace std;
const float pi=3.14156;
class Circle{
 private:
 float radius, circumference;
 float area, diameter;
 public:
 Circle(){
 }
 Circle(float r){
 }
 void set_radius(float r){
 radius=r;
 }
 void fn_area(void){
    area = (3.14 * radius * radius);
 }
 void fn_circumference(void){
    circumference = (2 * 3.14 * radius);
 }
 void fn_diameter(void){
 diameter = 2*radius;
 }
 float get_radius(){
 return radius;
 }
 float get_diameter(){
 return diameter;
 }
 float get_area(){
 return area;
 }
 float get_circumference(){
 return circumference;
 }
};
int main()
{
 Circle c1(10.0);
 c1.set_radius(25.5);
 c1.fn_area();
 c1.fn_circumference();
 c1.fn_diameter();
 cout<<"radius is "<<c1.get_radius()<<endl;
 cout<<"diameter is "<<c1.get_diameter()<<endl;
 cout<<"Area is "<<c1.get_area()<<endl;
 cout<<"Circumference is "<<c1.get_circumference()<<endl; 
}
*/
/*
4.
#include<iostream>
using namespace std;
const float pi=3.14156;
class Circle{
 private:
 float radius, circumference;
 float area, diameter;
 public:
 Circle(){

 }
 Circle(float r){

 }
 void set_radius(float r){
 radius=r;
 }
 void fn_area(void){
    area = (3.14 * radius * radius);
 }
 void fn_circumference(void){
    circumference = (2 * 3.14 * radius);
 }
 void fn_diameter(void){
 diameter = 2*radius;
 }

 float get_radius(){
 return radius;
 }
 float get_diameter(){
 return diameter;
 }
 float get_area(){
 return area;
 }
 float get_circumference(){
 return circumference;
 }
};
int main()
{
 Circle c1(10.0);
 c1.set_radius(25.5);
 c1.fn_area();
 c1.fn_circumference();
 c1.fn_diameter();
 cout<<"radius is "<<c1.get_radius()<<endl;
 cout<<"diameter is "<<c1.get_diameter()<<endl;
 cout<<"Area is "<<c1.get_area()<<endl;
 cout<<"Circumference is "<<c1.get_circumference()<<endl;
}
*/
/*
4.
#include<iostream>
#include<cmath>
using namespace std;
class RTriangle{
 private:
 float base ;
 float height;
 float area;
 float perimeter;
 public:
 static float pi;
 RTriangle(){
 cout <<"Indefault constructor\n" ;
 }
 ~RTriangle(){cout<<"In destructor\n"; }
 RTriangle(float b, float h) : base(b) , height(h) {  }
 void setBase(float b){
 base =b;
 }
 void setHeight(float h){
 height =h;
 }
 float getBase(void){
 return base;
 }
 float getHeight(void){
 return height;
 }
 float getArea(void){
 return(area);
 }
 float getPerimeter(void){
 return (perimeter);
 }
 float fnArea(void);
 float fnPerimeter(void);
};
float RTriangle::pi=3.14156f;
float RTriangle::fnArea(void){
    return (0.5 * base * height);
}
float RTriangle::fnPerimeter(void){
    return (2*(base+height));
}
int main()
{

 RTriangle *ptr=NULL;
 ptr = new RTriangle(123.24,65.7213);
 cout <<"Area is : "<<ptr->fnArea()<<endl;
 cout <<"Perimeter is : "<<ptr->fnPerimeter()<<endl;

 cout <<"Pi is : "<<RTriangle::pi<<endl;
 delete ptr;
}
*/
/*
5.
#include<iostream>
using namespace std;
class Box{
 float height;
 float width;
 float length;
 float volume;
 float surfacearea;
 public:
 Box(){}
 Box(float h, float w, float l) : height(h) , width(w) , length(l)  { }
 Box(Box & b){ }
 void setHeight(float h){
 height = h;
 }
 void setLength(float l){

 }
 void setWidth(float w){

 }
 double fnVolume(){
    volume = length*width*height;
 }
 double fnsurfacearea(){
    surfacearea = (2*length*width)+(2*length*height)+(2*height*width);
 }
 float getVolume(){
    return volume;
 }
 float getSurfaceArea(){
    return surfacearea;
 }
 void Print(){
 cout <<"volume is : "<<volume<<endl;
 cout <<"surfacearea is:"<<surfacearea<<endl;
 }
 float getHeight(void){
    return height ;
 }
 float getLength(void){
    return length;
 }
 float getWidth(void){
 return width;
 }
};
int main()
{
 Box obj(12.6,21.3,41.5);
 obj.fnVolume();
 obj.fnsurfacearea();
 obj.Print();
 cout <<hex<<obj.getHeight()<<endl;
 cout <<obj.getLength()<<endl;
 cout <<obj.getVolume()<<endl;
}*/
/*
6.
#include<iostream>
#include<cstring>
using namespace std ;
class Book{

public:
    int price ;
    char * name ;
    int pages ;
    
    Book(const char *bn,int amt,const char *ch_name,int n,int p) : sub(ch_name,n,p)
    {
        name = new char[strlen(bn) + 1];
        strcpy(name, bn);
        price = amt;
        pages = p;   
    }
    void display(){
        cout << name<<endl;
        cout <<price<<endl;
        cout << pages<<endl;
        cout << "******chapter info ****" <<endl;
        sub.display();
    }

    class chapter {
        char chap_name[25];
        int number;
        int pages;
        public:
            chapter(){}
            chapter(const char *ch,int n,int p)
            {
                strcpy(this->chap_name,ch);
                number=n;
                pages=p;
            }
            void display(){
                cout << chap_name<<endl;
                cout <<number <<endl;
                cout << pages<<endl;
            }
    };
    private :
        chapter sub ;
    

};
int main()
{
    Book object("Understand C++ ",50,"Class and Objects" , 200,500);
    object.display();

}
*/
#include<iostream>
using namespace std;
class Array {
     int *data;
     int size;
     int capacity;
     int temp;
     int count ;
     public:
     Array(){
     data=nullptr;
     size=capacity=0;
     }
     Array(int sz){
    
     }
     Array(Array & ref ){
    
     }
     ~Array(){
         delete [] data;
         data=nullptr;
         ++count;
     }
     void addbeg(int val){
        data[0] = val ;
     }
     void append(int val){
        ++count;
        data[count] = val ;
     }
     void insert(int pos,int val){
         data[pos]=val;
    
     }
    
     int Size(){ 
        size=sizeof(Array);
        return size;
        }
     int deletebeg(){
    
        return temp;   
     }
     int deleteend(){
     --size;
     return data[size];
     }
     int delete_pos(int pos){
     int i, temp;
    
     return temp;
     }
     void Print(){
     int i, temp;
     for(i=0; i < size;i++)
     cout <<data[i]<<endl;
     }
     int getVal(int pos){
     return(data[pos-1]);
     }
};
int main()
{
 Array array(100);
 array.addbeg(10);
 array.append(20);
 array.insert(2,30);
 array.addbeg(100);
 array.append(200);
 array.insert(5,300);

 cout <<"Size of Array is"<<array.Size();
 cout <<"Data at "<<3<<array.getVal(3)<<endl;
 array.Print();
 cout <<"*******************************\n";
 cout <<array.deletebeg()<<endl;
 cout <<array.deleteend()<<endl;
 cout <<array.delete_pos(2)<<endl;
 cout <<"*******************************\n";
 array.Print();
 cout <<"Size of Array is"<<array.Size()<<endl;
 Array sec_obj(array);
 sec_obj.addbeg(10);
 sec_obj.append(20);
 sec_obj.insert(2,30);
 sec_obj.addbeg(100);
 sec_obj.append(200);
 sec_obj.Print();
 cout <<"Size of Array is"<<sec_obj.Size();
}