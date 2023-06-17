#ifndef CLIENTE_NETWORK_H
#define CLIENTE_NETWORK_H
//////Mover a constants.h//////
#define PORT_A 9090
#define PORT_B 9091

#define MAX_BUFF_LEN 2048

#define K_UP 82 //intercambiar luego con los key codes de SDL
#define K_DOWN 81
#define K_LEFT 80
#define K_RIGHT 79

void initSockets(int serverID);
void writeToServer(char* data);
void readFromServer();


#endif //CLIENTE_NETWORK_H
