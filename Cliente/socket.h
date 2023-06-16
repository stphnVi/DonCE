#ifndef DONCE_SOCKET_H
#define DONCE_SOCKET_H

#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <unistd.h>
#include <string.h>

//Macros que se deben mover al constants header
#define START_CLIENT "Client started...\n"
#define STOP_CLIENT "Client stopped...\n"
#define ERR_SOCKET "Error: Socket init failed.: %d\n"
#define ERR_CONNECT "Error: Connection failed.: %d\n"
#define ERR_SEND "Error: Data sending failed.: %d\n"
#define ERR_READ "Error: Data reading failed.: %d\n"
#define ERR_MAX "Error: Max number of clients reached.\n"
#define IP "127.0.0.1"
#define PORT 9090
#define MAX_BUFF_LEN 2048
#define MAX_CLIENTS 6
///////////////

//Libreria WinSock
typedef struct{
    SOCKET sock;
    struct sockaddr_in server_address;
    char data[MAX_BUFF_LEN];
} ClientInstance;//struct que define una instancia de cliente

int socksInit();

int start(ClientInstance* client);

void stop();

SOCKET createSocket();

struct sockaddr_in serverAddress();

int connectServer(ClientInstance* client);

int sendData(ClientInstance* client, char* data);

char* readData(ClientInstance* client);

#endif //DONCE_SOCKET_H