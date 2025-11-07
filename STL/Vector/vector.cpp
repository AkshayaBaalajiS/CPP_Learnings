#include<iostream>
#include<vector>
using namespace std;

void print_vector(vector<int> vector_variable)
{
    while(!vector_variable.empty())
    {
        cout<< vector_variable.back()<< " " ;
        vector_variable.pop_back(); 
    }
    cout<<"\n";

}

void print_vec_like_array(vector<int> vector_variable)
{
    for (int i=0;i<vector_variable.size();i++)
    {
        cout <<vector_variable[i] << " " ; 
    }
    cout<<"\n";
}

int main()
{
    vector<int> vector_variable ;

    vector<bool> vector_bool;
       cout<<"--------------------- Vector Size ---------------------- \n";
    
    cout<<"Vector Size : " << vector_bool.size() << "\n";

    cout<<"Size of Vector variable : " << sizeof(vector_bool) << "\n";
    cout<<"Size of Vector of int : " << sizeof(vector<int>) << "\n";
    cout<<"Size of Vector of double : " << sizeof(vector<double>) << "\n";
    cout<<"Size of Vector of float : " << sizeof(vector<float>) << "\n";
    
    
    cout <<"--------------------- PUSH ---------------------- \n";
    int temp_var;
    
        cout<<"Enter a number to push to vector ..\n";
    cin>>temp_var;
    vector_variable.push_back(temp_var);
    cout<<"--------------------- Vector Size ---------------------- \n";
    
    cout<<"Vector Size : " << vector_variable.size() << "\n";

    cout<<"Size of Vector : " << sizeof(vector_variable) << "\n";

    cout<<"Capacity of the vector : " << vector_variable.capacity()<<"\n";

    
        cout<<"Enter a number to push to vector ..\n";
    cin>>temp_var;
    vector_variable.push_back(temp_var);


    cout<<"--------------------- Vector Size ---------------------- \n";
    
    cout<<"Vector Size : " << vector_variable.size() << "\n";

    cout<<"Size of Vector : " << sizeof(vector_variable) << "\n";
    cout<<"Capacity of the vector : " << vector_variable.capacity()<<"\n";
    
    
        cout<<"Enter a number to push to vector ..\n";
    cin>>temp_var;
    vector_variable.push_back(temp_var);

    cout<<"--------------------- Vector Size ---------------------- \n";
    
    cout<<"Vector Size : " << vector_variable.size() << "\n";

    cout<<"Size of Vector : " << sizeof(vector_variable) << "\n";
    cout<<"Capacity of the vector : " << vector_variable.capacity()<<"\n";
    

    
    
    cout<<"Enter a number to push to vector ..\n";
    cin>>temp_var;
    vector_variable.push_back(temp_var);
    cout<<"--------------------- Vector Size ---------------------- \n";
    
    cout<<"Vector Size : " << vector_variable.size() << "\n";

    cout<<"Size of Vector : " << sizeof(vector_variable) << "\n";
    cout<<"Capacity of the vector : " << vector_variable.capacity()<<"\n";
    


    
    
    cout<<"Enter a number to push to vector ..\n";
    cin>>temp_var;
    vector_variable.push_back(temp_var);
    cout<<"--------------------- Vector Size ---------------------- \n";
    
    cout<<"Vector Size : " << vector_variable.size() << "\n";

    cout<<"Size of Vector : " << sizeof(vector_variable) << "\n";
    cout<<"Capacity of the vector : " << vector_variable.capacity()<<"\n";
    


    
    
    cout<<"Enter a number to push to vector ..\n";
    cin>>temp_var;
    vector_variable.push_back(temp_var);
    cout<<"--------------------- Vector Size ---------------------- \n";
    
    cout<<"Vector Size : " << vector_variable.size() << "\n";

    cout<<"Size of Vector : " << sizeof(vector_variable) << "\n";
    cout<<"Capacity of the vector : " << vector_variable.capacity()<<"\n";
    


    

    cout<<"Enter a number to push to vector ..\n";
    cin>>temp_var;
    vector_variable.push_back(temp_var);
    cout<<"--------------------- Vector Size ---------------------- \n";
    
    cout<<"Vector Size : " << vector_variable.size() << "\n";

    cout<<"Size of Vector : " << sizeof(vector_variable) << "\n";
    cout<<"Capacity of the vector : " << vector_variable.capacity()<<"\n";
    


    

    cout<<"Enter a number to push to vector ..\n";
    cin>>temp_var;
    vector_variable.push_back(temp_var);
    cout<<"--------------------- Vector Size ---------------------- \n";
    
    cout<<"Vector Size : " << vector_variable.size() << "\n";

    cout<<"Size of Vector : " << sizeof(vector_variable) << "\n";
    cout<<"Capacity of the vector : " << vector_variable.capacity()<<"\n";
    


    

    cout<<"Enter a number to push to vector ..\n";
    cin>>temp_var;
    vector_variable.push_back(temp_var);
    cout<<"--------------------- Vector Size ---------------------- \n";
    
    cout<<"Vector Size : " << vector_variable.size() << "\n";

    cout<<"Size of Vector : " << sizeof(vector_variable) << "\n";
    cout<<"Capacity of the vector : " << vector_variable.capacity()<<"\n";
    


    

    cout<<"Enter a number to push to vector ..\n";
    cin>>temp_var;
    vector_variable.push_back(temp_var);
    cout<<"--------------------- Vector Size ---------------------- \n";
    
    cout<<"Vector Size : " << vector_variable.size() << "\n";

    cout<<"Size of Vector : " << sizeof(vector_variable) << "\n";
    cout<<"Capacity of the vector : " << vector_variable.capacity()<<"\n";
    


    

    cout<<"Enter a number to push to vector ..\n";
    cin>>temp_var;
    vector_variable.push_back(temp_var);
    cout<<"--------------------- Vector Size ---------------------- \n";
    
    cout<<"Vector Size : " << vector_variable.size() << "\n";

    cout<<"Size of Vector : " << sizeof(vector_variable) << "\n";
    cout<<"Capacity of the vector : " << vector_variable.capacity()<<"\n";
    


    

    cout<<"--------------------- Printing vector like array printing with index  ---------------------- \n";
    print_vec_like_array(vector_variable);

    cout<<"--------------------- Printing vector like queue printing ---------------------- \n";
    // it will print in reverse order as it is printing from back 
    print_vector(vector_variable);

    cout<<"--------------------- Front and Back ---------------------- \n";
    cout<<"Front : " << vector_variable.front() << "\n";
    cout<<"Back : " << vector_variable.back() << "\n";

    cout<<"--------------------- Insert  ---------------------- \n";
    
    cout<<"Enter a number to insert to vector ..\n";
    cin>>temp_var;
    // vector_variable.insert(3,temp_var); // this cant be done as we have to pass the iterator as the firest argument 
    vector_variable.insert(vector_variable.begin()+3,temp_var);

    cout<<"--------------------- Printing vector like array printing with index  ---------------------- \n";
    print_vec_like_array(vector_variable);

    cout<<"--------------------- Begin and End   ---------------------- \n";
    
    cout<<"Begin : " << *vector_variable.begin() << "\n";
    cout<<"Begin +1 : " << *((vector_variable.begin())+1) << "\n";
    cout<<"Begin +2 : " << *((vector_variable.begin())+2) << "\n";
    cout<<"Begin +3 : " << *((vector_variable.begin())+3) << "\n";

    
    cout<<"end : " << *vector_variable.end() << "\n";
    cout<<"end -1 : " << *((vector_variable.end())-1) << "\n";
    cout<<"end -2 : " << *((vector_variable.end())-2) << "\n";
    cout<<"end -3 : " << *((vector_variable.end())-3) << "\n";

    
    cout<<"--------------------- at ---------------------- \n";
    
    cout<<"at : " << vector_variable.at(0) << "\n";
     

    
    cout<<"--------------------- POP ---------------------- \n";
    
    vector_variable.pop_back();
    cout<<"--------------------- Printing vector like array printing with index  ---------------------- \n";
    print_vec_like_array(vector_variable);

    cout<<"--------------------- Printing vector like queue printing ---------------------- \n";
    print_vector(vector_variable);

    cout<<"--------------------- Printing vector with for each ---------------------- \n";
    // print_vector(vector_variable);
    for(int i : vector_variable)
    {
        cout<< i <<" " ;
    }
    cout<<"\n";


    cout<<"--------------------- Vector Size ---------------------- \n";
    
    cout<<"Vector Size : " << vector_variable.size() << "\n";

    cout<<"Size of Vector : " << sizeof(vector_variable) << "\n";
    cout<<"Capacity of the vector : " << vector_variable.capacity()<<"\n";




    cout<<"--------------------- Vector Size ---------------------- \n";
    
    cout<<"Vector Size : " << vector_variable.size() << "\n";

    cout<<"Size of Vector : " << sizeof(vector_variable) << "\n";
    cout<<"Capacity of the vector : " << vector_variable.capacity()<<"\n";


    cout<<"After 4 pop : \n";
    vector_variable.pop_back();
    vector_variable.pop_back();
    vector_variable.pop_back();
    vector_variable.pop_back();
     
    cout<<"Vector Size : " << vector_variable.size() << "\n";

    cout<<"Size of Vector : " << sizeof(vector_variable) << "\n";
    cout<<"Capacity of the vector : " << vector_variable.capacity()<<"\n";
    
    cout<<"After the shrink_to_fit called : \n";
    vector_variable.shrink_to_fit();
      cout<<"--------------------- Vector Size ---------------------- \n";
    
    cout<<"Vector Size : " << vector_variable.size() << "\n";

    cout<<"Size of Vector : " << sizeof(vector_variable) << "\n";
    cout<<"Capacity of the vector : " << vector_variable.capacity()<<"\n";


    
    

    

    

}