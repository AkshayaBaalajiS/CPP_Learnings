#include<iostream>
#include<deque>
using namespace std  ;
void function_to_print_from_back(deque<int> dequeu_var)
{
    cout<<"The deque var holds : ";
    while(!dequeu_var.empty())
    {
        cout << dequeu_var.back() <<" " ;
        dequeu_var.pop_back(); 
    }
}

void function_to_print_from_front(deque<int> dequeu_var)
{
    cout<<"The deque var holds : ";
    while(!dequeu_var.empty())
    {
        cout << dequeu_var.front() <<" " ;
        dequeu_var.pop_front(); 
    }
}

int main()
{
    deque<int> deque_var;
    int temp_var;
    
    cout << "----------------------------- push_front ----------------------------------\n";
    cout<<"Enter a number : ";
    cin>>temp_var;
    deque_var.push_front(temp_var);

    cout<<"Enter a number : ";
    cin>>temp_var;
    deque_var.push_front(temp_var);

    cout<<"Enter a number : ";
    cin>>temp_var;
    deque_var.push_front(temp_var);

    cout<<"Enter a number : ";
    cin>>temp_var;
    deque_var.push_front(temp_var);

    cout<<"Enter a number : ";
    cin>>temp_var;
    deque_var.push_front(temp_var);

    // function_to_print_from_back(deque_var);
    function_to_print_from_front(deque_var);
    cout << "---------------------------------------------------------------------------------\n";

    cout << "----------------------- push_back ----------------------------\n";
    cout<<"Enter a number : ";
    cin>>temp_var;
    deque_var.push_back(temp_var);

    cout<<"Enter a number : ";
    cin>>temp_var;
    deque_var.push_back(temp_var);

    cout<<"Enter a number : ";
    cin>>temp_var;
    deque_var.push_back(temp_var);

    cout<<"Enter a number : ";
    cin>>temp_var;
    deque_var.push_back(temp_var);

    cout<<"Enter a number : ";
    cin>>temp_var;
    deque_var.push_back(temp_var);
    
    function_to_print_from_front(deque_var);
    cout << "---------------------------------------------------------------------------------\n";


    cout << "------------------------- Size of -------------------------------\n";
    cout<<"The size is  :  " << deque_var.size() << "\n";
    cout<<"The Max size is  :  " << deque_var.max_size()<<"\n";
    cout << "---------------------------------------------------------------------------------\n";

    cout << "------------------------- Insert -------------------------------\n";
    deque_var.insert(deque_var.begin()+5,110);
    function_to_print_from_front(deque_var);
    cout << "---------------------------------------------------------------------------------\n";

    cout << "------------------------- Front and Back -------------------------------\n";
    cout<<"The element at front is : " << deque_var.front();
    cout<<"\nThe element at back is : " << deque_var.back();
    
    cout << "\n---------------------------------------------------------------------------------\n";

    cout << "------------------------- Begin & End -------------------------------\n";
    cout<<"the element at beginiing is  : "<< *deque_var.begin() << "\n";
    cout<<"the element at end is  : " << *deque_var.end() << "\n";
    cout<<"the element at end -1 is  : "<< *((deque_var.end())-1) << "\n";
    
    cout << "---------------------------------------------------------------------------------\n";


    
    

}