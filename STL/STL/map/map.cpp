#include <iostream>
#include <map>
using namespace std;

int main()
{
	cout<<"This is the code to understand the map in cpp\n";
	map<int, float> map1;
	
	cout<<"--- insert -------\n";
	// inserting element 1
	map1[1] = 93.324f;
	map1[0] = 83.324f;
	map1[2] = 73.324f;
	map1[3] = 63.324f;
	map1[4] = 53.324f;
	
	// inserting element way 2 
	map1.insert({5,324.453f});
	map1.insert({5,23.453f}); // only unique elemnt to be inserted so it silently fails here 

	// for(auto i: map1)
	for(std::pair<int, float> i: map1)
	{
		cout<<i.first << " " << i.second <<endl;
	}
	cout<<"------------------------\n";
	
	cout<<"------ erase -------\n";
	auto it =  map1.begin();
	map1.erase(it); // erase by element 
	map1.erase(5); // erase by id  
	
	for(std::pair<int, float> i: map1)
	{
		cout<<i.first << " " << i.second <<endl;
	}
	cout<<"------------------------\n";

	cout<<"------ indexing -------\n";
	cout<<"map1[0] = " << map1[0] <<endl;
	cout<<"map1[1] = " << map1[1] <<endl;
	cout<<"map1[2] = " << map1[2] <<endl;
	cout<<"------------------------\n";

	cout<<"------ size and empty -------\n";
	cout<<"The size of the map = " << map1.size() <<endl;
	cout<<"Map is empty or not = " << map1.empty() <<endl;
	cout<<"------------------------\n";


}
