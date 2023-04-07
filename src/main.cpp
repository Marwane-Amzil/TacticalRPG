#include <network.hpp>
#include <iostream>

int main(int argc, char* argv[])
{
    iut::client_socket client("192.168.43.19", iut::port::DEFAULT);
    client.connect();
    client.send("I am the first client\n");

    while (true)
    {
        const char* message = client.receive(256);

        if (!strcmp(message, "stop"))
        {
            delete message;
            break;
        }

        std::cout << message << '\n';

        delete message;
    }

    return 0;
}





/*
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        std::cerr << "WSAStartup failed: " << iResult << std::endl;
        return 1;
    }

    // create a socket
    SOCKET sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd == INVALID_SOCKET) {
        std::cerr << "socket failed: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return 1;
    }

    // set the address information
    struct addrinfo hints;
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    struct addrinfo* result = NULL;
    iResult = getaddrinfo("192.168.43.19", "5000", &hints, &result);
    if (iResult != 0) {
        std::cerr << "getaddrinfo failed: " << iResult << std::endl;
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }

    // connect to the server
    iResult = connect(sockfd, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        std::cerr << "connect failed: " << WSAGetLastError() << std::endl;
        freeaddrinfo(result);
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }
    freeaddrinfo(result);

    // send data to the server
    const char* message = "Hello, server!";
    iResult = send(sockfd, message, (int)strlen(message), 0);
    if (iResult == SOCKET_ERROR) {
        std::cerr << "send failed: " << WSAGetLastError() << std::endl;
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }

    // receive data from the server
    char buffer[1024];
    iResult = recv(sockfd, buffer, sizeof(buffer), 0);
    if (iResult > 0) {
        buffer[iResult] = '\0';
        std::cout << "Received: " << buffer << std::endl;
    }
    else if (iResult == 0) {
        std::cerr << "Connection closed" << std::endl;
    }
    else {
        std::cerr << "recv failed: " << WSAGetLastError() << std::endl;
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }

    // close the socket
    closesocket(sockfd);
    WSACleanup();

    return 0;
}

*/