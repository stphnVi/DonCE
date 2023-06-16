#include "socket.h"
//#include <pthread.h>

//void* clientThread(void* arg){
//    socksInit();
//    start();
//    //Client operations
//    char* messageToSend = "Hello Server, from Client! :)";
//}

int main(int argc, char* argv[]){
    //init winsock
    socksInit();

    ClientInstance client_instance;
    if (start(&client_instance) != 0){
        printf("Failed to start the client.\n");
        return 1;
    }

    //Start the client
    printf("Se intentara enviar un mensaje...\n");
    //Send a message
    char* dataToSend = "Hello Server, from Client! :)";
    if(sendData(&client_instance, dataToSend) !=0){
        printf("Error al enviar los datos.\n");
        stop();
        return 1;
    }

    printf("Se intentara leer el mensaje...\n");
    //Read response
    char* response= readData(&client_instance);
    if(response!= NULL){
        printf("Server response: %s\n", response);
        free(response);
    }
    //Stop client
    stop();

    return 0;
}