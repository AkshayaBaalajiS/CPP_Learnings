#include "header.hpp"
#include <sys/wait.h>
#include <arpa/inet.h>

using namespace std;

int main()
{
	#ifdef UDP
	cout<<"Client code for the IPv4 based UDP \n";
	#else
	cout<<"Client code for the IPv4 based TCP  \n";
	#endif

	#ifdef UDP
	int clientDesc = socket(AF_INET, SOCK_DGRAM, 0);
	#else
	int clientDesc = socket(AF_INET, SOCK_STREAM, 0);
	#endif

	sockaddr_in clientAdd ;
	clientAdd.sin_port = htons(8080);
	clientAdd.sin_family = AF_INET;
	clientAdd.sin_addr.s_addr = inet_addr("127.0.0.1");

	connect(clientDesc, (struct sockaddr *)&clientAdd, sizeof(clientAdd));

	Structure * obj = new Structure();
	obj->a=234;
	obj->b="Akshaya Baalaji S";

	#ifdef UDP
	socklen_t socketlen = sizeof(clientAdd);
	sendto(clientDesc, obj, sizeof(*obj),0,(struct sockaddr *)&clientAdd, socketlen);
	#else
	send(clientDesc, obj, sizeof(*obj),0);
	#endif

}