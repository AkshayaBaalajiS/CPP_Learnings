#include<iostream>
#include<cstring>
using namespace std ;
class c_cashOnHand 
{
    int cashOnHand=0;
    public:
        c_cashOnHand() : cashOnHand(0) {}
        // c_cashOnHand(int args=-1) : cashOnHand(args) {}
        int getCurrentBalance(int args)
        {
            this->cashOnHand -=args;
            // cout<<"Value on cashOnHand " << cashOnHand << " \n";
            return cashOnHand ;
        }
        void acceptAmount(int a )
        {
            this->cashOnHand =a ;
        }
};
class dispenserType
{   
    int numberofitems ; 
    int cost ;
    public :
        dispenserType() : cost(50) , numberofitems(50) {} 
        dispenserType(int args1 , int args2) : cost(args1) , numberofitems(args2) {} 
        int gerNoOfItems()
        {
            return numberofitems;
        }
        int getCost( int args )
        {
            this->cost =args ;
            return (cost);
        }
        void makeSale()
        {
            this->numberofitems -= 1;
        }

};
int main()
{
    int chips = 10;
    int candies =1 ;
    int gum=1 ;
    int cookies = 5;
    dispenserType object ;
    c_cashOnHand object_1;
    char need [5];
    while(1)
    {
        cout<<"\n we have \n1.candies\n2.chips\n3.gum\n4.cookies\n";
        int choice ;
        cin>>choice ;
        switch(choice)
        {
            case 1:
                cout<<"Cost of the candies : " << candies <<"\n";
                cout<<"Type Yes to Deposit  : ";
                cin>>need;
                if(strcmp(need , "Yes")==0)
                {
                    cout<<"Enter the money to dispense : ";
                    int money ;
                    cin>> money ;
                    object_1.acceptAmount(money);
                    int balence =object.getCost(candies);
                    if(balence>0)
                    {
                        cout<<"You have purchased the product and the this is your balence : " << object_1.getCurrentBalance(balence)<<"\n";
                        object.makeSale();
                        cout<<"The number of candies in dispenser is : " << object.gerNoOfItems();
                    }
                    else{
                        cout<<"Not sufficient money ";
                    }

                }
                break;
                
            case 2:
                cout<<"Cost of the chips : " << chips <<"\n";
                cout<<"Type Yes to Deposit  : ";
                cin>>need;
                if(strcmp(need , "Yes")==0)
                {
                    cout<<"Enter the money to dispense : ";
                    int money ;
                    cin>> money ;
                    object_1.acceptAmount(money);
                    int balence =object.getCost(chips);
                    cout<<"You have purchased the product and the this is your balence : " << object_1.getCurrentBalance(balence)<<"\n";
                    object.makeSale();
                    cout<<"The number of chips in dispenser is : " << object.gerNoOfItems();
                }
                break;

            case 3:
                cout<<"Cost of the gum : " << gum <<"\n";
                cout<<"Type Yes to Deposit  : ";
                cin>>need;
                if(strcmp(need , "Yes")==0)
                {
                    cout<<"Enter the money to dispense : ";
                    int money ;
                    cin>> money ;
                    object_1.acceptAmount(money);
                    int balence =object.getCost(gum);
                    cout<<"You have purchased the product and the this is your balence : " << object_1.getCurrentBalance(balence)<<"\n";
                    object.makeSale();
                    cout<<"The number of gum in dispenser is : " << object.gerNoOfItems();    
                }
                break;

            case 4:
                cout<<"Cost of the cookies : " << cookies  <<"\n";
                cout<<"Type Yes to Deposit  : ";
                cin>>need;
                if(strcmp(need , "Yes")==0)
                {
                    cout<<"Enter the money to dispense : ";
                    int money ;
                    cin>> money ;
                    object_1.acceptAmount(money);
                    int balence =object.getCost(cookies);
                    cout<<"You have purchased the product and the this is your balence : " << object_1.getCurrentBalance(balence) << "\n";
                    object.makeSale();
                    cout<<"The number of cookies in dispenser is : " << object.gerNoOfItems() << "\n";
                    
                }
                break;


            default:
                cout<<"Enter choice properly" << candies <<"\n";

                
        }
        
    }
}