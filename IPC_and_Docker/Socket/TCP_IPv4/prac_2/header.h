#include <iostream>

struct OutputStructure
{
	// std::string name;
	float salary;
	int size;
	// char * ar;
	char name[1000];
};

/*
You cannot directly send() a structure that contains pointers or std::string because sockets transmit raw bytes, and pointers/strings contain addresses that are only valid in the client’s memory space.
*/
