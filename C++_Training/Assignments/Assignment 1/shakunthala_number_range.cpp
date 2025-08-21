#include<iostream>
using namespace std ; 
class A 
{
    int number ;
    public :
        A()
        {
            cout<<"@ Constructor \n";
        }
        int factorial(int n)
        {
            int result=1;
            for(int i=1;i<=n;i++)
            {
                result=result*i;
            }
            return result ;
        }
        int return_result(int a)
        {
            int sum ;
            int fibonocci;
            int number = a;
            int rem=0;
            while(number!=0)
            {
                rem = number%10;
                number=number/10;
                sum = sum+factorial(rem);
            }
            fibonocci = sum ;
            sum =0 ;
            return fibonocci ;
        }

        ~A()
        {
            cout<<"@ Destructor \n";
        }
};
int main()
{
    {
        A object;

        int start ;
        cout<<"Enter the start number ";
        cin>>start;

        cout<<"\n";

        int end ;
        cout<<"Enter the end number ";
        cin>>end;
        cout <<"\n";
        for(int i=start; i<=end;i++)
        {
            int return_val = object.return_result(i);
            if(i == return_val)
            {
                cout<<"Entered Number  " << i <<" is Shakunthala number " <<"\n";
            }
        }
        cout<<"\n";
    }
}