#include <iostream>
#include <cstdlib>
#include <string> 
using namespace std;

int main(){
	  // Strings to be used for conversion
  
  string st1 = "200";
  string st2 = "1.252";
  string st3 = "Welcome";
  string st4 = "100 Welcome";
  
  
//   const char* str1 = "200";
//   const char* str2 = "1.252";
//   const char* str3 = "Welcome";
//   const char* str4 = "100 Welcome";


  const char* str1 = st1.c_str();
  const char* str2 = st2.c_str();
  const char* str3 = st3.c_str();
  const char* str4 = st4.c_str();
  // using atoi() in C++
//   int i1 = atoi(st1) ; //  proof that atoi takes the const char * as primary argument 
//   int i1 = atoi(str1);
  int i2 = atoi(str2);
  int i3 = atoi(str3);
  int i4 = atoi(str4);
  cout << "Integer 1 is : " << i1 << endl;
  cout << "Integer 2 is : " << i2 << endl;
  cout << "Integer 3 is : " << i3 << endl;
  cout << "Integer 4 is : " << i4 << endl;


  int i5 = stoi(st1.c_str()); // proof that const char * can also be given here 
//   int i6 = stoi(st2);// excepts integer but there is floating point 
//   int i7 = stoi(st3); // expects integer but there is no integer 
  int i8 = stoi(st4);
  cout << "Integer 5 is : " << i5 << endl;
//   cout << "Integer 6 is : " << i6 << endl;
//   cout << "Integer 7 is : " << i7 << endl;
  cout << "Integer 8 is : " << i8 << endl;

}