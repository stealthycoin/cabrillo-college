import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

/**
    Frame of the whole date application
*/
public class DateFrame extends JFrame implements ActionListener {    
    private static final int INPUT_WIDTH = 10;
    private static final int FRAME_WIDTH = 140;
    private static final int FRAME_HEIGHT = 80;
    
    static JTextField input;
    static JLabel output;
    
    /**
        Constructor, sets the name of the frame 
        and gets the action lisener ready
    */
    public DateFrame()  {
        super("Date");
        input.addActionListener(this);
    }
    
    /**
        Begins execution here.
        
        @param args Not used
    */
    public static void main(String args[])  {
        input = new JTextField("1/1/2001", INPUT_WIDTH);
        output = new JLabel("1/2/2001");
            
        DateFrame frame = new DateFrame();
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container c = frame.getContentPane();
        c.setLayout(new FlowLayout());
        
        c.add(frame.input);
        c.add(frame.output);
        
        frame.setBounds(0, 0, FRAME_WIDTH, FRAME_HEIGHT);
        frame.setResizable(false);
        frame.setVisible(true);
    }
    
    /**
        Action reciever
        
        @param ae Event to extract information from
    */
    public void actionPerformed(ActionEvent ae) {
        Object source = ae.getSource();
        if (source == input)   {
            String string = input.getText();

            try {
                Date currDate = new Date(string);
                Date tomorrow = currDate.nextDay();
                output.setText(tomorrow.toString());
                
            } catch (MonthException ex)   {
                JOptionPane.showMessageDialog(null, ex.getMessage(),
                                                "Error", 0);
            } catch (DayException ex)   {
                JOptionPane.showMessageDialog(null, ex.getMessage(),
                                                "Error", 0);
            }
        }
    }

}
