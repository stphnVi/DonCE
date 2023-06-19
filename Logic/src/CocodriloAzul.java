public class CocodriloAzul extends DonCE{

    Integer plataforma;
    Integer velocidad;

    public CocodriloAzul(Integer plataforma, Integer velocidad){
        this.plataforma = plataforma;
        this.velocidad = velocidad;
        addIntruction("crear:azul:" + Integer.toString(plataforma));
    }

    public void increaseSpeed(){
        addIntruction("speed:" + Integer.toString(velocidad + 50)); 
    }

    @Override
    public void addIntruction(String instruccion) {
        //Enviar al cliente
    }
    
}
