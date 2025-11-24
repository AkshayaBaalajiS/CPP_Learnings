#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	cout<<"This is the code to see how the fixed and precession work \n";

	float fvar = 23.234234234234f;
	cout<<"Float var before fixed applied : " <<  fvar <<endl;
	cout<<std::fixed << std::setprecision(10) << " Precision set to 10 \n";
	cout<<"Float var after fixed applied : " <<  fvar <<endl;
	
}