package Game;

public class CocodriloRojo extends DonCE{

    Integer liana;
    Integer velocidad;

    public CocodriloRojo(Integer liana, Integer velocidad){
        this.liana = liana;
        this.velocidad = velocidad;
        System.out.println("Se creo un cocodrilo rojo");
        send = "crear:rojo:" + Integer.toString(liana);
    }

    public void increaseSpeed(){
        send = "speed:" + Integer.toString(velocidad + 50); 
    }
    
}
