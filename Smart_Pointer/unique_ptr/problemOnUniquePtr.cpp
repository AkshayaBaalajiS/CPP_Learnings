#include <iostream>
#include <memory>
using namespace std;

int main()
{
	cout<<"Program to understand the memory leak \n";
	int arr[] ={12,23,34,45,56,76};

	unique_ptr<int *> uniq = make_unique<int*>(arr);
	cout<<"Ptr holds arr " << (*uniq)[0] << " " << (*uniq)[1] << " " << (*uniq)[2] << " " << (*uniq)[3] <<endl;

	uniq = make_unique<int *>(new int[20]); // here the old pointer is auto freed 
	// fill((*uniq[0])[0], (*uniq[0])[19],1); // why *uniq[0] will not work ? cause uniq holds int * 
	fill((*uniq), (*uniq)+19,1);
	cout<< " Unique Ptr of pointer " << (*uniq)[20];
	// undefined behaviour on accessing the the value > size 
	cout<<"Unique ptr of pointer holds  " << (*uniq)[0] << " " << (*uniq)[1] << " " << (*uniq)[2] << "  " << (*uniq)[3] << "  "<< (*uniq)[4]<< "  Now we are accessing the size +1 " << (*uniq)[21] << "  " << (*uniq)[22]  <<endl;

	// unique_ptr for array 
	// make_unique<T[]>(size_t n) thisis the signature 
	unique_ptr<int []> upp =  make_unique<int []> (5);
	upp[0] =23;
	upp[1] =23;
	upp[2] =23;
	upp[3] =23;
	upp[4] =23;
	// the below line is wrong and that is happening cause 
	// unique_ptr<T[]> does NOT do bounds checking
	upp[5] =23;
	
	cout<<"Unique ptr " << upp[0] << " " << upp[1] << " " << upp[2] << "  " << upp[3] << "  "<< upp[4] << "  "  <<endl;
	// even it gives value this is undefined behaviour 
	cout<< upp[5]<< endl;

	// this is also a issue with poointers
	int * ptrrr = new int[5];
	for(int i=0;i<10;i++)
	{
		ptrrr[i] =  345;
		cout<<"ptrrr["<< i <<  "] " << ptrrr[i] << "  ";
	}
	cout<<endl;
}