#include<iostream>
using namespace std ;


class PPP {
	int H;
	protected :
		int S;
	public :
		void input (int);
		void out();
};
class QQQ : private PPP {
		int T;
	protected :
		int U;
	public :
		void indata(int, int);
		void outdata();
};
class RRR : public QQQ {
		int M;
	public :
		void disp()
		{
			cout<<"M : " << M  <<"\n";
			cout<<"U : " << U  <<"\n";
//			cout<<"U : " << S  <<"\n"; this cant be done 
		}
};
int main()
{
	RRR object ;
	object.disp();	
}

//Name the base class and derived class of the class QQQ. 
// base class - PPP and the derived class - RRR

// Name the data member(s) that can be accessed from function disp().
// the datamember accessed by the disp is M (private data member of the class M ) U (protected data ,member of QQQ class )

// Name the member function(s), which can be accessed from the objects of class RRR. 
// disp() , indata(int , int ) , outdata() 

//Is the member function out() accessible by the object of the class QQQ?
//no 
