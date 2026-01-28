#include "header.hpp"
#include <arpa/inet.h>
using namespace std;

int main()
{
	#ifdef TCP 
	cout<<"Client code of TCP\n";
	#else
	cout<<"Client code of UDP\n";
	#endif
	
	#ifdef TCP
	int clientDesc = socket(AF_INET, SOCK_STREAM, 0);
	#else
	int clientDesc = socket(AF_INET, SOCK_DGRAM, 0);
	#endif

	sockaddr_in clientAdd;
	clientAdd.sin_family = AF_INET;
	clientAdd.sin_port = htons(8080);
	clientAdd.sin_addr.s_addr = inet_addr("127.0.0.1");

	connect(clientDesc, (struct sockaddr *)&clientAdd, sizeof(clientAdd));

	Structure * ptr = new Structure();
	ptr->a= 23.2344;
	ptr->b=234.234;
	ptr->c= 's';

	#ifdef TCP 
	send(clientDesc, ptr, sizeof(*ptr), 0);
	#else
	socklen_t socketlen = sizeof(clientAdd);
	sendto(clientDesc, ptr, sizeof(*ptr), 0,(struct sockaddr *)&clientAdd, socketlen );
	#endif
	
}