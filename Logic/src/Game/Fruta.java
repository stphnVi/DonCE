package Game;
public class Fruta extends DonCE{

    Integer liana;
    Integer altura;
    Integer puntos;
    String ID;

    /**
     * Contructor de la clase fruta 
     * @param liana liana donde se posicionara la fruta
     * @param altura altura donde se posicionara la fruta
     * @param puntos puntos que otorga al jugador
     */
    public Fruta(Integer liana, Integer altura, Integer puntos, String ID){
        this.liana = liana;
        this.altura = altura;
        this.puntos = puntos;
        this.ID = ID;
        System.out.println("Se creo una fruta " + this.ID);
    }

    
}
