#include <iostream>
#include <sys/wait.h>
#include <sys/socket.h>
#include <arpa/inet.h> // sockaddr_in and htons and INADDR_ANY
#include "header.h"
using namespace std;
int main()
{
	cout<<"This is the server code to send the structure to client in C++ \n";

	int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

	sockaddr_in serverAddress;
	serverAddress.sin_port = htons(8080);
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = INADDR_ANY;

	bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress));

	listen(serverSocket, 10);

	int serverClient= accept(serverSocket, nullptr, nullptr );

	// char buffer[2056];
	// OutputStructure * output  = new OutputStructure();
	OutputStructure output;

	recv(serverClient, &output, sizeof(output),0);

	cout<<"output = " <<endl;
	cout<<output.name  <<endl;
	cout<<output.salary  <<endl;
	cout<<output.size  <<endl;
	// cout<<output.ar  <<endl;
}