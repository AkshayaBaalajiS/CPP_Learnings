#include <iostream>
using namespace std;

namespace cStyle_Type_Csating{
    struct sA{};
    class cA{};

    void main()
    {
        cout<<"\n-----------------------------------------\n";
        cA caObj;
        sA saObj;
        cout<<"&saObj = "<<&saObj<<"\n";
        cout<<"&caObj = "<<&caObj<<"\n";
        cout<<"\n-----------------------------------------\n";
        void *vp = &saObj;
        cout<<"vp = "<<vp<<"\n";
        cout<<"\n-----------------------------------------\n";
        sA *sap = NULL;
        cA *cap = NULL;
        cout<<"sap = "<<sap<< " sizeof : " << sizeof(sap)<<"\n";
        cout<<"cap = "<<cap<< " sizeof : " << sizeof(cap)<<"\n";
        cout<<"\n-----------------------------------------\n";
        sap = (sA *) vp; //?
        cap = (cA *) (vp); //?
        cout<<"sap = "<<sap<< " sizeof : " << sizeof(sap)<<"\n";
        cout<<"cap = "<<cap<< " sizeof : " << sizeof(cap)<<"\n";
        cout<<"\n-----------------------------------------\n";
    }
}

int main()
{
    cStyle_Type_Csating::main();
}