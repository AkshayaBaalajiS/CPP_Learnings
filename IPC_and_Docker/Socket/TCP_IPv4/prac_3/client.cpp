#include <iostream>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <cstring>
#include "header.h"
using namespace std;
int main()
{
	cout<<"This is the program to understand the client side of the Socker in C++\n";

	int clientSock = socket(AF_INET, SOCK_STREAM, 0);
	sockaddr_in  clientAddr ;
	clientAddr.sin_port = htons(8080);
	clientAddr.sin_family = AF_INET;
	clientAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	connect(clientSock, (struct sockaddr *)&clientAddr, sizeof(clientAddr)); 

	Data obj;
	strcpy(obj.message , "Hi this is the message from client side, Hope you are doing well");
	obj.age = 23;
	obj.obj.salary =123123.234f;

	send(clientSock, &obj, sizeof(obj), 0);
	close(clientSock);

}