#include <iostream>
#include <chrono>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <thread>

using namespace std;

int main()
{
	cout<<"This is the server code where it used the TCP and IPv4 socket \n";

	int serverSocket  = socket(AF_INET, SOCK_STREAM, 0);
	sockaddr_in serverAddress;
	serverAddress.sin_port = htons(8080);
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = INADDR_ANY ;

	bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress));

	listen(serverSocket, 10);

	int clientSocket  = accept(serverSocket, nullptr, nullptr);

	char buffer[1024];
	recv(clientSocket, buffer, sizeof(buffer),0);
	cout<<"Message = " << buffer <<endl;
}