#include<iostream>
using namespace std;
/*
under std we have cout 
*/
namespace Group1{
    int gi=10;
// if a variable is uninitialized in the namespace it will be by default 0 
}

namespace Group2{
    int gi=20; // Group2::gi
}

namespace Group3{
    int gi=30; // Group2::gi
    void gfun()  // Group2::gfun
    {
        cout << "GI : "<< gi <<"\n";
    }
}
namespace Group3{
    int gj =12; // we can have multiple namespace on same group (it will be added )  
}

int main()
{
    int gi =20;
  
    cout<<"Local variable :  " ;
    cout << "gi : " << gi << " &gi :  " << &gi <<"\n" ;  

    cout<<"Value from Group1   :  ";
    cout << "Group1 gi : " << Group1::gi << " Group1 &gi :  " << &Group1::gi <<"\n";
   
    cout<<"Value from Group2   :  ";
    
    cout << "Group1 gi : " << Group2::gi << " Group2 &gi :  " << &Group2::gi <<"\n";
   
    
    {
        using namespace Group3;
        cout <<"GI : " << gi << "\n"; // here I am getting the local variable value 
        cout << "Fucntion call is done : \n";
        gfun();
    } // namespace Group3

   
}

/*
namespace G1{
    namespace G2 {
        namespace G3 {
            int a =10 ; G1::G2::G3::a  (outer , inner , innermost , gi) 
        }
    }
}




*/