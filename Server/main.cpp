#include <ServerSocket.hpp>
#include <iostream>
#include <string>

int main(int argc, char **argv){
    ServerSocket server;
    
    server.Listen();
    std::cout << server.ReceiveData() << std::endl;

    return 0;
}