#include<iostream>
#include<queue>
using namespace std ;


void printing_ele_in_queue_front (queue<int> variable)
{
    cout<<"the queue :  ";
    while(!variable.empty())
    {
        cout<<variable.front()<<"  " ;

        variable.pop();
    }
}


int main()
{
    cout<<"This is the queue program \n";
    queue<int> queue_var ;
    int var;
    cout<<"Enter an ele to push in the queue \n";
    cin>>var;
    queue_var.push(var);


    cout<<"Enter an ele to push in the queue \n";
    cin>>var;
    queue_var.push(var);


    cout<<"Enter an ele to push in the queue \n";
    cin>>var;
    queue_var.push(var);


    cout<<"Enter an ele to push in the queue \n";
    cin>>var;
    queue_var.push(var);


    cout<<"Enter an ele to push in the queue \n";
    cin>>var;
    queue_var.push(var);

    cout<< "--------------------- The queue now  : --------------------- \n";
    printing_ele_in_queue_front(queue_var);
    cout<<"\n";

    cout<< "--------------------- Understanding Front and Back : --------------------- \n";
    cout<<"The front is   : " << queue_var.front()<<endl;
    cout<<"The back is   : " << queue_var.back()<<endl;
    cout<<"\n";

        
    cout<< "--------------------- Pop on queue  : --------------------- \n";
    queue_var.pop();
    cout<<"Queue after poping  : ";
    cout<<"\n";
    printing_ele_in_queue_front(queue_var);
    cout<<"\n";
    


    cout<< "--------------------- Size and Empty : --------------------- \n";
    cout<<"The Size is   : " << queue_var.size();
    queue_var.empty(); // empty is to check it is empty or not 
    cout<<"\n";
    
    cout<< "--------------------- Size After Empty : --------------------- \n";
    cout<<"The Size is   : " << queue_var.size();
    queue_var.empty();
    cout<<"\n";   


    // there is no method to insert in queue 
    // cout<< "--------------------- Insert and change values  : --------------------- \n";
    // cout<<"The Size is   : " << queue_var.size();
    // // queue_var.empty();
    // queue_var.inser
    // cout<<"\n";  
    
    //  cout<< "--------------------- Insert and change values  : --------------------- \n";
    // cout<<"The Size is   : " << queue_var.size();
    // queue_var.empty();
    // cout<<"\n";  
}