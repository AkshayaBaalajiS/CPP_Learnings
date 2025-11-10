#include <iostream>
#include <optional>
using namespace std;

decltype(auto) assign_value(auto & optional_v, int * var)
{
	if(var!=nullptr)
	{
		optional_v = optional<int *>(var);
	}
	return nullopt;
}

bool check_value(optional<int *> optional_v)
{
	if(optional_v.has_value())
	{
		cout<<"Optional has value \n";
		return true;
	}
	else {
		cout<<"Optional has no value \n";
	}
	return false;
}


int main()
{
	cout<<"This is the program to understand the optional in cpp \n";

	optional<int *> optional_v;

	int array[50];
	
	check_value(optional_v);

	assign_value(optional_v, array);

	check_value(optional_v);

}