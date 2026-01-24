#include <arpa/inet.h>
#include <sys/wait.h>
#include "header.hpp"
using namespace std;

int main()
{
	#ifdef TCP
	cout<<"IPv4 TCP server code \n";
	#else 
	cout<<"IPv4 UDP server code \n";
	#endif

	#ifdef TCP 
	int serverDesc = socket(AF_INET, SOCK_STREAM, 0);
	#else
	int serverDesc = socket(AF_INET, SOCK_DGRAM , 0);
	#endif

	sockaddr_in serverAdd ;
	serverAdd.sin_port = htons(8080);
	serverAdd.sin_family = AF_INET;
	serverAdd.sin_addr.s_addr = INADDR_ANY;

	bind(serverDesc, (struct sockaddr *)&serverAdd, sizeof(serverAdd));

	#ifdef TCP
	listen(serverDesc,10);
	int clientDesc = accept(serverDesc, nullptr, nullptr);
	#endif
	// listen and connect is not needed for UDP

	Structure * ptr = new Structure();

	#ifdef TCP
	recv(clientDesc, ptr, sizeof(*ptr),0);
	#else
	socklen_t sockerlen = sizeof(serverAdd);
	recvfrom(serverDesc, ptr, sizeof(*ptr), 0, (struct sockaddr *)&serverAdd, &sockerlen );
	#endif
	// we cant transfer a address cause herere we are providing the address 
	// WHat internally happens is 
	// it transfer the bytes present inthe address 
	/*
	Sockets do NOT transfer “a fixed number of bytes at a time”.
	You decide how many bytes to send, and the OS may deliver them in chunks.
	*/
	cout<<*ptr;
}