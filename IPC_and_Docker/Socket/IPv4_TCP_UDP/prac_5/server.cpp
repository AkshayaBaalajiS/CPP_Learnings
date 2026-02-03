#include "header.hpp"
#include <arpa/inet.h>

using namespace std;

int main()
{
	#ifdef TCP
	cout<<"@ server code of IPv4 communication TCP\n";
	#else
	cout<<"@ server code of IPv4 communication UDP\n";
	#endif

	#ifdef TCP
	int serverDesc = socket(AF_INET, SOCK_STREAM , 0);
	#else
	int serverDesc = socket(AF_INET, SOCK_DGRAM, 0);
	#endif

	sockaddr_in serverAdd ;
	serverAdd.sin_addr.s_addr = INADDR_ANY;
	serverAdd.sin_family = AF_INET;
	serverAdd.sin_port = htons(8080);

	bind(serverDesc, (struct sockaddr *)&serverAdd, sizeof(serverAdd));
	#ifdef TCP
	listen(serverDesc, 10);
	int clientDesc = accept(serverDesc, nullptr, nullptr);
	#endif
	DataStructure * ptr = new DataStructure() ;
	#ifdef TCP
	recv(clientDesc, ptr, sizeof(*ptr), 0);
	#else
	socklen_t socketlt = sizeof(serverAdd);
	recvfrom(serverDesc, ptr, sizeof(*ptr), 0, (struct sockaddr *)&serverAdd, &socketlt);
	#endif
	cout<<*ptr;
	
}