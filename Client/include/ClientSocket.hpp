#pragma once

#ifndef SUM_CPP
#define SUM_CPP

#include <iostream> 
#include <netinet/in.h> 
#include <sys/socket.h> 

class ClientSocket {
 public:
    ClientSocket();

    void Connect ();
    void SendData ();

 private:
    int m_clientsocket;
    sockaddr_in m_serverAddr;

    void CreateServerSocket ();
};

#endif // #ifndef SUM_CPP