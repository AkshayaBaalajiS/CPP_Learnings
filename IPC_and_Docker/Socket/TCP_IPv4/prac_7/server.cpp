#include <iostream>
#include <chrono>
#include <cstring>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include "header.hpp"

using namespace std;

int main()
{
	cout<<"This is the server code for receiving the data from the client \n";

	int serverSock = socket(AF_INET, SOCK_STREAM, 0);
	sockaddr_in serverAddress;
	serverAddress.sin_port = htons(8080);
	serverAddress.sin_addr.s_addr = INADDR_ANY;
	serverAddress.sin_family = AF_INET;

	bind(serverSock, (struct sockaddr * )&serverAddress, sizeof(serverAddress));

	listen(serverSock, 10);

	int clientSock = accept(serverSock, nullptr, nullptr);

	DataStructure obj;
	recv(clientSock, &obj, sizeof(obj),0);

	cout<<"intData  = " << obj.intData <<endl;
	cout<<"charArrData  = " << obj.charArrData <<endl;
	cout<<"floatData  = " << obj.floatData <<endl;
	cout<<"doublData  = " << obj.doublData <<endl;

	char buffer[100];
	strcpy(buffer, "This is the message from server side, I received the Message of structure you sent \n");

	send(clientSock, buffer, sizeof(buffer), 0);

}