public class App {
    public static void main(String[] args) throws Exception {
        Controller c1 = new Controller();
        c1.init();
        c1.readClient("posJugador:[0,0]-posCocodrilos:[[0,0],[1,1]]");
        c1.controll();
    }
}
