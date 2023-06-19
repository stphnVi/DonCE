package Game;

import java.util.ArrayList;
import java.util.List;


/**
 * Clase Controller para determinar la estrategia que sigue el juego
 */
public class Controller{

//___________________________Incializacion de variables________________________________________
    
    DonCE donce = new DonCE();
    Jugador DKjr = new Jugador(3, 0, 1);
    public String send;


    
    public Controller(){
        this.donce = donce;
        this.DKjr = DKjr;
    }

    /**
     * Metodo para crear una fruta desde la interfaz del usuario administrador
     * @param liana Numero de la liana donde estara a fruta
     * @param altura Altura dentro de la liana donde estara la fruta
     * @param puntos Puntos asignados a la fruta
     * @param ID Identificador de la fruta (manzana, banano o granada)
     */
    public void crearFruta(Integer liana, Integer altura, Integer puntos, String ID){
        Fruta fruta = new Fruta(liana, altura, puntos, ID);
        donce.agregarFruta(fruta);
        System.out.println(donce.frutas);
        send = "crear:" + ID + "(" + Integer.toString(fruta.liana) + ", " + Integer.toString(fruta.altura) + ")";
    }

    /**
     * Metodo para crear cocodrilos desde la interfaz del usuario administrador
     * @param tipo Tipo de cocodrilo (azul o rojo)
     * @param liana Numero de la liana donde estara a fruta
     * @param plataforma Numero de la plataforma donde estara a fruta
     */
    public void crearCocodrilo(String tipo, Integer liana, Integer plataforma){
        if(tipo.equals("Azul")){
            CocodriloAzul cocodrilo = new CocodriloAzul(plataforma);
            donce.agregarCocodrilo(cocodrilo);
            send = "crear:azul:" + Integer.toString(plataforma) + ":" + Integer.toString(donce.velocidad);
        } else if(tipo.equals("Rojo")){
            CocodriloRojo cocodrilo = new CocodriloRojo(liana);
            donce.agregarCocodrilo(cocodrilo);
            send = "crear:rojo:" + Integer.toString(liana)+ ":" + Integer.toString(donce.velocidad);
        }

        System.out.println(donce.cocodrilos);
         
    }

    /**
     * Metodo para eliminar una fruta desde la interfaz del usuario administrador
     * @param liana Numero de la liana donde se encuentra a fruta
     * @param altura Altura en la liana donde se encuentra la fruta
     * @param puntos Puntos correspondientes a la fruta
     * @param ID Identificador de la fruta (manzana, banano o granada)
     */
    public void eliminarFruta(Integer liana, Integer altura, Integer puntos, String ID){

        for(int i = 0; i < donce.frutas.size(); i++){
            Fruta fruta = donce.frutas.get(i); 
            Integer l = fruta.liana;
            Integer a = fruta.altura;
            Integer p = fruta.puntos;
            String id = fruta.ID;
            if(liana == l && altura == a && puntos == p && ID.equals(id)){
                send = "eliminar:" + fruta.ID + "(" + Integer.toString(fruta.liana) + ", " + Integer.toString(fruta.altura) + ")";
                donce.eliminarFruta(fruta);
                break;
            }
        }
        
    }

//___________________________Leer Mensaje del Cliente_______________________________________________________

    /**
     * Metodo para leer el mensaje del cliente e interpretarlo
     * @param cadena Mensaje enviado por el cliente
     */
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
        //System.out.println("Valores de posJugador: " + donce.posJugador);
        //System.out.println("Valores de posCocodrilos: " + donce.posCocodrilos);
    }


//___________________________Controlar estados______________________________________________

    /**
     * Motodo para controlar los eventos segun la informacion enviada por el cliente
     */
    public void controll(){
        for(int i = 0; i < donce.posFrutas.size()-1; i++){ 
            //Si el jugador y la fruta tienen la misma posicion 
            Fruta fruta = donce.frutas.get(i);
            if(donce.posJugador.equals(donce.posFrutas.get(i))){
                DKjr.eatFruit(fruta);
                donce.eliminarFruta(fruta);
                send = "eliminar:" + fruta.ID + "(" + Integer.toString(fruta.liana) + ", " + Integer.toString(fruta.altura) + ")";
                break;
            }
            
        }
        for(int i = 0; i < donce.posCocodrilos.size()-1; i++){
            if(donce.posJugador.equals(donce.posCocodrilos.get(i))){
                DKjr.die();
                send = "die";
                //reiniciar nivel
                break;
            }
        }

        if(donce.posJugador.equals(donce.posDK)){
            DKjr.win();
            donce.velocidad -= 25;
            send = "win:" + Integer.toString(DKjr.nivel) + ":" + donce.velocidad;
        }
    }
}
