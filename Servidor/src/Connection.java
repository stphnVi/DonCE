import java.io.DataOutputStream;
import java.io.IOException;
import  java.net.ServerSocket;
import  java.net.Socket;

//Brinda la informacion relativa la conectividad
public class Connection {
    private final int PORT =9090;
    private final String HOST = "127.0.0.1";
    protected String mensajeServer;
    protected String mensajeCliente;
    protected  ServerSocket ss; //socket del servidor
    protected Socket cs; //socket del cliente
    protected DataOutputStream salidaServer, salidaCliente;

    public Connection(String type) throws IOException
    {
        if(type.equalsIgnoreCase("server")){
            ss = new ServerSocket(PORT);
            cs= new Socket();
        }
        else{
            cs = new Socket(HOST, PORT);
        }
    }
}

