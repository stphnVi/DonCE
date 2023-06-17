import java.io.IOException;
import Server.ServerHandler;
public class Main {
    public static void main(String[] args) throws IOException {

        ServerHandler serverA= new ServerHandler(9090);

        serverA.start();

    }

}