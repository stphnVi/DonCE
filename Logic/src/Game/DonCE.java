package Game;

import java.util.ArrayList;
import java.util.List;

public class DonCE {

    public List<Fruta> frutas = new ArrayList<>();
    public List<DonCE> cocodrilos = new ArrayList<>();
    public List<Jugador> jugadores = new ArrayList<>();

    List<Integer> posJugador = new ArrayList<>(); //posicion del jugador
    List<Integer> posDK = new ArrayList<>(); //posicion de DK, posicion ganadora
    public List<List<Integer>> posFrutas = new ArrayList<>(); //matriz de las posiciones de las frutas
    List<List<Integer>> posCocodrilos = new ArrayList<>(); //matriz de las posiciones de los cocodrilos

    public String send;


    public DonCE(){
        this.send = send;
        
    }

    public void agregarCocodrilo(DonCE cocodrilo){
        cocodrilos.add(cocodrilo);

    }

    public void agregarFruta(Fruta fruta){
        frutas.add(fruta);
        List<Integer> posFruta = new ArrayList<>();
        posFruta.add(fruta.liana); 
        posFruta.add(fruta.altura); 
        posFrutas.add(posFruta);
    }

    public void eliminarFruta(Fruta fruta){
        frutas.remove(fruta);
        posFrutas.remove(frutas);
        fruta.eliminar();
    }

}
