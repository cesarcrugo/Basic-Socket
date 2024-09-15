#include "ClientSocket.hpp"
#include <cstring> 
#include <iostream> 
#include <netinet/in.h> 
#include <sys/socket.h> 
#include <unistd.h> 

ClientSocket::ClientSocket(){
    CreateServerSocket();
}

void ClientSocket::CreateServerSocket(){
    m_clientsocket = socket(AF_LOCAL, SOCK_STREAM, 0);

    m_serverAddr.sin_family = AF_LOCAL;
    m_serverAddr.sin_port = htons(1300);
    m_serverAddr.sin_addr.s_addr = INADDR_ANY;
}

void ClientSocket::Connect(){
    connect(m_clientsocket, (struct sockaddr*)&m_serverAddr, sizeof(m_serverAddr));
}

void ClientSocket::SendData(){
    const char* message = "Hello World!";
    send(m_clientsocket, message, strlen(message), 0);

    close(m_clientsocket);
}
