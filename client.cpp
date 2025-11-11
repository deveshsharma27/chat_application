#include <iostream>
#include <winsock2.h>
#include <string>
using namespace std;

int main() {
    WSADATA WSAData;
    SOCKET sock;
    SOCKADDR_IN addr;
    char buffer[1024];

    // Initialize Winsock
    WSAStartup(MAKEWORD(2, 0), &WSAData);
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET) {
        cout << "Error creating socket!" << endl;
        return -1;
    }
    cout << "Client socket created successfully." << endl;

    // Get Server IP
    string serverIP;
    cout << "Enter Server IP Address: ";
    cin >> serverIP;

    addr.sin_addr.s_addr = inet_addr(serverIP.c_str());
    addr.sin_family = AF_INET;
    addr.sin_port = htons(4444);

    // Connect to server
    if (connect(sock, (SOCKADDR*)&addr, sizeof(addr)) == SOCKET_ERROR) {
        cout << "Connection failed!" << endl;
        closesocket(sock);
        WSACleanup();
        return -1;
    }
    cout << "Connected to the server successfully!" << endl;

    cin.ignore(); // Clear input buffer
    while (true) {
        cout << "You (Client): ";
        memset(buffer, 0, sizeof(buffer));
        cin.getline(buffer, sizeof(buffer));
        send(sock, buffer, sizeof(buffer), 0);

        memset(buffer, 0, sizeof(buffer));
        recv(sock, buffer, sizeof(buffer), 0);
        cout << "Server: " << buffer << endl;
    }

    closesocket(sock);
    WSACleanup();
    return 0;
}
