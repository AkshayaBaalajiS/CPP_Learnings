#include <iostream>
#include <fstream>
#include <yaml-cpp/yaml.h>
#include <map>
using namespace std;

void createmem(YAML::Node & node)
{
	YAML::Node details ;
	details["Name"] = "Akshaya baalaji S";
	details["age"] = 23;
	details["Address"] = "Thanjavur";
	std::list<string> strr = {"TNJ", "MAS", "BLR"};
	details["City"] = strr;
	std::map<int, string> mmap;
	mmap[1] = "TNJ";
	mmap[2] = "MAS";
	mmap[3] = "BLR";
	details["City City"] = mmap;

	
	YAML::Node details1 ;
	details1["Name"] = "Baalaji S";
	details1["age"] = 23;
	details1["Address"] = "Thanjavur";
	std::list<string> strr1 = {"TVR", "MAS", "BLR"};
	details1["City"] = strr1;
	// std::map<int, string> mmap;s
	mmap[1] = "TVR";
	mmap[2] = "MAS";
	mmap[3] = "BLR";
	details1["City City"] = mmap;


	std::map<int, YAML::Node> mmapp;
	mmapp[1] = details;
	mmapp[2] = details1;
	

	node["Attendance"] = mmapp;

}

int main()
{
	cout<<"This is the program to create YAML from code \n";

	YAML::Node node;
	createmem(node);

	
	ofstream fff("config_created.yml");
	fff<< node;
}