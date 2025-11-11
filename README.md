# chat_application
C++ Client-Server Chat Program using Winsock.
# Chat Application (C++ Winsock)

This is a **basic Client-Server Chat Application** written in **C++** using **Winsock2** on Windows.  
 clients can connect to the server and exchange text messages.

---

## 💡 Features

- Server accepts  clients
- Clients can send text messages
- Clients see the same messages
- Uses TCP communication (reliable data transfer)

---

## 🛠 Requirements

- Windows OS
- MinGW-w64 compiler
- VS Code or any C++ IDE

---

## 🧱 How to Compile

Open terminal in the folder and run:

```bash
g++ -std=c++17 server.cpp -lws2_32 -o server.exe
g++ -std=c++17 client.cpp -lws2_32 -o client.exe
