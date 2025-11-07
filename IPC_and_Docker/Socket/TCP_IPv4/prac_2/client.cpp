#include <iostream>
#include <sys/socket.h>
#include <sys/wait.h>
#include <cstring>
#include <arpa/inet.h>
#include "header.h"
using namespace std;

int main()
{
	cout<<"This is the client program to send the structure data in C++\n";
	int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

	sockaddr_in clientAddress ;
	clientAddress.sin_port = htons(8080);
	clientAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
	clientAddress.sin_family = AF_INET;

	connect(clientSocket, (struct sockaddr *)&clientAddress, sizeof(clientAddress));

	char arr[] = "SENTHILRAJ GOVINDASWAMY";
	// char buffer[4200]="Hi this is a message from client \nHope server is fine \n";
	// structure message 
	OutputStructure outputPtr ;
	// outputPtr.name = "Akshaya Baalaji S";
	outputPtr.salary = 23234.23432f;
	outputPtr.size  = 23;
	strcpy(outputPtr.name, "Akshaya Baalaji S");
	// outputPtr.ar = arr;

	send(clientSocket, (&outputPtr), sizeof(outputPtr),0);

}
/*
You cannot directly send() a structure that contains pointers or std::string because sockets transmit raw bytes, and pointers/strings contain addresses that are only valid in the client’s memory space.

*/
