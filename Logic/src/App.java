import java.io.IOException;
import Server.ServerHandler;

import javax.swing.*;

public class App {
    public static void main(String[] args) throws IOException {

        Controller c1 = new Controller();

         SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new AdminInterface();
            }
        });

        ServerHandler serverA = new ServerHandler(9090);

        serverA.start();

        c1.readClient("posJugador:[0,0]-posCocodrilos:[[0,0],[1,1]]");
        c1.controll();
    }
}
