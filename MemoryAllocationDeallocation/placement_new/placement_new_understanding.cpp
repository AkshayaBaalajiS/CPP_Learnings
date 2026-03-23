#include <iostream>
using namespace std;

int main()
{
	cout<<"This is the program to understand the placement new in cpp\n";

	float * placementNew = new float[1000];

	float * arr = new(placementNew) float();
	float * arr1 = new(placementNew + sizeof(float)) float(); // mem allocated is 4 * 4 = 16
	arr[0] = 123; // 4
	arr[1] = 123.234; // 8
	arr[2] = 123.345; // 12 
	arr[3] = 123.345; // 16 

	arr[4] = 123.345; // 20 <---- this address is assigned to arr1 so print arr1 will get this value
	arr[5] = 123.345;
	// arr[6] = 123.345;


	// arr1[0] = 35;
	// arr1[1] = 35.234;
	// arr1[2] = 35.345;

	cout<<"----------------------------\n";
	cout<<"arr[0] = " << arr[0] <<endl;
	cout<<"arr[1] = " << arr[1] <<endl;
	cout<<"arr[2] = " << arr[2] <<endl;
	cout<<"----------------------------\n";

	cout<<"----------------------------\n";
	cout<<"placementNew[0] = " << placementNew[0] <<endl;
	cout<<"placementNew[1] = " << placementNew[1] <<endl;
	cout<<"placementNew[2] = " << placementNew[2] <<endl;
	cout<<"----------------------------\n";

	cout<<"----------------------------\n";
	cout<<"arr1[0] = " << arr1[0] <<endl;
	cout<<"arr1[1] = " << arr1[1] <<endl;
	cout<<"arr1[2] = " << arr1[2] <<endl;
	cout<<"----------------------------\n";

	
	
}