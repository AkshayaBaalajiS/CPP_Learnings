#include<iostream>
using namespace std ;

class A 
{
    int admno ; 
    char sname[20] ; 
    float eng , math, science ; 
    float total ; 
    float ctotal()
    {
        return (eng+math+science);
    } 
    public :
        void takedata(int a ,char *array , float e , float sci)
        {
            int count;
            int i=0;
            for(;array[i]!='\0';i++)
            {
                sname[i]=array[i];
            }
            sname[i]='\0';
            admno = a;
            eng = e;
            science = sci ;
        }
        int result = ctotal();
        void showdata()
        {
            cout <<"Addno = " << admno << " sname = " <<sname  <<" eng =" << eng << " science = " << science <<"\n";  
        }
};
int main()
{
    A object ;
    // char *array="Akshay";  //working proper 
    char array[]="Akshay"; //not working proper why 
    object.takedata(10,array, 50.34 , 23.32);
    object.showdata();
}