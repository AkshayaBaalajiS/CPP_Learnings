#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cout<<"Check on how the vector is RAII\n";
	vector<int> vect1 = {12,23,34,45,56};
	vector<int> vect2 = std::move(vect1);

	for(int i=0;i<vect1.size();i++)
	{
		cout<<vect1[i] << "  " ;
	} 
	// no element printed above this prove the vector is RAII 
	for(int i=0;i<vect2.size();i++)
	{
		cout<<vect2[i] << "  " ;
	}
}