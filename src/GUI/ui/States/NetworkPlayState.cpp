#include <iostream>
#include <memory>
#include <stdexcept>
#include <GUI/ui/States/NetworkPlayState.hpp>
#include <GUI/ui/StateMachine.hpp>
#include <GUI/ui/States/MenuState.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <GUI/game/EntitySprite.hpp>
#include <array>
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")


NetworkPlayState::NetworkPlayState(StateMachine& machine, sf::RenderWindow& window, gui::World& world, utils::TextureManager& texture_manager, const bool replace)
	: State(machine, window, replace), _world(world), _textureManager(texture_manager) {



}



SOCKET NetworkPlayState::createSocket() {
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        std::cerr << "WSAStartup failed: " << iResult << std::endl;
        return 0;
    }

    SOCKET sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd == INVALID_SOCKET) {
        std::cerr << "socket failed: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return 0;
    }

    return sockfd;
}

bool NetworkPlayState::connectSocket(SOCKET sockfd, const char* ip, const char* port) {
    struct addrinfo hints;
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    struct addrinfo* result = NULL;
    int iResult = getaddrinfo(ip, port, &hints, &result);
    if (iResult != 0) {
        std::cerr << "getaddrinfo failed: " << iResult << std::endl;
        closesocket(sockfd);
        WSACleanup();
        return false;
    }

    iResult = connect(sockfd, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        std::cerr << "connect failed: " << WSAGetLastError() << std::endl;
        freeaddrinfo(result);
        closesocket(sockfd);
        WSACleanup();
        return false;
    }
    freeaddrinfo(result);

    return true;
}

bool NetworkPlayState::sendMessage(SOCKET sockfd, const char* message) {
    int iResult = send(sockfd, message, (int)strlen(message), 0);
    if (iResult == SOCKET_ERROR) {
        std::cerr << "send failed: " << WSAGetLastError() << std::endl;
        closesocket(sockfd);
        WSACleanup();
        return false;
    }

    return true;
}

bool NetworkPlayState::receiveMessage(SOCKET sockfd, char* buffer, int buffer_size) {
    int iResult = recv(sockfd, buffer, buffer_size - 1, 0);
    if (iResult > 0) {
        buffer[iResult] = '\0';
        std::cout << "Received: " << buffer << std::endl;
        return true;
    }
    else if (iResult == 0) {
        std::cerr << "Connection closed" << std::endl;
    }
    else {
        std::cerr << "recv failed: " << WSAGetLastError() << std::endl;
    }

    closesocket(sockfd);
    WSACleanup();
    return false;
}