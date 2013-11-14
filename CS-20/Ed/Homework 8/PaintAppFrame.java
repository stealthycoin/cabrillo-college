import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

/**
    This class contains the controls and drawing area for the app.
*/

public class PaintAppFrame implements ActionListener    {
    
    public static final int BLACK_KEY = 0;
    public static final int BLUE_KEY = 1;
    public static final int RED_KEY = 2;
    public static final int GREEN_KEY = 3;
    public static final int YELLOW_KEY = 4;
    public static final int CYAN_KEY = 5;
    public static final int MAGENTA_KEY = 6;
    public static final int DARK_GRAY_KEY = 7;
    public static final int GRAY_KEY = 8;
    public static final int LIGHT_GRAY_KEY = 9;
    public static final int ORANGE_KEY = 10;
    public static final int PINK_KEY = 11;
    
    public static final int HEIGHT = 500;
    public static final int WIDTH = 500;
    public static final int CONTROLS_HEIGHT = 250;
    public static final int CONTROLS_WIDTH = 140;
    
    public static final int COLOR_SELECTOR_WIDTH = 80;
    public static final int COLOR_SELECTOR_HEIGHT = 80;
    private static final String[] TYPES = {"Line", "Oval", "Rectangle"};
    private static final String[] COLORS = {"Black", "Blue", "Red", 
                                            "Green", "Yellow", "Cyan", 
                                            "Magenta", "Dark Gray", "Gray", 
                                            "Light Gray", "Orange", "Pink"};
    
    public PaintApp paint;
    public JComboBox drawType;
    public JCheckBox fill;
    public boolean fillChecked;
    public JButton clear;
    public JButton undo;
    public JList color;
    public JScrollPane scroll;
    
    /**
        Constructor sets up and places all GUI components.
        Also prepares ActionListeners and the MouseListener
    */
    
    public PaintAppFrame()   {
        JFrame frame = new JFrame("Drawing Application");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        paint = new PaintApp(this);
        paint.setBackground(Color.WHITE);
        
        drawType = new JComboBox(TYPES);
        drawType.setSelectedIndex(1);
        
        fill = new JCheckBox("Filled");
        clear = new JButton("Clear");
        undo = new JButton("Undo");
        
        color = new JList(COLORS);
        color.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        color.setLayoutOrientation(JList.VERTICAL);
        scroll = new JScrollPane(color);
        scroll.setPreferredSize(new Dimension(COLOR_SELECTOR_WIDTH,
                                              COLOR_SELECTOR_HEIGHT));
        
        
        JFrame controls = new JFrame("Controls");
        controls.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        controls.setLayout(new FlowLayout(FlowLayout.LEFT));
        controls.getContentPane().add(drawType);
        controls.getContentPane().add(fill);
        controls.getContentPane().add(clear);
        controls.getContentPane().add(undo);
        controls.getContentPane().add(scroll);
        controls.setSize(new Dimension(CONTROLS_WIDTH, CONTROLS_HEIGHT));
        controls.setVisible(true);
        
        
        frame.getContentPane().add(paint, BorderLayout.CENTER);
        
        frame.setBounds(CONTROLS_WIDTH, 0, WIDTH, HEIGHT);
        frame.setVisible(true);
        
        drawType.addActionListener(this);
        fill.addActionListener(this);
        undo.addActionListener(this);
        clear.addActionListener(this);
    }
    
    /**
        Returns a color based on what is selected in
        the color selection list.
        
        @return Black, Blue, Red, Green, Yellow, Cyan, Magenta
    */
    public Color getSelectedColor()  {
        int colorIndex = color.getSelectedIndex();
        switch (colorIndex)   {
            case BLACK_KEY:
                return Color.BLACK;
                
            case BLUE_KEY:
                return Color.BLUE;
                
            case RED_KEY:
                return Color.RED;
                
            case GREEN_KEY:
                return Color.GREEN;
                
            case YELLOW_KEY:
                return Color.YELLOW;
                
            case CYAN_KEY:
                return Color.CYAN;
                
            case MAGENTA_KEY:
                return Color.MAGENTA;
            
            case DARK_GRAY_KEY:
                return Color.DARK_GRAY;
                
            case GRAY_KEY:
                return Color.GRAY;
                
            case LIGHT_GRAY_KEY:
                return Color.LIGHT_GRAY;
                
            case ORANGE_KEY:
                return Color.ORANGE;
                
            case PINK_KEY:
                return Color.PINK;
                
            default:
                return Color.BLACK;
                
        }
        
    }
    
    
    /**
        Starts exectution of program
        
        @param args not used.
    */
    public static void main(String args[])   {
        PaintAppFrame frame = new PaintAppFrame();
    }
    
    /**
        Handles all the actions coming from the controls.
        
        @param ae Action event from which the source is determined
    */
    public void actionPerformed(ActionEvent ae) {
        Object source = ae.getSource();
        if (source == clear)   {
            paint.clear();
        }
        if (source == fill)   {
            if (fillChecked)   {
                fillChecked = false;
            }   else    {
                fillChecked = true;
            }
        }
        if (source == undo)   {
            paint.removeLast();
        }
    }
}
