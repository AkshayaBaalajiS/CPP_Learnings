#include <iostream>
#include <cstring>
#include <yaml-cpp/yaml.h>

using namespace std;

char * ptr = new char [50];

class BadFile
{
	public:	
		BadFile()
		{
			cout<<"@ BadFile constructor \n";
		}
		friend ostream & operator << (ostream & out, BadFile & ref)
		{
			out<<"YAML BadFile : File is not there in specified path";
			return out; 
		}
		~BadFile()
		{
			cout<<"@ BadFile destructor \n";
		}
};

int main()
{
	cout<<"This is the program to understand the YAML\n";
	
	strcpy(ptr, "YAML File not loaded properly");

	try{
		YAML::Node nodeObj = YAML::LoadFile("config.yml");
		YAML::Node subNode = nodeObj["Attendance"];
		YAML::Node subsubNode = subNode["1"];
		string name = subsubNode["name"].as<string>();
		// string name = subsubNode["Name"].as<string>(); // Error on main : bad conversion
		cout<<"name = " << name<<endl;

		int Roll = subsubNode["Roll"].as<int>();
		cout<<"Roll = " << Roll <<endl;

		int Age = subsubNode["Age"].as<int>();
		cout<<"Age = " << Age <<endl;
		
		string Address = subsubNode["Address"].as<string>();
		cout<<"Address = " << Address <<endl;
		
	}
	catch(const char * pptr)
	{
		cout<<"Error on main : " << *pptr << endl;
	}
	catch(const YAML::Exception & e)
	{
		cout<<"Error on main : " << e.what() <<endl;
	}

}