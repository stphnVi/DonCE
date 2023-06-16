#include "socket.h"

//Cada instancia de cliente
ClientInstance* clientInstances[MAX_CLIENTS];

int numClients=0;//Se inicializa en cero

//funcion que inicializa el socket
int socksInit() {
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
    {
        printf("Failed. Error Code : %d",WSAGetLastError());
        return 1;
    }
    return 0;
}

//Funcion que inicializa el cliente
int start(ClientInstance* client) {
    if(numClients>=MAX_CLIENTS){
        printf(ERR_MAX);
        _exit(1);
    }
    printf(START_CLIENT);

    if(client==NULL){
        printf("Error");
        _exit(1);
    }
    client->sock = createSocket();
    client->server_address= serverAddress();
    clientInstances[numClients++]= client;
    
    return connectServer(client);
}

void stop() {
    printf(STOP_CLIENT);
    for(int i=0; i < numClients; i++){
        closesocket(clientInstances[i]->sock);
        free(clientInstances[i]);
    }
}

SOCKET createSocket() {
    SOCKET status = socket(AF_INET, SOCK_STREAM, 0);
    if (status == INVALID_SOCKET){
        printf(ERR_SOCKET, WSAGetLastError());
        return INVALID_SOCKET;
    }
    return status;
}

struct sockaddr_in serverAddress() {
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr(IP);
    serverAddress.sin_port = htons(PORT);
    return serverAddress;
}

int connectServer(ClientInstance* client) {
    int status = connect(client->sock, (struct sockaddr *)&(client->server_address), sizeof(client->server_address));
    if (status < 0) {
        printf(ERR_CONNECT, WSAGetLastError());
        return 1;
    }
    printf("Conexion establecida con el servidor.\n");
    return 0;
}


int sendData(ClientInstance* client, char* data) {
    if (send(client->sock, data, strlen(data), 0) < 0)
        printf(ERR_SEND, WSAGetLastError());
    else{
        printf("Client attempts to send: %s \n", data);
        return 1;}
}

char* readData(ClientInstance* client) {
    char* response = (char*) malloc(MAX_BUFF_LEN* sizeof(char));

    if(response==NULL){
        printf("Error: Failed to allocate memory for the server response.\n");
        return NULL;
    }
    int bytesRead= recv(client->sock, response, MAX_BUFF_LEN-1,0);
    if (bytesRead==SOCKET_ERROR){
        printf(ERR_READ, WSAGetLastError());
        free(response);
        return NULL;
    } else if (bytesRead==0){
        printf("Connection closed by server.\n");
        free(response);
        return NULL;
    }else{
        response[bytesRead]= '\0';
        printf("Client reads: %s\n", response);
        return response;
    }
}

