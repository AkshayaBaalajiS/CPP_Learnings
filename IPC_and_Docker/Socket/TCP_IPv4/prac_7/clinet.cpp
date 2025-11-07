#include <iostream>
#include <thread>
#include <sys/wait.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <chrono>
#include <cstring>
#include "header.hpp"

using namespace std;

int main()
{
	cout<<"This is the program to understand the client side of the socket programming \n";

	int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	sockaddr_in clientAddress;
	clientAddress.sin_port = htons(8080);
	clientAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
	clientAddress.sin_family = AF_INET ;

	connect(clientSocket, (struct sockaddr *)&clientAddress, sizeof(clientAddress));


	DataStructure obj;
	obj.intData=12;
	strcpy(obj.charArrData, "This is the data from the client ");
	obj.floatData=234.12312f;
	obj.doublData=45645.12312d;

	send(clientSocket, &obj, sizeof(obj),0);
	char buffer[100];
	recv(clientSocket, buffer, sizeof(buffer), 0);
	cout<<"This is the message from server : " << buffer<<endl;
	close(clientSocket);


};

