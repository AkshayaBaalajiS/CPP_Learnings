/****************************************************************************
Company: Tata Elxsi LTD
File Name: headers.h
Author: Group 2
Version: 1.0
Date: 01 July 2024
Operating Environment: Raspbian GNU/Linux 12
Compiler with Version Number: g++ 12.2.0
Description: This file contains the declarations of the global functions and the class definition without the function definition. 
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

class WiFiControl
{
public:
    // Function to turn on Wi-Fi
    void turn_on_wifi() ; 

    // Function to turn off Wi-Fi
    void turn_off_wifi() ; 

};

class ping_mechanism : public WiFiControl
{
public:
    unsigned short checksum(void *b, int len);
    bool ping_ip(const char *ip);

    // Discover device at the specified IP address
    void discover_devices(const char *provided_ip_address, int start,int  stop);

};


string get_hostname(const char *ip_address);
void identify_ports_and_os(const char *ip_address);




