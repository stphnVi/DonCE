#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <windows.h>
#include <unistd.h>
#include <string.h>
#include "network.h"

#pragma comment(lib, "ws2_32.lib") //Winsock Library

// WinSock required variables
SOCKET clientSocket;

char recvBuffer[MAX_BUFF_LEN];


//Flag para saber si el juego sirve, coordinar con Estef
boolean isPlaying = TRUE;
////////////////////////////

void initSockets(int serverID){
    int port;

    if(serverID==1){
        port = PORT_A;
    }

    if(serverID==2){
        port = PORT_B;
    }

    WSADATA wsa; //Winsocket init
    struct sockaddr_in server;//server
    
    printf("Initializing WinSock...\n");

    if(WSAStartup(MAKEWORD(2,2), &wsa) !=0 ){
        printf("Winsock init failed: Error code %d\n", WSAGetLastError());

    }
    printf("WinSock successfully initialized.\n");

    //Create a socket
    if((clientSocket= socket(AF_INET, SOCK_STREAM, IPPROTO_TCP))== INVALID_SOCKET){
        printf("Could not create socket. Error code: %d\n", WSAGetLastError());
        WSACleanup();
    }
    printf("Socket created successfully. Attempting to connect to server...\n");
    memset(&server, 0, sizeof(server));
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family= AF_INET;
    server.sin_port= htons(port);

    //Connect to the remote server
    if(connect(clientSocket, (struct sockaddr*)& server, sizeof(server))< 0){
        printf("Cannot connect to server. Error: %d\n", WSAGetLastError());
        closesocket(clientSocket);
        WSACleanup();
    }
    printf("Connection to server successful.\n");
}

//void writeToServer(int key){//Descomentar para la entrada de teclas
//    int result;
//    const char* normalKey= "Key\n";//cualquier otra tecla
//    const char* upKey= "UpKey\n";
//    const char* downKey= "DownKey\n";
//    const char* rightKey= "RightKey\n";
//    const char* leftKey= "LeftKey\n";
//
//    const char* player = "Player\n";
//    const char* spectator = "Spectator\n";
//
//    const char* bye = "bye\n";
//
//    const char* test = "Hola\n";
//
//    //recoger con las teclas de Estef.
//    if(isPlaying){
//        switch (key){
//            case K_UP:
//                result=send(clientSocket, upKey, (int)strlen(upKey),0);
//                break;
//                //asi con cada caso para enviar al server
//        }
//
//    }
//
//    if (result==SOCKET_ERROR){
//        printf("Attempt to send data to server failed. Error: %d\n", WSAGetLastError());
//    }
//}

void writeToServer(char* data){

    if((send(clientSocket,data, (int)strlen(data),0))==SOCKET_ERROR){
        printf("Attempt to send data to server failed. Error: %d\n", WSAGetLastError());
    }
    printf("Data sent to server: %s\n", data);
}


void readFromServer(){
    int result;
    result= recv(clientSocket, recvBuffer, MAX_BUFF_LEN,0);

    if(result > 0){
        printf("El server dice: %s", recvBuffer);
    }
    else if(result==0){
        printf("Connection closed.\n");
    }
    else{
        printf("Data reading failed. Error: %d\n", WSAGetLastError());
    }
}

