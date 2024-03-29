import java.awt.*;
import java.awt.event.*;

class test extends Frame {

	Label num1 = new Label("Enter Number 1");
	Label num2 = new Label("Enter Number 2");
	Button button1 = new Button ("Click me");
	TextField text1 = new TextField (10);
	TextField text2 = new TextField (10);
	TextField text3 = new TextField (10);

	TextField value = new TextField (10);
	Button square = new Button("Square");
	TextField result = new TextField (10);

	test() {
		//Constructor
		setLayout( new FlowLayout() );

		add(num1);
		add(text1);
		add(num2);
		add(text2);
		add(button1);
		button1.addActionListener (new IsClicked());
		add(text3);
		text3.setEditable(false);


		add(value);
		add(square);
		square.addActionListener (new SquareButton());
		add(result);
		result.setEditable(false);


		setSize(500, 150);
		setVisible(true);
		setTitle("Calculations");
		addWindowListener( new WindowAdapter() {
			public void windowClosing(WindowEvent we) {
				dispose();
			}
		} );
	}

	private class SquareButton implements ActionListener {
		public void actionPerformed (ActionEvent evnt) {
			int val = Integer.parseInt(value.getText());
			val = val * val;
			result.setText(val + "");
		}
	}
	private class IsClicked implements ActionListener {
		public void actionPerformed(ActionEvent evt) {
			int num = Integer.parseInt(text1.getText()) + Integer.parseInt(text2.getText());
			text3.setText( num + "");
		}
	}

	public static void main (String[] args) {
		new test();
	}
}
