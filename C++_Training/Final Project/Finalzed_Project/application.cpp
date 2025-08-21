/****************************************************************************
Company: Tata Elxsi LTD
File Name: application.cpp
Author: Group 2
Version: 1.0
Date: 01 July 2024
Operating Environment: Raspbian GNU/Linux 12
Compiler with Version Number: g++ 12.2.0
Description: This file contains the main function which helps the user to enter the IP , Start , End Rangs and function call for pinging IP 
List of functions used:
    - main()
    - turn_on_wifi()
    - turn_off_wifi()
    - discover_devices()
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
#include <iostream>
/****************************************************************************
Function Name: main
Function ID:
Requirement ID:
Description: This function is responsible for getting the user input for  turn
ON wifi and turn OFF wifi and call the fucntion accordingly. This allows the
user to select Ping IP or Exit if the user select the Ping IP option allows the
user to get the first 3 bytes of the IP address and start and end range of IP.
             After the user enters the inputs function call is done to get the
requirement Parameters: None Called Functions:
    - main()
    - turn_on_wifi()
    - turn_off_wifi()
    - discover_devices()
Global Data: None
Return Value: 0 (Successful execution state)
Exceptions: None
*****************************************************************************/
int main() {
  WiFiControl wifi_control;
  ping_mechanism object;
  int choice;
  cout << "Wi-Fi Control Menu:"
       << "\n";
  cout << "1. Turn on Wi-Fi"
       << "\n";
  cout << "2. Turn off Wi-Fi"
       << "\n";
  cout << "Enter your choice: ";
  cin >> choice;
  switch (choice) {
  case 1:
    wifi_control.turn_on_wifi();
    int sub_choice;
    cout << "Press  \n1.Get the IP configurations \n2.Exit\nEnter your choice  "
            ":  ";
    cin >> sub_choice;
    if (sub_choice == 1) {
      char ip_add[20]; // Example IP address of a laptop on th
      cout << "Enter the first 3 bytes of IP address  :   ";
      cin >> ip_add;
      const char *ip_address = ip_add;
      int start;
      cout << "Enter the first number of the range  : ";
      cin >> start;
      int last;
      cout << "Enter the last number of the range  : ";
      cin >> last;
      object.discover_devices(ip_address, start, last);
      cout << "\nDetails fetched Successfully ......\n";
    } else {
      cout << "BYE..";
    }
    break;
  case 2:
    wifi_control.turn_off_wifi();
    break;
  default:
    cout << "Invalid choice!"
         << "\n";
    break;
  }
  return 0;
}
