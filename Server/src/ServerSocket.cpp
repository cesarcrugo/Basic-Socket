#include "ServerSocket.hpp"
#include <cstring> 
#include <iostream> 
#include <netinet/in.h> 
#include <sys/socket.h> 
#include <unistd.h> 


ServerSocket::ServerSocket(){
    CreateSocket();
}

void ServerSocket::CreateSocket(){
    m_socket = socket(AF_LOCAL, SOCK_STREAM, 0);

    m_addr.sin_family = AF_LOCAL;
    m_addr.sin_port = htons(1300);
    m_addr.sin_addr.s_addr = INADDR_ANY;

    bind(m_socket, (struct sockaddr*)&m_addr, sizeof(m_addr));
}

void ServerSocket::Listen(){
    listen(m_socket, 100);
}

std::string ServerSocket::ReceiveData(){
    int client = accept(m_socket, nullptr, nullptr);
    
    char buffer[1024] = {};
    recv(client, buffer, sizeof(buffer), 0);
    std::cout << "reached" << std::endl;

    close(m_socket);

    return buffer;
}

