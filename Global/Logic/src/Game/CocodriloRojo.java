package Game;

public class CocodriloRojo extends DonCE{

    Integer liana;

    /**
     * Constructor de cocodrilos rojos
     * @param liana Numero de liana donde se encontrara el cocodrilo
     */
    public CocodriloRojo(Integer liana){
        this.liana = liana;
        System.out.println("Se creo un cocodrilo rojo");
        velocidad = 100;
    }

    
}
