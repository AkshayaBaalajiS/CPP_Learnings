#include <iostream>
using namespace std;

namespace NameSpace
{
	struct DataStructure{
		int intData;
		char charData;
		float floatData;
		double doubleData;
		char charArr [1000];

		void change_value(int intData, char charData, float floatData, double doubleData, string stringData);
		void print_values();

	};
}

