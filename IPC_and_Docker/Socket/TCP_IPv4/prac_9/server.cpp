#include <iostream>
#include <thread>
#include <sys/socket.h>
#include <arpa/inet.h>
using namespace std;

int main()
{
	cout<<"Server.cpp code \n";
	int serverDesc = socket(AF_INET, SOCK_STREAM, 0);
	sockaddr_in serverDet;
	serverDet.sin_port = htons(8080);
	serverDet.sin_addr.s_addr = INADDR_ANY;
	serverDet.sin_family = AF_INET;

	bind(serverDesc, (struct sockaddr *)&serverDet, sizeof(serverDet));

	listen(serverDesc, 10);

	int clientDesc = accept(serverDesc, nullptr, nullptr);

	char buffer[1000];
	recv(clientDesc, buffer, sizeof(buffer),0);

	cout<<"Buffer = "<< buffer <<endl;
}
