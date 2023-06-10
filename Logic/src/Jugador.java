public class Jugador implements DonCE{

    Integer vidas;
    Integer puntos;
    Integer nivel;
    
    public Jugador(Integer vidas, Integer puntos, Integer nivel){
        this.vidas = vidas;
        this.puntos = puntos;
        this.nivel = nivel;
    }

    public void win(){
        this.vidas = vidas + 1; //Si el jugador gana se suma una vida
        this.nivel = nivel + 1; //Sube de nivel y aumenta la velocidad de los cocodrilos
    }

    public void eatFruit(Fruta fruit){
        this.puntos = puntos + fruit.puntos; //A los puntos del jugador se le suman los puntos de la fruta
        fruit.eliminar(); 
    }

    public void die(){
        this.vidas = vidas - 1;
        //Reiniciar nivel
    }
}
