#include "header.hpp"
#include <arpa/inet.h>
#include <sys/wait.h>

int main()
{
	#ifdef UDP
	cout<<"Server code for the IPv4 based UDP \n";
	#else
	cout<<"Server code for the IPv4 based TCP  \n";
	#endif

	#ifdef UDP
	int serverDesc = socket(AF_INET, SOCK_DGRAM, 0);
	#else
	int serverDesc = socket(AF_INET, SOCK_STREAM, 0);
	#endif

	sockaddr_in serverAdd;
	serverAdd.sin_port = htons(8080);
	serverAdd.sin_addr.s_addr = INADDR_ANY;
	serverAdd.sin_family = AF_INET;

	bind(serverDesc, (struct sockaddr *)(&serverAdd), sizeof(serverAdd));

	listen(serverDesc,10);

	#ifndef UDP 
	int clientDesc = accept(serverDesc, nullptr, nullptr);
	#endif

	Structure * ptr = new Structure();

	#ifdef UDP
	socklen_t socketlenn = sizeof(serverAdd);
	recvfrom(serverDesc, ptr, sizeof(*ptr),0, (struct sockaddr *)(&serverAdd), &socketlenn);
	#else 
	recv(clientDesc, ptr, sizeof(*ptr),0);
	#endif

	cout<<"---------------------------\n";
	cout<<"Data Received is :\n";
	cout<<"A = " << ptr->a<<endl;
	// cout<<"B = " << ptr->b<<endl;
	cout<<"---------------------------\n";


}