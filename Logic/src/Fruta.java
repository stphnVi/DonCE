public class Fruta implements DonCE{

    Integer liana;
    Integer altura;
    Integer puntos;

    /**
     * Contructor de la clase fruta 
     * @param liana liana donde se posicionara la fruta
     * @param altura altura donde se posicionara la fruta
     * @param puntos puntos que otorga al jugador
     */
    public Fruta(Integer liana, Integer altura, Integer puntos){
        this.liana = liana;
        this.altura = altura;
        this.puntos = puntos;
    }

    /**
     * Metodo para eliminar un fruta del juego
     */
    public void eliminar(){

    }
    
}
