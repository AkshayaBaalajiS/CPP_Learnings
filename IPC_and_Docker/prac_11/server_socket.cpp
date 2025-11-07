#include <iostream>
#include <netinet/in.h>  // struct sockaddr_in, AF_INET, INADDR_ANY, htons 
#include <sys/socket.h>   //->socket, bind, listen, accept, recv 
#include <unistd.h>  // close, wait 
#include <cstring>  // memset, strcpy, strcmp 
#include <thread>


using namespace std;

int main()
{
	cout<<"This is the program to understand the server socket in c++\n";

	int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	/*
	serverSocket - > file descriptor uniquely identifies socket in your program 
	AF_INET - > IPv4
	SOCK_STREAM - > TCP based connection (reliable)
	0 -> protocol number OS picks the correct one for TCP here 
	socket -> establish endpoint for communication 
		return of socket -> 
			-1 for failure 
			non negative for success 
	*/

	std::this_thread::sleep_for(std::chrono::seconds(15));

	sockaddr_in serverDetails;
	serverDetails.sin_family = AF_INET; // AF_INET must match the 1st arg of socket 
	serverDetails.sin_port = htons(8080); // This is the port number the server will listen 
	/*
	htons -> Host to Network Short (convert from host byte order (little endian on x86) to network byte order (big endian) for portability)
	*/
	serverDetails.sin_addr.s_addr = INADDR_ANY; // This sets the IP address when the server should accept 
	/*
	INADDR_ANY - >  accept connection on any network interface 
	*/


	bind(serverSocket,(struct sockaddr*)&serverDetails, sizeof(serverDetails));

	listen(serverSocket, 5);
	/*
	5 -> queue upto 5 pending connections 
	*/
	int clientSock = accept(serverSocket, nullptr, nullptr);
	// accept return a client descriptor for communicating 
	// ignore IP and port 


	char buffer[1000] ;
	recv(clientSock, buffer, sizeof(buffer), 0);
	cout<<"Message from client  = " << buffer <<endl ;
	// 0-> flags 

	close(serverSocket);


}