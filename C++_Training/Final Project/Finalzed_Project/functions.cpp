/****************************************************************************
Company: Tata Elxsi LTD
File Name: functions.cpp
Author: Group 2
Version: 1.0
Date: 01 July 2024
Operating Environment: Raspbian GNU/Linux 12
Compiler with Version Number: g++ 12.2.0
Description: This file contains the definitions of the function written inside the class and in the global scope. 
List of functions used:
    - turn_on_wifi()
    - turn_off_wifi()
    - discover_devices()
    - ping_ip()
    - get_host_name()
    - identify_ports_and_os()
Revisers Name: 
Date: 01 July 2024
Customer Bug No./ CMF No.: None
Brief description of the fix/enhancement: None
Created by Tata Elxsi Ltd., Group 2 
Copyright <2023> Tata Elxsi Ltd.
All rights reserved.
This code contains information that is proprietary to Tata Elxsi Ltd. No part of
this document/code may be reproduced or used in whole or part in any form or by any
means - graphic, electronic or mechanical without the written permission of Tata Elxsi Ltd.
**************************************************************************/

#include "headers.h"

/****************************************************************************
Function Name: get_hostname
Function ID: 
Requirement ID: 
Description: This function is responsible for getting the Host name based on the IP address.
Parameters: ip_address
Called Functions: None 
Global Data: None
Return Value: string 
Exceptions: None
*****************************************************************************/
 
string get_hostname(const char *ip_address)
{
    cout<<"\nFetching the Host name for " << ip_address <<"\n";
    struct sockaddr_in socket_address;
    socklen_t len;
    char buffer[NI_MAXHOST];

    memset(&socket_address, 0, sizeof(struct sockaddr_in));
    socket_address.sin_family = AF_INET;
    inet_pton(AF_INET, ip_address, &socket_address.sin_addr);

    if (getnameinfo((struct sockaddr *)&socket_address, sizeof(struct sockaddr_in), buffer, sizeof(buffer), NULL, 0, NI_NAMEREQD))
    {
        cerr << "Could not resolve hostname for " << ip_address << "\n";
        return "";
    }
    else
    {
        return string(buffer);
    }
}

/****************************************************************************
Function Name: identify_ports_and_os
Function ID: 
Requirement ID: 
Description: This function is responsible for getting the open Ports and OS details of Host .
Parameters: ip_address
Called Functions: None 
Global Data: None
Return Value: Null  
Exceptions: None
*****************************************************************************/
void identify_ports_and_os(const char *ip_address)
{
    cout<<"\nFetching the Open Ports and OS informations for " << ip_address <<"\n";
    char command[256];
    snprintf(command, sizeof(command), "nmap -O %s", ip_address); // -O flag is for OS detection
    system(command);
}



/****************************************************************************
Function Name: turn_on_wifi
Function ID: 
Requirement ID: 
Description: This function is responsible for turning ON WiFi.
Parameters: None
Called Functions: None 
Global Data: None
Return Value: Null  
Exceptions: None
*****************************************************************************/
void WiFiControl::turn_on_wifi()
{
    system("sudo rfkill unblock wifi");
    system("sudo ifconfig wlan0 up");
    cout << "----Wi-Fi turned on.----" << "\n";
}

/****************************************************************************
Function Name: turn_off_wifi
Function ID: 
Requirement ID: 
Description: This function is responsible for turning OFF WiFi.
Parameters: None
Called Functions: None 
Global Data: None
Return Value: Null  
Exceptions: None
*****************************************************************************/
void WiFiControl::turn_off_wifi()
{
    system("sudo ifconfig wlan0 down");
    system("sudo rfkill block wifi");
    cout << "----Wi-Fi turned off.----" << "\n";
}

/****************************************************************************
Function Name: discover_devices
Function ID: 
Requirement ID: 
Description: This function is responsible for iterating the IP address from the start till end range given by the user.
             This function will check whether the IP is pingable and if pingable get the Host Name ,Host OS and Open Port details by function call to the specific function. 
Parameters: provided_ip_address, start, stop
Called Functions: 
    - ping_ip ()
    - get_host_name()
    - identify_ports_and_os()
Global Data: None
Return Value: Null  
Exceptions: None
*****************************************************************************/
void ping_mechanism::discover_devices(const char *provided_ip_address, int start,int  stop)
{

    string configurable_ip_address;
    for (int i = start; i <= stop; i++)
    {
        configurable_ip_address = provided_ip_address;
        configurable_ip_address = configurable_ip_address + "." + to_string(i);
        cout<<"---------------------------------------------Details for IP: " << configurable_ip_address <<" ---------------------------------------------\n"<< "\n";
        if (ping_ip(configurable_ip_address.c_str()))
        {
            cout << "Device found: " << configurable_ip_address << "\n";  
            cout << "Ping successful!" << "\n";
            string hostname = get_hostname(configurable_ip_address.c_str());
            if (!hostname.empty())
            {
                cout << "Hostname: " << hostname << "\n";
            }
            // Scan ports and detect OS++
            identify_ports_and_os(configurable_ip_address.c_str());
            cout<<"******************************************************************************************************************\n";
        }
        else
        {
            cout << "Device not found at: " << configurable_ip_address << "\n";
            cout<<"*************************************************************************************************************************\n";
        }
    }
}

/****************************************************************************
Function Name: checksum
Function ID: 
Requirement ID: 
Description: This function is responsible for calculating checksum for a given buffer b by summing 16-bit chunks, adding any remaining byte, and handling any carry. 
             The result is the one's complement of the sum, commonly used to verify data integrity in network communications.
Parameters: b (struct icmp_packet), len (sizeof(b))
Called Functions: None 
Global Data: None
Return Value: unsigned short   
Exceptions: None
*****************************************************************************/
unsigned short ping_mechanism::checksum(void *b, int len)
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
/****************************************************************************
Function Name: ping_ip
Function ID: 
Requirement ID: 
Description: This function is responsible for creating a socket for pinging the IP address provided by the user  and for setting the time interval of 5 sec .
             This funciton is mainly for sending the ICMP_ECHOREQUEST and receiving the ICMP_ECHOREPLY.
             It compare the reply received from the Host / Target devices whether it matches to ICMP_ECHOREPLY 
Parameters: ip_address
Called Functions: None 
Global Data: None
Return Value: bool   
Exceptions: None
*****************************************************************************/
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
        cerr << "Socket creation failed: " << strerror(errno) << "\n";
        return false;
    }

    // Set receive timeout
    struct timeval timeout;
    timeout.tv_sec = 5; // Example: 5 seconds timeout
    timeout.tv_usec = 0;
    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0)
    {
        cerr << "Error setting receive timeout: " << strerror(errno) << "\n";
        close(sock);
        return false;
    }

    if (sendto(sock, &packet, sizeof(packet), 0, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        cerr << "Sendto failed: " << strerror(errno) << "\n";
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
            cerr << "Receive timeout expired." << "\n";
        }
        else
        {
            cerr << "Recvfrom failed: " << strerror(errno) << "\n";
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
