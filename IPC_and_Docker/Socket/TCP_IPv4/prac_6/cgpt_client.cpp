#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <chrono>
#include <thread>
using namespace std;

int main() {
    cout << "Client running...\n";

    int clientSock = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(clientSock, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("connect failed");
        return 1;
    }

    const char* msg = "Hello from client!";
    char recvBuffer[1024];

    while (true) {
        send(clientSock, msg, strlen(msg), 0);
        cout << "Sent: " << msg << endl;

        int bytesRead = recv(clientSock, recvBuffer, sizeof(recvBuffer) - 1, 0);
        if (bytesRead > 0) {
            recvBuffer[bytesRead] = '\0';
            cout << "Server: " << recvBuffer << endl;
        } else if (bytesRead == 0) {
            cout << "Server disconnected\n";
            break;
        } else {
            perror("recv failed");
            break;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(450));
    }

    close(clientSock);
}
