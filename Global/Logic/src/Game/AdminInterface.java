package Game;

import javax.swing.*;
import java.awt.event.ActionListener;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;



/*Funcion que se encarga de desplegar la interfaz del administrador en el servidor
    y manejar la creacion de frutas y de Kremlins*/

public class AdminInterface {
    //Componentes graficos
    private JFrame frame;
    private JComboBox<String> platformSelector;
    private JComboBox<String> lianaSelector;
    private JComboBox<String> kremlinSelector;
    private JComboBox<String> fruitSelector;
    private JComboBox<String> heightSelector;
    private JTextField scoreField;
    private JButton createFruitButton;
    private JButton removeFruitButton;
    private JButton generateKremlinButton;
    private JComboBox<String> fruitPlaceSelector;
    private Controller controller;


    public AdminInterface(Controller controller){
        frame = new JFrame("Consola de Administador");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new GridLayout(9, 50, 10, 15));

        // gameSelector = new JComboBox<>(new String[]{"Juego 1", "Juego 2"});
        kremlinSelector = new JComboBox<>(new String[]{"Rojo", "Azul"});
        fruitSelector = new JComboBox<>(new String[]{"Manzana", "Banano", "Granada"});
        platformSelector = new JComboBox<>(new String[]{"1", "2", "3"});
        lianaSelector = new JComboBox<>(new String[]{"1", "2", "3", "4", "5", "6", "7", "8", "9"});
        fruitPlaceSelector  = new JComboBox<>(new String[]{"1", "2", "3", "4", "5", "6", "7", "8", "9"});
        heightSelector= new JComboBox<>(new String[]{"1", "2", "3", "4"});
        scoreField = new JTextField();
        generateKremlinButton = new JButton("Generar Kremlin");
        createFruitButton = new JButton("Crear Fruta");
        removeFruitButton = new JButton("Remover Fruta");

        /*Ubicacion de los widgets en el grid */
        frame.add(new JLabel("Enemigo:"));
        frame.add(kremlinSelector);
        frame.add(new JLabel("Plataforma:"));
        frame.add(platformSelector);
        frame.add(new JLabel("Liana:"));
        frame.add(lianaSelector);
        frame.add(new JLabel(""));
        frame.add(generateKremlinButton);
        frame.add(new JLabel("Fruta:"));
        frame.add(fruitSelector);
        frame.add(new JLabel("Liana:"));
        frame.add(fruitPlaceSelector);
        frame.add(new JLabel("Altura:"));
        frame.add(heightSelector);
        frame.add(new JLabel("Puntaje:"));
        frame.add(scoreField);
        frame.add(createFruitButton);
        frame.add(removeFruitButton);
        /*Funcion que se encarga de generar un kremlin en el cliente al presionar el boton "generar" */
        generateKremlinButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // String selectedGame = (String) gameSelector.getSelectedItem();
                String kremlinType = (String) kremlinSelector.getSelectedItem();
                Integer kremlinLiana = Integer.parseInt((String) lianaSelector.getSelectedItem());  
                Integer kremlinPlatform = Integer.parseInt((String) platformSelector.getSelectedItem());  

                //Acciones correspondientes a la seleccion de enemigos
                controller.crearCocodrilo(kremlinType, kremlinLiana, kremlinPlatform);
                System.out.println("Se ha generado un " + kremlinType
                        + " en " + kremlinLiana + kremlinPlatform +
                        " para el " + ".\n");
                
            }

        });
        /*Funcion que se encarga de generar una fruta en el cliente al presionar el boton*/
        createFruitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // String selectedGame = (String) gameSelector.getSelectedItem();
                String fruit = (String) fruitSelector.getSelectedItem();
                Integer liana = Integer.parseInt((String) fruitPlaceSelector.getSelectedItem());
                Integer height =Integer.parseInt((String) heightSelector.getSelectedItem());
                Integer score = Integer.parseInt(scoreField.getText());
                String ID = "";

                if(fruit.equals("Banano")){
                    ID = "1";
                }else if(fruit.equals("Manzana")){
                    ID = "0";
                }else if(fruit.equals("Granada")){
                    ID = "2";
                }

                //Crear la fruta
                controller.crearFruta(liana, height, score, ID);

                System.out.println("Se ha generado una " + fruit
                        + " en la  " + liana
                        + " a la altura " + height
                        + " con la puntuacion de " + score
                        +" para el "+ ".\n");

                // Limpia los campos de entrada
                scoreField.setText("");
            }
        });
        /*Funcion que se encarga de remover una fruta en el cliente al presionar el boton*/
        removeFruitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // String selectedGame = (String) gameSelector.getSelectedItem();
                String fruit = (String) fruitSelector.getSelectedItem();
                Integer liana = Integer.parseInt((String) fruitPlaceSelector.getSelectedItem());
                Integer height = Integer.parseInt((String) heightSelector.getSelectedItem());
                Integer score = Integer.parseInt(scoreField.getText());

                //Acciones correspondientes despues de remover
                controller.eliminarFruta(liana, height, score, fruit);
                System.out.println("Se ha removido una " + fruit
                        + " en la  " + liana
                        + " a la altura " + height
                        + " con la puntuacion de " + score
                        +" para el "+ ".\n");

                // Limpia los campos de entrada
                scoreField.setText("");
            }
        });
        
        frame.pack();
        frame.setVisible(true);
    }

}

