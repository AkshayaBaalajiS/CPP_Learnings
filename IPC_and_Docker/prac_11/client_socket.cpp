#include <iostream>
#include <cstring>
#include <unistd.h>  // for close
#include <sys/wait.h> // for wait
#include <sys/socket.h> // socket, bind, listen, accept, connect
#include <netinet/in.h>  // struct sockaddr_in, AF_INET, INADDR_ANY, htons 
#include <arpa/inet.h>   // inet_addr
using namespace std;

int main()
{
	cout<<"This is the client socket program in c++\n";

	int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	/*clientSocket - client socket descriptor */

	sockaddr_in clientDetails ;
	clientDetails.sin_family = AF_INET ;
	clientDetails.sin_port = htons(8080);
	clientDetails.sin_addr.s_addr = inet_addr("127.0.0.1");

	connect(clientSocket, (struct sockaddr *)&clientDetails, sizeof(clientDetails));

	char * mess = "Hi Bye Sever\n";
	send(clientSocket, mess, strlen(mess), 0);
	// 0 flags 

	close(clientSocket);


}