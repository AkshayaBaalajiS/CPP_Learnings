#include <iostream>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>

using namespace std;

struct dataStructure
{
	int intdata;
	char charData;
	char charPointer[200];
	float floatPointer[5];
};
int main()
{
	cout<<"IPv4 based TCP socket communication \n";
	int serverDesc = socket(AF_INET, SOCK_STREAM, 0);

	sockaddr_in serverDetail;
	serverDetail.sin_port = htons(8080);
	serverDetail.sin_family = AF_INET;
	serverDetail.sin_addr.s_addr = INADDR_ANY;

	bind(serverDesc, (struct sockaddr *)&serverDetail, sizeof(serverDetail));

	listen(serverDesc, 10);

	int clientDescriptor = accept(serverDesc, nullptr, nullptr);
	dataStructure * clientDataStructure = new dataStructure();

	recv(clientDescriptor, clientDataStructure, sizeof(*clientDataStructure), 0);
	std::cout<< "Int data = " << clientDataStructure->intdata<<std::endl;
	std::cout<< "Char data = " << clientDataStructure->charData<<std::endl;
	std::cout<< "char data[] = " << clientDataStructure->charPointer<<std::endl;
	std::cout<< "float data[] = " << clientDataStructure->floatPointer[0] <<"  " << clientDataStructure->floatPointer[1] <<"  " << clientDataStructure->floatPointer[2] <<"  " << clientDataStructure->floatPointer[3] <<std::endl;
	

}