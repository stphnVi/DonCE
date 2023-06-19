#include "network.h"
#include <unistd.h>

int main(int argc, char* argv[]){
    //El cliente siempre debe enviar un \n al final de cada msj

    char* data = "posJugador:[0,1]-posCocodrilos:[[0,0],[1,1]]\n";
    
    initSockets(1);//incializar conexion con servidor 1

    writeToServer(data);
    readFromServer();

    for(int i=0; i<10; i++){
    writeToServer(data);
    readFromServer();
    sleep(3);
}
    return 0;
}