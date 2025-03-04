#include<iostream>
using namespace std;
 
struct A
{
	int i;
	A():i(-1)
	{
		cout<<"i= "<<i<<  this <<" \n";
	}
	int getValue()
	{
		return i;
	}
    int* getAddress()
    {
		return &i;
	}
};
 
 
struct B:A
{
	int j;
	B():j(-2)
	{
		cout<<"j= "<<j<<  this <<" \n";
	}
	int getValue()
	{
		return i;
	}
    int* getAddress()
	{
		return &i;
	}
};
 
 
struct C:A
{
	int k;
	C():k(-3)
	{
		cout<<"k= "<<k<<  this <<" \n";
	}
	int getValue()
	{
		return i;
	}
    int* getAddress()
	{
		return &i;
	}
};
 
 
struct D:B,C
{
	int l;
	D():l(-4)
	{
		cout<<"l= "<<l<<  this <<" \n";
	} 
};
 
void size()
{
	cout<<"sizeof(A)="<<sizeof(A)<<"\n";	
	cout<<"sizeof(B)="<<sizeof(B)<<"\n";
	cout<<"sizeof(C)="<<sizeof(C)<<"\n";
	cout<<"sizeof(D)="<<sizeof(D)<<"\n";
}
 
int main()
{
	D obj;
	size();
	cout<<"----------------------------------------------------\n";
	cout<<"&obj="<<&obj<<"\n";
	// cout<<"obj.i="<<obj.i<<"&obj.i="<<&obj.i<<"\n";
	cout<<"obj.j="<<obj.j<<"&obj.j="<<&obj.j<<"\n";
	cout<<"obj.k="<<obj.k<<"&obj.k="<<&obj.k<<"\n";
	cout<<"obj.l="<<obj.l<<"&obj.l="<<&obj.l<<"\n";
	return 0;

}
 