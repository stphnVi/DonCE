import java.util.ArrayList;
import java.util.List;



public class Controller{

//___________________________Incializacion de variables________________________________________
    //Revisar polimorfismo
    DonCE donce = new DonCE();
    Fruta banana = new Fruta(2, 3, 100, "banano");
    Fruta fresa = new Fruta(1, 5, 50, "fresa");
    Cocodrilo cocodrilo = new Cocodrilo("azul", 3, 50);
    Jugador DKjr = new Jugador(3, 0, 1);

    public void init(){
        donce.agregarFruta(banana);
        donce.agregarFruta(fresa);
        donce.agregarCocodrilo(cocodrilo);
        System.out.println(donce.frutas);
        donce.eliminarFruta(banana);
        System.out.println(donce.frutas);
        System.out.println(donce.cocodrilos);
    }



//___________________________Leer Mensaje del Cliente_______________________________________________________

    public void readClient(String cadena){

        // Obtener la lista de valores de posJugador
        int inicioPosJugador = cadena.indexOf("[");
        int finPosJugador = cadena.indexOf("]");
        String listaPosJugador = cadena.substring(inicioPosJugador + 1, finPosJugador);
        String[] valoresPosJugador = listaPosJugador.split(",");
        
        for (String valor : valoresPosJugador) {
            donce.posJugador.add(Integer.parseInt(valor));
        }
        
        // Obtener la lista de valores de posCocodrilos
        int inicioPosCocodrilos = cadena.lastIndexOf("[[");
        int finPosCocodrilos = cadena.lastIndexOf("]]");
        String listaPosCocodrilos = cadena.substring(inicioPosCocodrilos + 2, finPosCocodrilos);
        String[] elementosPosCocodrilos = listaPosCocodrilos.split("\\],\\[");
        
        for (String elemento : elementosPosCocodrilos) {
            String[] valores = elemento.split(",");
            List<Integer> posiciones = new ArrayList<>();
            for (String valor : valores) {
                posiciones.add(Integer.parseInt(valor));
            }
            donce.posCocodrilos.add(posiciones);
        }
        
        // Imprimir los resultados
        System.out.println("Valores de posJugador: " + donce.posJugador);
        System.out.println("Valores de posCocodrilos: " + donce.posCocodrilos);
    }


//___________________________Controlar estados______________________________________________

    public void controll(){
        for(int i = 0; i < donce.posFrutas.size()-1; i++){ //cambiar limite debe funcionar para todas las listas
            //Si el jugador y la fruta tienen la misma posicion 
            if(donce.posJugador.equals(donce.posFrutas.get(i))){
                DKjr.eatFruit(donce.frutas.get(i)); //se elimina dentro de eatFruit
                break;
            }
        }
        for(int i = 0; i < donce.posCocodrilos.size()-1; i++){
            if(donce.posJugador.equals(donce.posCocodrilos.get(i))){
                DKjr.die();
                //reiniciar nivel
                break;
            }
        }

        if(donce.posJugador.equals(donce.posDK)){
            DKjr.win();
        }
    }
}
