#include <iostream>
#include <sys/wait.h>
#include <netinet/in.h>
#include <sys/socket.h>
using namespace std;

int main()
{
	cout<<"This is the program to understand the Socker programming Server Side\n ";

	int serverSocket  = socket(AF_INET, SOCK_STREAM, 0);

	sockaddr_in serverAddr ;
	serverAddr.sin_addr.s_addr =INADDR_ANY ;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(8080);

	bind(serverSocket, (struct sockaddr *)(&serverAddr), sizeof(serverAddr) );
	listen(serverSocket,10);

	int clientDesc = accept(serverSocket, nullptr, nullptr);
	char buffer[1231] ;
	recv(clientDesc, buffer, sizeof(buffer),0);
	cout<<"Message received from client is  : " << buffer;

	close(serverSocket);


}