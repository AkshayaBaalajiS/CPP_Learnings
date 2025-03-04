/*
Write the definition for a class called Rectangle that has floating point data members length and width. The class has the 
following member functions: 
void setlength(float) to set the length data member 
void setwidth(float) to set the width data member 
float perimeter() to calculate and return the perimeter of the rectangle 
float area() to calculate and return the area of the rectangle 
void show() to display the length and width of the rectangle 
int sameArea(Rectangle) that has one parameter of type Rectangle. sameArea 
returns 1 if the two Rectangles have the same area, and returns 0 if they don't. 
    1. Write the definitions for each of the above member functions. 
    2. Write main function to create two rectangle objects. Set the length and width of 
    the first rectangle to 5 and 2.5. Set the length and width of the second rectangle to 
    5 and 18.9. Display each rectangle and its area and perimeter. 
    3. Check whether the two Rectangles have the same area and print a message 
    indicating the result. Set the length and width of the first rectangle to 15 and 6.3. 
    Display each Rectangle and its area and perimeter again. Again, check whether the 
    two Rectangles have the same area and print a message indicating the result. 
*/
#include<iostream>
using namespace std ;
class Rectangle
{
    friend int compare_rectangle(Rectangle & a , Rectangle & b) ;
    int length;
    int width ;
    public :
        void setlength(float args)
        {
            this->length = args ;
        }
        void setwidth(float args)
        {
            this->width = args ;
        }
        float perimeter()
        {
            return ((2*length)*(2*width));
        }
        float area(){
            return (length*width);
        }
        void show()
        {
            cout<<"The width is  " << width ;
            cout<<"The Length is  " << length ;
        }
};
int compare_rectangle(Rectangle & a , Rectangle & b)
{
    int result1 = a.area();
    int result2 = b.area();
    
    if(result1==result2)
    {

        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    Rectangle object , object1 ;
    object.setwidth(2.5);
    object.setlength(5);
    int length =5;
    int width=18.9;
    object1.setwidth(length);
    object1.setlength(width);
    cout<<"Rectangle 1 Area is : " << object.area() << " perimeter is : " << object.perimeter() << "\n";
    cout<<"Rectangle 2 Area is : " << object1.area() << " perimeter is : " << object1.perimeter();
    while(1)
    {
        cout<<"\nRectangles have different area ------------------- \n";
        cout<<"Enter the Length and width Again : \n";
        int length;
        int width;
        cin>>length;
        cin>>width;
        
        object1.setwidth(length);
        object1.setlength(width);
        int result = compare_rectangle(object , object1);
        if(result ==  1)
        {
            cout<<"Having same Area \n";
            break;
        }
        else{
            cout<<"Enter the correct length and width \n";
            
        }
        
    }

    

}