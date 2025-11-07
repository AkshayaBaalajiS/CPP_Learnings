#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>

struct dataStructure
{
	int intdata;
	char charData;
	char charPointer[200];
	float floatPointer[5];
};

using namespace std;

int main()
{
	cout<<"IPv4 based TCP client socket code \n";

	int clientDesc = socket(AF_INET, SOCK_STREAM,0);

	sockaddr_in clientDet;
	clientDet.sin_port = htons(8080);
	clientDet.sin_family = AF_INET;
	clientDet.sin_addr.s_addr = inet_addr("127.0.0.1");

	connect(clientDesc, (struct sockaddr *)&clientDet, sizeof(clientDet));


	float array[5] = {12,23,34,45,56};
	char * pointer = "Hi Akshaya Baalaji S, this data is originated by parent process and write on pipe ";
	dataStructure * parentDataStructure =  new dataStructure();
	parentDataStructure->charData = 'a';
	parentDataStructure->intdata = 123;
	// strcpy(parentDataStructure->charPointer,pointer ) ; // for proving memcpy can be used for string also 
	memcpy(parentDataStructure->charPointer, pointer, strlen(pointer)) ; // can be used for string also 
	memcpy(parentDataStructure->floatPointer, array, sizeof(array)) ;
	
	send(clientDesc, parentDataStructure, sizeof(*parentDataStructure),0);




}