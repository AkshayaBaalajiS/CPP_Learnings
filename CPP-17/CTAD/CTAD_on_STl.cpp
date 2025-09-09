#include <iostream>
#include <tuple>
#include <vector>
#include <queue>

using namespace std;

struct A 
{
};

int main()
{
	cout<<"Program to understand the CTAD in STL\n";
	vector vec_int = {1,2,3,4,5,6,7};
	for(auto i : vec_int)
	{ 
		cout<< i <<"  " ;
	}
	cout<<endl; 	


	// queue is not a container it is a adaptor the constructor does not directly expose the type of ele 
	// queue queue_1= {12213,123123};

	// pair<int , string > pair1;
	// we are using the below instead of above 

	// pair on CTAD 
	pair pair_1 = {12, "Akshaya Baalaji"};
	cout<<"pair1 " <<  pair_1.first <<endl;
	cout<<"pair2 " <<  pair_1.second<<endl;
	
	pair<int , string > pair1; // this works cause the type is specified 
	// 	pair pair2 ; // this will not work cause the type not specified and the value are not given for deducing the type   

	pair<int , string > * pairPtr = new pair<int , string >()  ; // this works cause the type is specified 
	pairPtr->first = 2134;
	pairPtr->second = "aksha6ya Baalasji ";

	cout<<"Pointer of pair first = " << pairPtr->first <<endl;
	cout<<"Pointer of pair second = " << pairPtr->second<<endl;

	pair<int , string > * pairPtr1 = new pair<int , string >(12,"Akshaya VBALASUIF")  ; // this works cause the type is specified 
	cout<<"Pointer of pair first = " << pairPtr1->first <<endl;
	cout<<"Pointer of pair second = " << pairPtr1->second<<endl;

	// pair * pairPtr1 = new pair(12,"Akshaya VBALASUIF")  ; // this not works cause the type is not specified while using new ty=ry auto on lhs
	auto * pairPtr2 = new pair(12,"Akshaya VBALASUIF")  ; // this works cause the type is specified 	


	// tuple on CTAD 
	tuple tuple_1 = make_tuple(12,23.2323f, 'a', "Akshaya BaalajiS", new A());

}

