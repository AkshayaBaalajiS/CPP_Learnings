#include <arpa/inet.h>
#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <netdb.h>
#include <netinet/ip_icmp.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

struct icmp_packet
{
    struct icmphdr icmp_hdr;
};

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
    cout << "bool ping_mechanism::ping_ip(const char *ip_address   \n";
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

    if (sendto(sock, &packet, sizeof(packet), 0, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        cerr << "Sendto failed: " << strerror(errno) << endl;
        close(sock);
        return false;
    }

    cout << "-------------------\n";

    char buffer[1024];
    sockaddr_in recv_addr;
    socklen_t addr_len = sizeof(recv_addr);

    if (recvfrom(sock, buffer, sizeof(buffer), 0, reinterpret_cast<sockaddr *>(&recv_addr), &addr_len) <= 0)
    {
        close(sock);
        return false;
    }

    struct icmp_packet *recv_icmp_hdr = (struct icmp_packet *)(buffer + sizeof(struct iphdr));
    if (recv_icmp_hdr->icmp_hdr.type == ICMP_ECHOREPLY && recv_icmp_hdr->icmp_hdr.un.echo.id == packet.icmp_hdr.un.echo.id)
    {
        close(sock);
        return true;
    }
    else
    {
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
        cout << "Press \"1\" To know about a range of IP Address   : ";
        cin >> sub_choice;
        if (sub_choice == 1)
        {
            string ip_add;
            cout << "Enter the IP address before the last \".\"  : ";
            cin >> ip_add;

            int start;
            cout << "Enter the last digit of  IP :  ";
            cin >> start;

            int last;
            cout << "Enter the last IP address uptil it need to loop :  ";
            cin >> last;

            const char *ip_address = (ip_add).c_str();
            cout << "Pinging IP address: " << ip_address << endl;
            object.discover_device(ip_address,start,last);
        }
        else
        {
            cout << "BYE....";
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
