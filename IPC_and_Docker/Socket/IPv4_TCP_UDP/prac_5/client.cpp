#include "header.hpp"
#include <cstring>
#include <arpa/inet.h>

using namespace std;

int main()
{
	#ifdef TCP
	cout<<"@ client code of IPv4 communication TCP\n";
	#else
	cout<<"@ client code of IPv4 communication UDP\n";
	#endif

	#ifdef TCP
	int  clientDesc = socket(AF_INET, SOCK_STREAM , 0);
	#else
	int  clientDesc = socket(AF_INET, SOCK_DGRAM, 0);
	#endif

	sockaddr_in clientAdd ;
	clientAdd.sin_addr.s_addr = inet_addr("127.0.0.1");
	clientAdd.sin_family = AF_INET;
	clientAdd.sin_port = htons(8080);

	connect(clientDesc, (struct sockaddr *)&clientAdd, sizeof(clientAdd));

	DataStructure * ptr = new DataStructure();
	ptr->a =123;
	strcpy(ptr->array, "Akshaya Baalaji S");
	ptr->c = 2.34;
	ptr->d = 2342.234234;
	#ifdef TCP
	send(clientDesc, ptr, sizeof(*ptr), 0);
	#else
	socklen_t socketlee = sizeof(clientAdd);
	sendto(clientDesc, ptr, sizeof(*ptr), 0, (struct sockaddr *)&clientAdd, socketlee );
	#endif


}