import javax.swing.*;
import java.awt.event.ActionListener;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;




public class AdminInterface {
    //Componentes graficos
    private JFrame frame;
    private JComboBox<String> gameSelector;
    private JComboBox<String> kremlinSelector;
    private JComboBox<String> fruitSelector;
    private JComboBox<String> heightSelector;
    private JTextField scoreField;
    private JButton createFruitButton;
    private JButton removeFruitButton;
    private JButton generateKremlinButton;
    private JComboBox<String> kremlinPlaceSelector;
    private JComboBox<String> fruitPlaceSelector;


    public AdminInterface(){
        frame = new JFrame("Consola de Administador");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new GridLayout(9, 50, 10, 15));

        gameSelector = new JComboBox<>(new String[]{"Juego 1", "Juego 2"});
        kremlinSelector = new JComboBox<>(new String[]{"Kremlin Rojo", "Kremlin Azul"});
        fruitSelector = new JComboBox<>(new String[]{"Manzana", "Banano", "Granada"});
        kremlinPlaceSelector = new JComboBox<>(new String[]{"Plataforma 1", "Plataforma 2", "Liana 1", "Liana 2"});
        fruitPlaceSelector  = new JComboBox<>(new String[]{"Liana 1", "Liana 2", "Liana 3", "Liana 4"});
        heightSelector= new JComboBox<>(new String[]{"1", "2", "3", "4", "5"});
        scoreField = new JTextField();
        generateKremlinButton = new JButton("Generar Kremlin");
        createFruitButton = new JButton("Crear Fruta");
        removeFruitButton = new JButton("Remover Fruta");

        //Placement de los widgets
        frame.add(new JLabel("Juego:"));
        frame.add(gameSelector);
        frame.add(new JLabel("Enemigo:"));
        frame.add(kremlinSelector);
        frame.add(new JLabel("Posicion:"));
        frame.add(kremlinPlaceSelector);
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

        generateKremlinButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String selectedGame = (String) gameSelector.getSelectedItem();
                String kremlinType = (String) kremlinSelector.getSelectedItem();
                String kremlinPosition = (String) kremlinPlaceSelector.getSelectedItem();

                //Acciones correspondientes a la seleccion de enemigos
                System.out.println("Se ha generado un " + kremlinType
                        + " en " + kremlinPosition +
                        " para el " + selectedGame + ".\n");
            }

        });

        createFruitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String selectedGame = (String) gameSelector.getSelectedItem();
                String fruit = (String) fruitSelector.getSelectedItem();
                String liana = (String) fruitPlaceSelector.getSelectedItem();
                String height = (String) heightSelector.getSelectedItem();
                int score = Integer.parseInt(scoreField.getText());

                //Acciones correspondientes despues de crear
                System.out.println("Se ha generado una " + fruit
                        + " en la  " + liana
                        + " a la altura " + height
                        + " con la puntuacion de " + score
                        +" para el "+selectedGame +  ".\n");

                // Limpia los campos de entrada
                scoreField.setText("");
            }
        });

        removeFruitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String selectedGame = (String) gameSelector.getSelectedItem();
                String fruit = (String) fruitSelector.getSelectedItem();
                String liana = (String) fruitPlaceSelector.getSelectedItem();
                String height = (String) heightSelector.getSelectedItem();
                int score = Integer.parseInt(scoreField.getText());

                //Acciones correspondientes despues de remover
                System.out.println("Se ha removido una " + fruit
                        + " en la  " + liana
                        + " a la altura " + height
                        + " con la puntuacion de " + score
                        +" para el "+ selectedGame +  ".\n");

                // Limpia los campos de entrada
                scoreField.setText("");
            }
        });

        frame.pack();
        frame.setVisible(true);
    }

}

