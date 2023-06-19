package Game;

public class CocodriloAzul extends DonCE{

    Integer plataforma;

    /**
     * Constructor de cocodrilos azules
     * @param plataforma Numero de plataforma donde se encuentra el cocodrilo
     */
    public CocodriloAzul(Integer plataforma){
        this.plataforma = plataforma;
        System.out.println("Se creo un cocodrilo azul");
        velocidad = 100;
    }

    
}
