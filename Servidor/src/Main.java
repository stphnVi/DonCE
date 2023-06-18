import java.io.IOException;
import Server.ServerHandler;

import javax.swing.*;

public class Main {
    public static void main(String[] args) throws IOException {

        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new AdminInterface();
            }
        });

        ServerHandler serverA= new ServerHandler(9090);

        serverA.start();

    }

}