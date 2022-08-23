import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Converter extends JFrame {
    public static void main (String args[]) {
        Converter frame = new Converter();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
        frame.setTitle("Converter");
        frame.pack();
        frame.setLocationRelativeTo(null); 
    }
     
    private Container container;
    private JPanel panel = new JPanel();
    private JLabel fromLabel = new JLabel("From:");
    private JTextField fromField = new JTextField(10);
    private JComboBox fromBox = new JComboBox();
    private JButton convButton = new JButton("Convert");
    private JLabel toLabel = new JLabel("To:");
    private JTextField toField = new JTextField(10);
    private JComboBox toBox = new JComboBox();
     
    public Converter() {
         
        panel.setBorder(BorderFactory.createTitledBorder("Unit Conversion"));
        panel.add(fromLabel);
        panel.add(fromField);
        panel.add(fromBox);
            fromBox.addItem("min");
            fromBox.addItem("hr");
            fromBox.addItem("inch");
            fromBox.addItem("cm");
            fromBox.setSelectedItem("min");
            fromBox.setEditable(false);
            fromBox.addActionListener(new convListener()); 
        panel.add(convButton);
            convButton.addActionListener(new convListener());
        panel.add(toLabel);
        panel.add(toField);
            toField.setEditable(false);
        panel.add(toBox);
            toBox.addItem("hr");
            toBox.addItem("min");
            toBox.addItem("cm");
            toBox.addItem("inch");
            toBox.setSelectedItem("hr");
            toBox.setEditable(false);
            toBox.addActionListener(new convListener());
         
        container = getContentPane();
        container.setLayout(new FlowLayout());
        container.add(panel);
     

    }
     
    private class convListener implements ActionListener {

        public void actionPerformed (ActionEvent event) {

            if (event.getSource() == convButton) {

                try {

                     

                    int i = fromBox.getSelectedIndex();

                    int j = toBox.getSelectedIndex();

                     

                    // if from min and to hr were selected

                    if (i == 0 && j == 0) {

                        double fromMin = Double.parseDouble(fromField.getText());

                        double toHr = convertMinToHr(fromMin);

                            toField.setText("" + toHr);    

                    }

                     

                    // else if from hr and to min were selected

                    else if (i == 1 && j == 1) {

                        double fromHr = Double.parseDouble(fromField.getText());

                        double toMin = convertHrToMin(fromHr);

                            toField.setText("" + toMin);

                    }

                     

                    // else if from min and to min were selected

                    else if (i == 0 && j == 1) {

                        double fromMin = Double.parseDouble(fromField.getText());

                        double toMin = Double.parseDouble(fromField.getText());

                            toField.setText("" + toMin);                       

                    }
                     

                    // else if from hr and to hr were selected

                    else if (i == 1 && j == 0) {

                        double fromHr = Double.parseDouble(fromField.getText());

                        double toHr = Double.parseDouble(fromField.getText());

                            toField.setText("" + toHr);                    

                    }

                     

                    // else if from inch and to cm were selected

                    else if (i == 2 && j == 2) {

                        double fromIn = Double.parseDouble(fromField.getText());

                        double toCm = convertInToCm(fromIn);

                            toField.setText("" + toCm);

                    }
                     

                    // else if from cm and to inch were selected

                    else if (i == 3 && j == 3) {

                        double fromCm = Double.parseDouble(fromField.getText());

                        double toIn = convertCmToIn(fromCm);

                            toField.setText("" + toIn);

                    }

                     

                    // else if from inch and to inch were selected

                    else if (i == 2 && j == 3) {

                        double fromIn = Double.parseDouble(fromField.getText());

                        double toIn = Double.parseDouble(fromField.getText());

                            toField.setText("" + toIn);

                    }                  

                     

                    // else if from cm and to cm were selected

                    else if (i == 3 && j == 2) {

                        double fromCm = Double.parseDouble(fromField.getText());

                        double toCm = Double.parseDouble(fromField.getText());

                            toField.setText("" + toCm);

                    }                  

                     

                    // else

                    else {

                        toField.setText("ERROR");

                    }

                }

                catch (Exception ex){

                    JOptionPane.showMessageDialog(null, "ERROR");

                }

            }
        }

    }

     

    public static double convertHrToMin(double fromHr) {

        return fromHr * 60.0;

    }
    public static double convertMinToHr(double fromMin) {
        return fromMin / 60.0;
    }
    public static double convertCmToIn(double fromCm) {

        return fromCm / 2.54;
    }
    public static double convertInToCm(double fromIn) {
        return fromIn * 2.54;
    }
     
}

