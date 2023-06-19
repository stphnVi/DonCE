package Game;

import java.util.ArrayList;
import java.util.List;



public class Controller{

//___________________________Incializacion de variables________________________________________
    //Revisar polimorfismo
    DonCE donce = new DonCE();
    Jugador DKjr = new Jugador(3, 0, 1);



    public Controller(){
        this.donce = donce;
        this.DKjr = DKjr;
    }

    public String getMSJ(){
        return donce.getSend();
    }

    public void updateSendBuffer(String message){
        donce.setSend(message);
    }

    public void crearFruta(Integer liana, Integer altura, Integer puntos, String ID){
        Fruta fruta = new Fruta(liana, altura, puntos, ID);
        donce.agregarFruta(fruta);
        System.out.println(donce.frutas);
    }

    public void crearCocodrilo(String tipo, Integer liana, Integer plataforma){
        Integer velocidad = 100; //delay - velocidad default
        if(tipo.equals("Azul")){
            CocodriloAzul cocodrilo = new CocodriloAzul(plataforma, velocidad);
            donce.agregarCocodrilo(cocodrilo);
        } else if(tipo.equals("Rojo")){
            CocodriloRojo cocodrilo = new CocodriloRojo(liana, velocidad);
            donce.agregarCocodrilo(cocodrilo);
        }

        System.out.println(donce.cocodrilos);
         
    }

    public void eliminarFruta(Integer liana, Integer altura, Integer puntos, String ID){

        for(int i = 0; i < donce.frutas.size(); i++){
            Fruta fruta = donce.frutas.get(i); 
            Integer l = fruta.liana;
            Integer a = fruta.altura;
            Integer p = fruta.puntos;
            String id = fruta.ID;
            if(liana == l && altura == a && puntos == p && ID.equals(id)){
                fruta.eliminar();
            }
        }
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
        //System.out.println("Valores de posJugador: " + donce.posJugador);
        //System.out.println("Valores de posCocodrilos: " + donce.posCocodrilos);
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
            System.out.println(donce.send);
        }

        if(donce.posJugador.equals(donce.posDK)){
            DKjr.win();
        }
    }
}
