#include "header.hpp"
#include <cstring>
using namespace std;

void NameSpace::DataStructure::change_value(int intData, char charData, float floatData, double doubleData, string stringData)
{
	this->intData=intData;
	this->charData=charData;
	this->floatData=floatData;
	this->doubleData=doubleData;
	strcpy(this->charArr, stringData.c_str());
}

void NameSpace::DataStructure::print_values()
{
	cout<<"intData = " << this->intData << endl;
	cout<<"charData = " << this->charData << endl;
	cout<<"floatData = " << this->floatData << endl;
	cout<<"doubleData = " << this->doubleData << endl;
	cout<< "charArr = " << this->charArr <<endl;
}



