#include <arpa/inet.h>
#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <netinet/ip_icmp.h>
#include <netinet/ip.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cstdio>
#include <netdb.h>

#define NI_MAXHOST 1025
using namespace std;

struct icmp_packet
{
    struct icmphdr icmp_hdr;
};

string get_hostname(const char *ip_address)
{
    struct sockaddr_in socket_address;
    socklen_t len;
    char buffer[NI_MAXHOST];

    memset(&socket_address, 0, sizeof(struct sockaddr_in));
    socket_address.sin_family = AF_INET;
    inet_pton(AF_INET, ip_address, &socket_address.sin_addr);

    if (getnameinfo((struct sockaddr *)&socket_address, sizeof(struct sockaddr_in), buffer, sizeof(buffer), NULL, 0, NI_NAMEREQD))
    {
        cerr << "Could not resolve hostname for " << ip_address << endl;
        return "";
    }
    else
    {
        return string(buffer);
    }
}

void identify_ports_and_os(const char *ip_address)
{
    char command[256];
    snprintf(command, sizeof(command), "nmap -O %s", ip_address); // -O flag is for OS detection
    system(command);
}

class WiFiControl
{
public:
    // Function to turn on Wi-Fi
    void turn_on_wifi()
    {
        system("sudo rfkill unblock wifi");
        system("sudo ifconfig wlan0 up");
        cout << "Wi-Fi turned on." << endl;
    }
    // Function to turn off Wi-Fi
    void turn_off_wifi()
    {
        system("sudo ifconfig wlan0 down");
        system("sudo rfkill block wifi");
        cout << "Wi-Fi turned off." << endl;
    }
};

class ping_mechanism : public WiFiControl
{
public:
    unsigned short checksum(void *b, int len)
    {
        unsigned short *buf = (unsigned short *)b;
        unsigned int sum = 0;
        unsigned short result;

        for (sum = 0; len > 1; len -= 2)
        {
            sum += *buf++;
        }

        if (len == 1)
        {
            sum += *(unsigned char *)buf;
        }

        sum = (sum >> 16) + (sum & 0xFFFF);
        sum += (sum >> 16);
        result = ~sum;

        return result;
    }

    bool ping_ip(const char *ip);

    // Discover device at the specified IP address
    void discover_device(const char *provided_ip_address, int start,int  stop)
    {
        string configurable_ip_address;
        for (int i = start; i <= stop; i++)
        {
            cout << "Checking device at IP: " << provided_ip_address << endl;
            configurable_ip_address = provided_ip_address;
            configurable_ip_address = configurable_ip_address + "." + to_string(i);
            if (ping_ip(configurable_ip_address))
            {
                cout << "Device found: " << configurable_ip_address << endl;  
                cout << "Ping successful!" << endl;
                string hostname = get_hostname(configurable_ip_address);
                if (!hostname.empty())
                {
                    cout << "Hostname: " << hostname << endl;
                }
                // Scan ports and detect OS
                identify_ports_and_os(configurable_ip_address);
            }
            else
            {
                cout << "Device not found at: " << configurable_ip_address << endl;
            }
        }
    }
};

bool ping_mechanism::ping_ip(const char *ip_address)
{
    struct icmp_packet packet;
    struct sockaddr_in addr;
    int sock;

    memset(&packet, 0, sizeof(packet));
    packet.icmp_hdr.type = ICMP_ECHO;
    packet.icmp_hdr.un.echo.id = getpid();
    packet.icmp_hdr.un.echo.sequence = 1;
    packet.icmp_hdr.checksum = checksum(&packet, sizeof(packet));

    addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip_address, &addr.sin_addr);

    sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sock < 0)
    {
        cerr << "Socket creation failed: " << strerror(errno) << endl;
        return false;
    }

    // Set receive timeout
    struct timeval timeout;
    timeout.tv_sec = 5; // Example: 5 seconds timeout
    timeout.tv_usec = 0;
    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0)
    {
        cerr << "Error setting receive timeout: " << strerror(errno) << endl;
        close(sock);
        return false;
    }

    if (sendto(sock, &packet, sizeof(packet), 0, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        cerr << "Sendto failed: " << strerror(errno) << endl;
        close(sock);
        return false;
    }

    char buffer[1024];
    struct sockaddr_in recv_addr;
    socklen_t addr_len = sizeof(recv_addr);

    // Receive ICMP reply
    ssize_t bytes_received = recvfrom(sock, buffer, sizeof(buffer), 0, reinterpret_cast<sockaddr *>(&recv_addr), &addr_len);
    if (bytes_received < 0)
    {
        if (errno == EAGAIN || errno == EWOULDBLOCK)
        {
            cerr << "Receive timeout expired." << endl;
        }
        else
        {
            cerr << "Recvfrom failed: " << strerror(errno) << endl;
        }
        close(sock);
        return false;
    }

    // Check if the received packet is an ICMP echo reply
    struct iphdr *iph = (struct iphdr *)buffer;
    struct icmp_packet *recv_icmp_hdr = (struct icmp_packet *)(buffer + (iph->ihl * 4));
    if (recv_icmp_hdr->icmp_hdr.type == ICMP_ECHOREPLY && recv_icmp_hdr->icmp_hdr.un.echo.id == packet.icmp_hdr.un.echo.id)
    {
        cout << "ECHO REPLY RECEIVED \n";
        close(sock);
        return true;
    }
    else
    {
        cout << "ECHO REPLY NOT RECEIVED \n";
        close(sock);
        return false;
    }
}

int main()
{
    WiFiControl wifi_control;
    ping_mechanism object;
    int choice;
    cout << "Wi-Fi Control Menu:" << endl;
    cout << "1. Turn on Wi-Fi" << endl;
    cout << "2. Turn off Wi-Fi" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
        case 1:
            wifi_control.turn_on_wifi();
            int sub_choice;
            cout << "1. To get the IP configurations ";
            cin >> sub_choice;
            if (sub_choice == 1)
            {
                char ip_add[20]; // Example IP address of a laptop on th
                cout << "Enter the IP address to get ping from ....";
                cin >> ip_add;
                const char *ip_address = ip_add;
                cout << "Pinging IP address: " << ip_address << endl;
                object.discover_device(ip_address);
            }
            else
            {
                cout << "BYE..";
            }
            break;
        case 2:
            wifi_control.turn_off_wifi();
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
    }
    return 0;
}

