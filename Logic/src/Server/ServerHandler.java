package Server;

import java.net.*;
import java.io.*;


/**
 * Clase que controla a los clientes del servidor segun el puerto al que se conectan*/
public class ServerHandler extends Thread{

    public Integer clientCount;//count
    public Integer port;//puerto p conexion
    public boolean player;//si es player or spect

    /**
     * Constructor de Server.ServerHandler*/
    public ServerHandler(Integer port) {//, DonCE juego); ->Se debe agregar la instancia de juego DonCE como parametro constructivo
        this.port = port;
        //this.juego= juego;
        this.player=false;
        clientCount=0;
    }
    /**
     * Se inicializa el socket*/
    public void run(){
        try(ServerSocket serverSocket = new ServerSocket(port)){
            System.out.println("Server is listening on port: "+port);

            while(clientCount<=3){//Solo puede haber max 3 clients: 2 spect y 1 player
                Socket clientSocket= serverSocket.accept();
                System.out.println("New client connected to port: "+port);
                clientCount+=1;
                System.out.println("Cantidad de clientes conectados: "+ clientCount+"\n");
                ServerThread serverThread= new ServerThread(clientSocket,this);
                serverThread.start();
            }
        } catch(IOException exception){
            exception.printStackTrace();
        }
    }
}
