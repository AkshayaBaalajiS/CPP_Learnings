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
        int return_result(int args )
        {
            number = args ;

            int result ;

            int temp=0 , temp1=0 , temp2=0 ;
            int first=0 , second=0 , third=0 ;
            first = number/100;
            number = number%100 ;
            second = number/10;
            third = number%10;

            temp = factorial(first);
            temp1 = factorial(second);
            temp2 = factorial(third);

            result = temp+temp1+temp2;
            
            return result ;

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

        int number ;
        cout<<"Enter the number \n";
        cin>>number;

        
        int return_val = object.return_result(number);
        if(number == return_val)
        {
            cout<<"Entered Number  " << number <<" is Shakunthala number " <<"\n";
        }

    }
}