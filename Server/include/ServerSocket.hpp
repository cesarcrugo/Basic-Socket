#pragma once

#ifndef SUM_CPP
#define SUM_CPP

#include <iostream> 
#include <netinet/in.h> 
#include <sys/socket.h> 

class ServerSocket {
 public:
    ServerSocket();

    void Listen ();
    std::string ReceiveData ();

 private:
    int m_socket;
    sockaddr_in m_addr;

    void CreateSocket ();
};

#endif // #ifndef SUM_CPP