/*
This problem is to get you familiar with virtual functions. Create three classes Person, Professor and Student. The class Person should have data members name and age. The classes Professor and Student should inherit from the class Person.

The class Professor should have two integer members: publications and cur_id. There will be two member functions: getdata and putdata. The function getdata should get the input from the user: the name, age and publications of the professor. The function putdata should print the name, age, publications and the cur_id of the professor.

The class Student should have two data members: marks, which is an array of size  and cur_id. It has two member functions: getdata and putdata. The function getdata should get the input from the user: the name, age, and the marks of the student in  subjects. The function putdata should print the name, age, sum of the marks and the cur_id of the student.

For each object being created of the Professor or the Student class, sequential id's should be assigned to them starting from .

Solve this problem using virtual functions, constructors and static variables. You can create more data members if you want.

Note: Expand the main function to look at how the input is being handled.

Input Format

The first line of input contains the number of objects that are being created. If the first line of input for each object is , it means that the object being created is of the Professor class, you will have to input the name, age and publications of the professor.

If the first line of input for each object is , it means that the object is of the Student class, you will have to input the name, age and the marks of the student in  subjects.


Sample Input

4
1
Walter 56 99
2
Jesse 18 50 48 97 76 34 98
2
Pinkman 22 10 12 0 18 45 50
1
White 58 87
Sample Output

Walter 56 99 1
Jesse 18 403 1
Pinkman 22 135 2
White 58 87 2

*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Person
{
    public :
        string name;
        int age;  
        
        virtual void getdata()=0;  
        virtual void putdata()=0;
        virtual ~Person() {};
};

class Professor :  public  Person
{
    public :
        static int cur_id;
        Professor()
        {
        }    
    
        int publications;
        // int cur_id;
        void getdata()
        {
            cin>>name>>age>>publications;
        }
        void putdata()
        {
            cur_id++;
            cout<<name << " " << age << " " << publications << " " << cur_id << endl; 
        }
        ~Professor () {}
};
int Professor::cur_id = 0;

class Student :  public Person
{
    public :
        static int cur_id;
        Student()
        {
        }
        int arr[6];
        void getdata()
        {
            cin>>name>>age;
            for(int i=0;i<6;i++)
            {
                int temp;
                cin>>temp;
                arr[i]=temp;
            }
            // cur_id++;
            
        }
        void putdata()
        {
            int sum =0;
            
            for(int i=0;i<6;i++)
            {
                sum=sum+arr[i];    
            }
            cur_id++;
            
            cout<<name << " " << age << " "<<sum<<" " <<cur_id<<endl;
            
            
        }
        ~Student (){}
    
};
int Student::cur_id = 0;


int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
