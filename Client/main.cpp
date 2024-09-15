#include <ClientSocket.hpp>
#include <iostream>
#include <string>

int main(int argc, char **argv){
    ClientSocket client;
    
    client.Connect();
    client.SendData();

    return 0;
}