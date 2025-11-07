#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <chrono>
#include <thread>
using namespace std;

int main() {
    cout << "Server running...\n";

    int serverSock = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddress{};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    bind(serverSock, (struct sockaddr*)&serverAddress, sizeof(serverAddress));
    listen(serverSock, 10);

    int clientSock = accept(serverSock, nullptr, nullptr);
    if (clientSock < 0) {
        perror("accept failed");
        return 1;
    }

    const char* reply = "Hello from server!";
    char buffer[1024];

    while (true) {
        int bytesReceived = recv(clientSock, buffer, sizeof(buffer) - 1, 0);
        if (bytesReceived > 0) {
            buffer[bytesReceived] = '\0';
            cout << "Client: " << buffer << endl;
            send(clientSock, reply, strlen(reply), 0);
        } else if (bytesReceived == 0) {
            cout << "Client disconnected\n";
            break;
        } else {
            perror("recv failed");
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(450));
    }

    close(clientSock);
    close(serverSock);
}
