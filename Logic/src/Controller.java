import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class Controller{

//___________________________Incializacion de variables________________________________________
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

    List<Integer> posJugador = new ArrayList<>(); //posicion del jugador
    List<Integer> posDK = new ArrayList<>(); //posicion de DK, posicion ganadora
    List<List<Integer>> posFrutas = new ArrayList<>(); //matriz de las posiciones de las frutas
    List<List<Integer>> posCocodrilos = new ArrayList<>(); //matriz de las posiciones de los cocodrilos

//___________________________Leer TXT_______________________________________________________

public void readtxt(){
    String filePath = "data.txt";

    try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
        String line;
        while ((line = reader.readLine()) != null) {
            if (line.contains("posJugador:")) {
                posJugador = parseList(line);
            } else if (line.contains("posFrutas:")) {
                posFrutas = parseMatrix(line);
            } else if (line.contains("posCocodrilos:")) {
                posCocodrilos = parseMatrix(line);
            }
        }
    } catch (IOException e) {
        e.printStackTrace();
    }

    // Imprimir las listas
    System.out.println("posJugador: " + posJugador);
    System.out.println("posFrutas: " + posFrutas);
    System.out.println("posCocodrilos: " + posCocodrilos);
}

private static List<Integer> parseList(String line) {
    Pattern pattern = Pattern.compile("\\[(\\d+(,\\s*\\d+)*)\\]");
    Matcher matcher = pattern.matcher(line);
    List<Integer> list = new ArrayList<>();

    if (matcher.find()) {
        String numbers = matcher.group(1);
        String[] numberArr = numbers.split(",\\s*");

        for (String number : numberArr) {
            list.add(Integer.parseInt(number.trim()));
        }
    }

    return list;
}

private static List<List<Integer>> parseMatrix(String line) {
    Pattern pattern = Pattern.compile("\\[(\\[(\\d+(,\\s*\\d+)*)\\](,\\s*)?)*\\]");
    Matcher matcher = pattern.matcher(line);
    List<List<Integer>> matrix = new ArrayList<>();

    if (matcher.find()) {
        String matrixContent = matcher.group();
        Matcher numberMatcher = Pattern.compile("\\[(\\d+(,\\s*\\d+)*)\\]").matcher(matrixContent);

        while (numberMatcher.find()) {
            String numbers = numberMatcher.group(1);
            String[] numberArr = numbers.split(",\\s*");
            List<Integer> row = new ArrayList<>();

            for (String number : numberArr) {
                row.add(Integer.parseInt(number.trim()));
            }

            matrix.add(row);
        }
    }

    return matrix;
}

//___________________________Controlar estados______________________________________________

    public void controll(){
        for(int i = 0; i < posFrutas.size()-1; i++){
            //Si el jugador y la fruta tienen la misma posicion 
            if(posJugador.equals(posFrutas.get(i))){
                DKjr.eatFruit(frutas.get(i));
                frutas.get(i).eliminar();
                break;
            }

            if(posJugador.equals(posCocodrilos.get(i))){
                DKjr.die();
                //reiniciar nivel
                break;
            }

            if(posJugador.equals(posDK)){
                DKjr.win();
                break;
            }
        }  
    }
}
