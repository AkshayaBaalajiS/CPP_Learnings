#include <iostream>
#include <optional>
using namespace std;


// int function()
// {
//     return 10;
// }

/// creating a monadic class type 

std::optional<int> function()
{
    return 10;
}

class Sample 
{
    public:
    int variable1 ;
    int variable2 ;
        Sample()
        {
            cout<<"This @Sample class constructor \n";
        }
        
        ~Sample()
        {
            cout<<"This @Sample class destructor \n";
        }
        
};

int main()
{
    cout<<"This is the code to prac the addvanced lambda in cpp \n";
    int variable = 21;

    Sample obj;

    auto lambda = [=]() -> int
    {
        cout<<"Value can be accessed \n";
        cout<<"variable = " << variable << std::endl;
        return -1;
    };

    auto lambda1 = [&]() -> int
    {
        cout<<"Value can be accessed \n";
        cout<<"variable value changed = " <<( variable = 12) << std::endl;
        obj.variable1 = 23;
        obj.variable2 = 23;
        
        return 1;
    };

    lambda();
    lambda1();

    cout<<"Local Variable = " << variable <<endl;
    cout<<"obj.variable1 = " << obj.variable1 <<endl;
    cout<<"obj.variable2 = " << obj.variable2 <<endl;
    

    std::optional<int> (*funcPtr)()   = function;
    // cout<<" function pointer return  = " << funcPtr() << std::endl;

    // and then try in cpp 
    funcPtr().and_then([](int ref ) -> std::optional<int>
    {
        cout<<"Reference  = " << ref << std::endl;
        return ref;
    });

}