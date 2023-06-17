#include "network.h"
#include <unistd.h>

int main(int argc, char* argv[]){
    //El cliente siempre debe enviar un \n al final de cada msj

    char* data = "Hola\n";
    initSockets(1);//incializar conexion con servidor 1

    writeToServer(data);

    readFromServer();

    writeToServer("bye\n");
    sleep(5);


    return 0;
}