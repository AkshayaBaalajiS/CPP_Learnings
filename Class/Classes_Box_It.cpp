/*
Design a class named Box whose dimensions are integers and private to the class. The dimensions are labelled: length , breadth , and height .

The default constructor of the class should initialize , , and  to .

The parameterized constructor Box(int length, int breadth, int height) should initialize Box's  and  to length, breadth and height.

The copy constructor BoxBox ) should set  and  to 's  and , respectively.

Apart from the above, the class should have  functions:

int getLength() - Return box's length
int getBreadth() - Return box's breadth
int getHeight() - Return box's height
long long CalculateVolume() - Return the volume of the box

Box b1; // Should set b1.l = b1.b = b1.h = 0;
Box b2(2, 3, 4); // Should set b1.l = 2, b1.b = 3, b1.h = 4;
b2.getLength(); // Should return 2
b2.getBreadth(); // Should return 3
b2.getheight(); // Should return 4
b2.CalculateVolume(); // Should return 24
bool x = (b1 < b2); // Should return true based on the conditions given
cout<<b2; // Should print 2 3 4 in order.


*/

#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)
class Box 
{
    int l;
    int b;
    int h;
    public:
        Box():l(0), b(0), h(0)
        {
            
        }  
        Box(int l, int b, int h )
        {
            this->l = l;
            this->b = b;
            this->h = h;
        }
        Box(Box & ref )
        {
            // cout<<"Oh oH"<<endl;
            this->l=ref.l;
            this->b=ref.b;
            this->h=ref.h;
            
        }
        int getLength()
        {
            return l;
        }
        int getBreadth()
        {
            return b;
        }
        int getHeight()
        {
            return h;
        }
        long long CalculateVolume()
        {
            // cout<<"Volume = ";
            return (long long)this->l*this->b*this->h;
        }
        bool operator < (Box & ref )
        {
            if(this->l < ref.l )
            {
                return true;
            }
            else if(this->b < ref.b && this->l == ref.l)
            {
                return true;
            }
            else if(this->h < ref.h && this->b == ref.b && this->l== ref.l)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        friend ostream & operator << (ostream & out, Box & ref );
};

ostream & operator << (ostream & out, Box & ref )
{
    out<< ref.l << " " << ref.b << " " << ref.h ;
    return out;
}


void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}