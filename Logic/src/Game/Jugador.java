package Game;
public class Jugador extends DonCE{

    Integer vidas;
    Integer puntos;
    public Integer nivel;
    
    public Jugador(Integer vidas, Integer puntos, Integer nivel){
        this.vidas = vidas;
        this.puntos = puntos;
        this.nivel = nivel;
    }

    public void win(){
        System.out.println("*** Felicidades, has ganado! ***\nLVL UP +1 vida <3");
        this.vidas = vidas + 1; //Si el jugador gana se suma una vida
        this.nivel = nivel + 1; //Sube de nivel y aumenta la velocidad de los cocodrilos
    }

    public void eatFruit(Fruta fruit){
        System.out.println("Te comiste una fruta! :P \nHas ganado "+ fruit.puntos + " puntos");
        this.puntos = puntos + fruit.puntos; //A los puntos del jugador se le suman los puntos de la fruta
    }

    public void die(){
        System.out.println("X_X Has muerto X_X");
        this.vidas = vidas - 1;
        this.puntos = 0;
    }

}
