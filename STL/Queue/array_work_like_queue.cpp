#include<iostream>
using namespace std;

void push(int * array , int &front , int &rear )
{   
    cout<<"Enter a value to insert to array : " ;
    int value ;
    cin>>value;

    if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
    }

    if(rear==0)
    {
        array[rear]=value;
        ++rear;
    }
    else     {
        array[rear]=value;
        ++rear;
    }
    
}

void pop(int * array , int &front , int &rear )
{
    if(rear <=0)
    {
        rear=-1  ;
        front=-1;
        cout<<"Array is empty ...\n";
    }

    else 
    {
        int temp_index=front ;
        while(temp_index<rear)
        {
            array[temp_index] = array[temp_index+1];
            temp_index++;

        }
    }
    if(rear!=-1 )
    {
        --rear;
    }


}

void front_and_back(int * array , int front , int rear )
{
    cout<<"The front of array is : " << array[front]<<"\n";
    cout<<"The back of array is " << array[rear-1]<<"\n";
}

void print_function(int * array , int rear )
{
    // for (int i=rear-1;i>=0;i--)
    // {
    //     cout<<array[i] << " " ;
    // }
    // cout<<"\n";

    for (int i=0;i<rear;i++)
    {
        cout<<array[i] << " " ;
    }
    cout<<"\n\n";

}
int main()
{
    int array[100];
    int front=-1;
    int rear=-1;
    
    push(array,front , rear);
    push(array,front , rear);
    push(array,front , rear);
    push(array,front , rear);
    push(array,front , rear);

    cout<<"\nArray looks like  : ";
    print_function(array,rear);
    front_and_back(array, front , rear );
    
    cout<<"\n\n";

    cout<<"Front = " << front << " Rear = " << rear <<"\n";
    cout<<"\nAfter 1 pop Array looks like  : ";
    pop(array,front,rear);
    print_function(array,rear);


    cout<<"Front = " << front << " Rear = " << rear <<"\n";
    cout<<"\nAfter 2 pop Array looks like  : ";
    pop(array,front,rear);
    print_function(array,rear);


    cout<<"Front = " << front << " Rear = " << rear <<"\n";
    cout<<"\nAfter 3 pop Array looks like  : ";
    pop(array,front,rear);
    print_function(array,rear);


    cout<<"Front = " << front << " Rear = " << rear <<"\n";
    cout<<"\nAfter 4 pop Array looks like  : ";
    pop(array,front,rear);
    print_function(array,rear);


    cout<<"Front = " << front << " Rear = " << rear <<"\n";
    cout<<"\nAfter 5 pop Array looks like  : ";
    pop(array,front,rear);
    print_function(array,rear);


    cout<<"Front = " << front << " Rear = " << rear <<"\n";
    cout<<"\nAfter 6 pop Array looks like  : ";
    pop(array,front,rear);
    print_function(array,rear);

    cout<<"Front = " << front << " Rear = " << rear <<"\n";
    cout<<"\nAfter 7 pop Array looks like  : ";
    pop(array,front,rear);
    print_function(array,rear);

    cout<<"Front = " << front << " Rear = " << rear <<"\n";
    cout<<"\nAfter 8 pop Array looks like  : ";
    pop(array,front,rear);
    print_function(array,rear);

    push(array,front , rear);
    cout<<"\nAfter Push Array looks like  : ";
    print_function(array,rear);
   
}
