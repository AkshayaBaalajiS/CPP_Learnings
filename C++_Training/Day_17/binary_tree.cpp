#include <iostream>
using namespace std;

struct Node{
    int public_data;
    Node * left_child;
    Node * right_child;
    Node(int data):public_data(data)
    {
        left_child=right_child=nullptr;
    }
};

void create_tree(Node ** p,int value){
    if(!*p) // checking  NULL
        *p=new Node(value);
    else // if not NULL 
        value < (*p)->public_data ? create_tree((&(*p)->left_child),value) : create_tree((&(*p)->right_child),value);
//      if the value is less than data ->create_tree((&(*p)->left_child),value)   // lest left pointer 
//                          else ->create_tree((&(*p)->right_child),value)          //right child pointer 
}
void pre_order(Node *p){
    if(p){
        cout<<p->public_data<<",";
        pre_order(p->left_child);
        pre_order(p->right_child);
    }
}
void in_order(Node *p){
    if(p){
        in_order(p->left_child);
        cout<<p->public_data<<",";
        in_order(p->right_child);
    }
}
void post_order(Node *p){
    if(p){
        post_order(p->left_child);
        post_order(p->right_child);
        cout<<p->public_data<<",";
    }
}

int main(){
    int arr[]={23,1,143,420,111,96,7,21,14},n=9;
    Node * root = nullptr;
    
    for(int i=0;i<n;i++)
        create_tree(&root,arr[i]);
    cout<<"----------------------\n";
    pre_order(root);
    cout<<"\n";
    cout<<"-------------------------------\n";
    in_order(root);
     cout<<"\n";
    cout<<"-------------------------------\n";
    post_order(root);
     cout<<"\n";
    cout<<"-------------------------------\n";
}
