import java.util.List;
import java.util.ArrayList;


public class Controller{
    //Revisar polimorfismo
    Fruta banana = new Fruta(2, 3, 100);
    Cocodrilo cocodrilo = new Cocodrilo("azul", 3, 50);
    Jugador DKjr = new Jugador(3, 0, 1);

    List<Fruta> frutas = new ArrayList<>();
    List<Cocodrilo> cocodrilos = new ArrayList<>();

    public void agregar() {
        frutas.add(banana);
        cocodrilos.add(cocodrilo);
    }

    //leer json
    List<Integer> posJugador = new ArrayList<>();
    ArrayList<ArrayList<Integer>> posFrutas = new ArrayList<>();
    public void controll(){
        for(int i = 0; i < posFrutas.size(); i++){
            if(posJugador == posFrutas.get(i)){
                DKjr.eatFruit(frutas.get(i));
            }
        }  
    }
}
