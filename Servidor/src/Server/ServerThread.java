package Server;

import java.io.*;
import java.net.Socket;
public class ServerThread extends Thread{

    private Socket socket;
    private ServerHandler serverHandler;
    private Boolean isPlayer;

    public ServerThread(Socket socket, ServerHandler serverHandler){
        this.socket = socket;
        this.serverHandler= serverHandler;
    }
    public boolean testInput(String input){
        if(input==null){
            System.out.println("Null");
            return false;
        }
        else{
            if(input.equals("bye")){//string para concluir el proceso
                return false;
            }
        }
        return true;
    }
    public void run(){
        try{
            InputStream input = socket.getInputStream();
            BufferedReader reader= new BufferedReader(new InputStreamReader(input));

            OutputStream output = socket.getOutputStream();
            PrintWriter writer = new PrintWriter(output,true);
            String text;

            do{
                text=reader.readLine();
                System.out.printf("The clients says: " + text+ "\n");
                writer.println("crear:1(1, 3)");
                System.out.println("Message sent to client successfully.\n");

            } while(!text.equals("bye") && text != null);

            socket.close();

        } catch(IOException exception){
            System.out.println("Server exception: " + exception.getMessage());
            exception.printStackTrace();
        }
    }
}



//    public void run(){//funcion que parsea los mensajes del cliente
//        try{
//            InputStream input = socket.getInputStream();
//            BufferedReader reader= new BufferedReader(new InputStreamReader(input));
//
//            OutputStream output = socket.getOutputStream();
//            PrintWriter writer = new PrintWriter(output,true);
//            String text;
//
//            do{
//                text= reader.readLine();
//                if(text.equals("Hola")){
//                    System.out.println("El cliente dice: " + text);
//                }
//                else if(text.equals("Key")){
//                    System.out.println(text);
//                    //writer.println(string a enviar al cliente);
//                }
//                else if (text.equals("UpKey")){
//                    //movePlayer()
//                    System.out.println(text);
//                    ////writer.println(string a enviar al cliente);
//                }
//                else if (text.equals("DownKey")){
//                    //movePlayer()
//                    System.out.println(text);
//                    ////writer.println(string a enviar al cliente);
//                }
//                else if (text.equals("LeftKey")){
//                    //movePlayer()
//                    System.out.println(text);
//                    ////writer.println(string a enviar al cliente);
//                }
//                else if (text.equals("RightKey")){
//                    //movePlayer()
//                    System.out.println(text);
//                    ////writer.println(string a enviar al cliente);
//                }
//                else if (text.equals("Player"))
//                {
//                    if(serverHandler.player==true){//Si ya existe un jugador en esta partida
//                        //writer.print("denyPlayer");//Se niega la conexion al cliente
//                        serverHandler.clientCount= serverHandler.clientCount-1;//se reduce la cuenta de clientes conectados
//                    }else{
//                        serverHandler.player=true;
//                        isPlayer =true;
//                        //writer.print(string a enviar al cliente);
//                    }
//                }else if (text.equals("Spectator")){
//                    if(serverHandler.clientCount==2 && serverHandler.player==false){//ya existen dos espectadores
//                        //writer.print("denySpect");//Se niega la conexion al cliente
//                        serverHandler.clientCount=2;
//                    }else{
//                        //writer.print(string a enviar al cliente);
//                        System.out.println("clientString");
//                    }
//                }
//            } while (text!=null || text!= "bye");
//            serverHandler.clientCount = serverHandler.clientCount-1;
//            if(isPlayer){
//                serverHandler.player=false;
//            }
//            socket.close();
//        } catch(IOException exception){
//            serverHandler.clientCount = serverHandler.clientCount-1;
//            if(isPlayer){
//                serverHandler.player= false;
//            }
//            System.out.println("Server exception: " + exception.getMessage());
//            exception.printStackTrace();
//        }
//    }
//}
