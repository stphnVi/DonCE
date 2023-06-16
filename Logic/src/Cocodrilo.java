public class Cocodrilo extends DonCE{

    String tipo;
    Integer liana;
    Integer velocidad;

    public Cocodrilo(String tipo, Integer liana, Integer velocidad){
        this.tipo = tipo; 
        this.liana = liana;
        this.velocidad = velocidad;
        addIntruction("crear:" + this.tipo + Integer.toString(liana));
    }

    public void increaseSpeed(){
        addIntruction("speed:" + Integer.toString(velocidad + 50)); 
    }

    @Override
    public void addIntruction(String instruccion) {
        //Enviar al cliente
    }
    
}
