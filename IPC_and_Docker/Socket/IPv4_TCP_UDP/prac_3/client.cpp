#include "header.hpp"
#include <arpa/inet.h>
using namespace std;

int main()
{

	#ifdef TCP
	cout<<"IPv4 TCP client code \n";
	#else 
	cout<<"IPv4 UDP client code \n";
	#endif


	#ifdef TCP 
	int clientDesc = socket(AF_INET, SOCK_STREAM, 0);
	#else
	int clientDesc = socket(AF_INET, SOCK_DGRAM, 0);
	#endif

	sockaddr_in clientAdd;
	clientAdd.sin_port = htons(8080);
	clientAdd.sin_family  = AF_INET;
	clientAdd.sin_addr.s_addr = inet_addr("127.0.0.1");


	#ifdef TCP
	connect(clientDesc, (struct sockaddr *)(&clientAdd), sizeof(clientAdd));
	#else 
	connect(clientDesc, (struct sockaddr *)(&clientAdd), sizeof(clientAdd));
	#endif

	Structure * ptr = new Structure();
	ptr->a = 12;
	ptr->b = 123123.1231;
	ptr->c = 'a';
	ptr->d = 123.234;

	#ifdef TCP
	send(clientDesc, ptr, sizeof(*ptr),0);
	#else
	socklen_t socketlen = sizeof(clientAdd);
	sendto(clientDesc, ptr, sizeof(*ptr), 0, (struct sockaddr *)(&clientAdd), socketlen);

	#endif

	// cout<<*ptr;
}