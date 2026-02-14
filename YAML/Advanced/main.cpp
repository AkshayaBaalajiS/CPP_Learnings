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
		cout<<"-------------------------------------------\n";
		for(int i=1;i<=3;i++)
		{
			YAML::Node subsubNode = nodeObj["Attendance"][to_string(i)] ;
			{
				string name = subsubNode["name"].as<string>();
				// string name = subsubNode["Name"].as<string>(); // Error on main : bad conversion
				cout<<"name = " << name<<endl;

				int Roll = subsubNode["Roll"].as<int>();
				cout<<"Roll = " << Roll <<endl;

				int Age = subsubNode["Age"].as<int>();
				cout<<"Age = " << Age <<endl;
				// safe way to use YAML
				if(subsubNode["phno"])
				{
					string number = subsubNode["phno"].as<string>();
				}
				cout<<"number does not exist\n";
				
				string Address = subsubNode["Address"].as<string>();
				cout<<"Address = " << Address <<endl;
				if(i==1) // list 
				{	cout<<"City MOved on  : " ;
					for(auto it : subsubNode["city"])
					{
						cout<< it <<" ";
					}
					cout<<endl;
				}
				if(i==2) // map 
				{	cout<<"City Moved on  : " ;
					for(auto it : subsubNode["city"]) // this is possible if it is map 
					{
						cout<<it.first.as<string>() << " " << it.second.as<string>() << " || " ;
					}
					cout<<endl;
				}
				if(i==3) // list of map
				{
					int counter = 0;
					cout<<"City Moved on  : ";
					for(auto it : subsubNode["city"])
					{
						for(auto node1 : it)
						{
							cout<<node1.first.as<int>() << "  " << node1.second.as<string>() << " || ";
						}	
					}
					cout<<endl;
				}
				cout<<endl;
			}
		}
		cout<<"-------------------------------------------\n";
		for(auto it : subNode)
		{
			int number  = it.first.as<int>();
			cout<<"Number = " << number <<endl;

			YAML::Node stude = it.second["name"];
			string name = stude.as<string>(); 
			cout<<"name = " << name<<endl;

			int Roll = it.second["Roll"].as<int>();
			cout<<"Roll = " << Roll <<endl;

			int Age = it.second["Age"].as<int>();
			cout<<"Age = " << Age <<endl;
			
			string Address = it.second["Address"].as<string>();
			cout<<"Address = " << Address <<endl;
			cout<<endl;
		}
		cout<<"-------------------------------------------\n";

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