#include<iostream>
#include<queue>
using namespace std;


void printing_queue(queue<int> queue_var)
{
    cout<<"Queue data   :";
    while(!queue_var.empty())
    {
        cout << queue_var.front() << " " ;
        queue_var.pop();
    }
    cout<<"\n";
}

void pop_ele_from_array(int * array , int &size )
{
    // int size=array/array[0] // we cant do this 
    if(size>=0)
    {
        array[size-1]=0;
        size=size-1; 
    }
    else{
        cout<<"Array Empty\n";
    }
    
}

void function_to_add_ele(queue<int> queue_var , int * array)
{
    cout<<"Queue to Array insertion going on ..\n";
    int tmep_var=0;
    int index=0;
    while(!queue_var.empty())
    {
        tmep_var=queue_var.front();
        array[index]=tmep_var;
        queue_var.pop();
        ++index;
    }
}

void front_and_back(int *array , int& size )
{
    cout << "Front is  :  " << array[size-1] <<endl;
    cout << "Back is  :  " << array[size-size]<<endl;
}


int main()
{
    queue<int> queue_var;
    queue_var.push(10);
    queue_var.push(20);
    queue_var.push(30);
    queue_var.push(40);
    queue_var.push(50);

    printing_queue(queue_var);

    int size=queue_var.size();
    cout<<"the Size of the queue is : " << size << "\n"; 
    // int *array = new int[size];
    int *array = (int*) malloc(sizeof(int));
    function_to_add_ele(queue_var,array);    

    cout<<"Array data  : \n";
    for(int i=0;i<size;i++)
    {
        cout<< array[i]<< " ";
    }
    cout<<"\n";


    cout <<" ------------------- POP an element from array --------------------------\n";
    cout<<"Size before POP : "  << size<<"\n";
    pop_ele_from_array(array,size);
    cout<<"Size after POP : "  << size<<"\n";
    
    cout<<"Array data after POP   : \n";
    for(int i=0;i<size;i++)
    {
        cout<< array[i]<< " ";
    }
    cout<<"\n";

    cout <<" ------------------- Front and Back --------------------------\n";
    cout<<"Current Size is :: " << size<<"\n";
    front_and_back(array,size);    
}