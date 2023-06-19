package Game;

public class CocodriloAzul extends DonCE{

    Integer plataforma;
    Integer velocidad;

    public CocodriloAzul(Integer plataforma, Integer velocidad){
        this.plataforma = plataforma;
        this.velocidad = velocidad;
        setSend("crear:azul:" + Integer.toString(plataforma));
        System.out.println("Se creo un cocodrilo azul");
    }

    public void increaseSpeed(){
        setSend("speed:" + Integer.toString(velocidad + 50)); 
    }
    
}
