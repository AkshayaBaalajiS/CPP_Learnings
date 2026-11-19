#include <iostream>
#include <optional>
using namespace std;


optional<int> function(bool var)
{
	if(var)
	{
		return 123;
	}
	else
	{
		return nullopt;
	}
}	

int main(int args, char ** argv)
{
	cout<<"This is the parent code \n";
	// int ref = function(); // this cant be done cause left is int and right is optional int 
	std::string sref = argv[1];
	std::cout<<"[DEBUG] = " << sref << std::endl;
	bool var ;

	if(sref=="true")
	{	
		var = true;
	}
	else
	{
		var = false;
	}

	optional<int> ref = function(var);

	if(ref.has_value())
	{
		cout<<"has value passed in the optional\n";
	}
	else
	{
		cout<<"has value failed in optional \n";
	}
	
}	