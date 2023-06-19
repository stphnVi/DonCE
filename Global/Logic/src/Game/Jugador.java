package Game;
public class Jugador extends DonCE{

    Integer vidas;
    Integer puntos;
    public Integer nivel;
    
    /**
     * Constructor de jugadores
     * @param vidas Vidas del jugador
     * @param puntos Puntos recolectados por el jugador
     * @param nivel Nivel en el que se encuentra el jugador
     */
    public Jugador(Integer vidas, Integer puntos, Integer nivel){
        this.vidas = vidas;
        this.puntos = puntos;
        this.nivel = nivel;
    }

    /**
     * Si el jugador gana la partida
     */
    public void win(){
        this.vidas = vidas + 1; //Si el jugador gana se suma una vida
        this.nivel = nivel + 1; //Sube de nivel y aumenta la velocidad de los cocodrilos
        System.out.println("*** Felicidades, has ganado! ***\nLVL UP +1 vida <3\n Actualmente estas en el nivel "
        + nivel + " y tienes " + vidas + " vidas");
    }

    /**
     * Si el jugador se come una fruta
     * @param fruit fruta que se come
     */
    public void eatFruit(Fruta fruit){
        this.puntos = puntos + fruit.puntos; //A los puntos del jugador se le suman los puntos de la fruta
        System.out.println("Te comiste una fruta! :P \nHas ganado "+ fruit.puntos + " puntos\nActualmente tienes " + 
        puntos + " puntos");
    }

    /**
     * Si el jugador muere
     */
    public void die(){
        this.vidas = vidas - 1;
        this.puntos = 0;
        System.out.println("X_X Has muerto X_X\nTe quedan " + vidas + " vidas");
    }

}
