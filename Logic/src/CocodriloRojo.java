public class CocodriloRojo extends DonCE{

    Integer liana;
    Integer velocidad;

    public CocodriloRojo(Integer liana, Integer velocidad){
        this.liana = liana;
        this.velocidad = velocidad;
        addIntruction("crear:rojo:" + Integer.toString(liana));
    }

    public void increaseSpeed(){
        addIntruction("speed:" + Integer.toString(velocidad + 50)); 
    }

    @Override
    public void addIntruction(String instruccion) {
        //Enviar al cliente
    }
    
}
