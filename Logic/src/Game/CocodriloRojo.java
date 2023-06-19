package Game;

public class CocodriloRojo extends DonCE{

    Integer liana;
    Integer velocidad;

    public CocodriloRojo(Integer liana, Integer velocidad){
        this.liana = liana;
        this.velocidad = velocidad;
        System.out.println("Se creo un cocodrilo rojo");
    }

    public void increaseSpeed(){
        //setSend("speed:" + Integer.toString(velocidad + 50)); 
    }
    
}
