#include <iostream>
#include <winsock2.h>
#include <string>
using namespace std;

int main() {
    WSADATA WSAData;
    SOCKET server, client;
    SOCKADDR_IN serverAddr, clientAddr;
    char buffer[1024];

    // Initialize Winsock
    WSAStartup(MAKEWORD(2, 0), &WSAData);
    server = socket(AF_INET, SOCK_STREAM, 0);
    if (server == INVALID_SOCKET) {
        cout << "Error creating socket!" << endl;
        return -1;
    }
    cout << "Server socket created successfully." << endl;

    // Set up server address structure
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(4444);

    // Bind socket to IP and port
    if (bind(server, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        cout << "Error in binding." << endl;
        closesocket(server);
        WSACleanup();
        return -1;
    }
    cout << "Binding successful. Listening on port 4444..." << endl;

    // Listen for a client
    listen(server, 0);
    cout << "Waiting for client connection..." << endl;

    int clientAddrSize = sizeof(clientAddr);
    if ((client = accept(server, (SOCKADDR*)&clientAddr, &clientAddrSize)) != INVALID_SOCKET) {
        cout << "Client connected!" << endl;

        while (true) {
            memset(buffer, 0, sizeof(buffer));
            recv(client, buffer, sizeof(buffer), 0);
            cout << "Client: " << buffer << endl;

            cout << "You (Server): ";
            memset(buffer, 0, sizeof(buffer));
            cin.getline(buffer, sizeof(buffer));
            send(client, buffer, sizeof(buffer), 0);
        }
    }

    closesocket(client);
    closesocket(server);
    WSACleanup();
    return 0;
}
