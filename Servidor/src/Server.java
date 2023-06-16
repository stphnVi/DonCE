import java.io.*;
import  java.net.ServerSocket;
import  java.net.Socket;

public class Server extends Connection{

    public Server() throws IOException{super("server");}

    public void startServer() {//metodo para iniciar el server

        try{
            System.out.println("Esperando...\n");

            //Espera la conexion desde el cliente
            cs= ss.accept();

            System.out.println("Cliente conectado.\n");

            //Create input and output streams
            InputStream inputStream = cs.getInputStream();
            OutputStream outputStream = cs.getOutputStream();

            //wrap the streams for convenient message reading and writing
            BufferedReader reader = new BufferedReader(new InputStreamReader(inputStream));
            PrintWriter writer= new PrintWriter(outputStream, true);//autoflush

            //Send response to client
            writer.println("Solicitud recibida y aceptada.\n");

            //Lee los mensajes entrantes
            while((mensajeCliente= reader.readLine())!=null){
                System.out.println("Mensaje del cliente: "+ mensajeCliente+"\n");
            }

            System.out.println("Fin de la conexión");
            ss.close();//cierra la conexion
            cs.close();
        }
        catch(Exception e){
            System.out.println(e.getMessage());
        }
    }
}

