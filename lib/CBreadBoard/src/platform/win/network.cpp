//
// Created by Jedzia on 29.10.2019.
//

#include "CBreadBoard/network.h"

//#ifdef WINDOWS
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
//#endif


using namespace std;

bool Network::initialized = false;
static WSADATA wsa;

void Network::getName() {


}

Network::Network() {
    if (!initialized) {
        cout << "Initialising Winsock..." << endl;
        if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
            printf("Failed. Error Code : %d", WSAGetLastError());
            //return 1;
        }

        printf("Initialised.");
    }
}

Network::~Network() {
    if (!initialized) {
        cout << "Winsock cleanup..." << endl;
        WSACleanup();
        initialized = false;
    }
}
