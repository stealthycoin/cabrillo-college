import java.awt.*;
import javax.swing.*;

/**
  CS-20J  Asn 7
  ArtOMatic.java
  Purpose: Randomly draw shapes
  
  @author John Carlyle
  @version 1.3 3/19/05
  */
public class ArtOMatic extends JPanel {
    final static int HEIGHT = 500;
    final static int WIDTH = 500;
    
    public static final int ZERO = 0;
    public static final int NUM_COLORS = 10;
    public static final int NUM_SHAPES = 15;
    
    public static final int RED = 1;
    public static final int BLUE = 2;
    public static final int GREEN = 3;
    public static final int YELLOW = 4;
    public static final int ORANGE = 5;
    public static final int PINK = 6;
    public static final int BLACK = 7;
    public static final int GRAY = 8;
    public static final int CYAN = 9;

    private MyShape shapes[];

    /**
      Contructor that creates shapes.
      */
    public ArtOMatic() {
        
        shapes = new MyShape[NUM_SHAPES];
        for (int i = 0; i < shapes.length; i++)  {
            shapes[i] = getShape();
            shapes[i].setColor(getColor());
            System.out.println(shapes[i].toString());
        }
    }
    
    /**
      Returns the array of shapes drawn in the application.
      
      @return the first point's x coordinate
      */
    public MyShape[] getShapes() {
        return shapes;
    }

    /**
      Draw shapes
      
      @param g graphics context
      */
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        for (int i = 0; i < shapes.length; i++)  {
            shapes[i].draw(g);
        }
    }
    
    /**
        Returns a random shape
        
        @return MyShape
    
    */
    
    public MyShape getShape()  {
        int r = getPoint(ORANGE);
        
        MyShape shape;
        
        if (r == ZERO)   {
            shape = new MyLine(getPoint(WIDTH), getPoint(WIDTH),
                               getPoint(HEIGHT), getPoint(HEIGHT));
        } else if (r == RED)    {
            shape = new MyRect(getPoint(WIDTH / BLUE), 
                               getPoint(WIDTH / BLUE),
                               getPoint(HEIGHT / GREEN), 
                               getPoint(HEIGHT / GREEN));
        } else if (r == BLUE)    {
            shape = new MyOval(getPoint(WIDTH / BLUE), 
                               getPoint(WIDTH / BLUE),
                               getPoint(HEIGHT / GREEN), 
                               getPoint(HEIGHT / GREEN));
        } else if (r == GREEN)    {
            shape = new MyTriangle(getPoint(WIDTH / BLUE), 
                                   getPoint(WIDTH / BLUE),
                                   getPoint(HEIGHT / GREEN), 
                                   getPoint(HEIGHT / GREEN));
        } else  {
            shape = new MyX(getPoint(WIDTH), 
                            getPoint(WIDTH),
                            getPoint(HEIGHT), 
                            getPoint(HEIGHT));
        }
        
        return shape;
    }
    
    /**
        Get a random point inside of the window
        
        @param cap this is the limit of the randomly generated number
        @return random integer
    */
    public int getPoint(int cap)   {
        double random = Math.random();
        random *= cap;
        
        return (int)random;
    }
    
    /**
        Returns a random color
        
        @return returns red, blue, green, yellow, orange, 
                        pink, black, gray, cyan, magenta
    */
    public Color getColor() {
        double r = Math.random();
        r *= NUM_COLORS;
        int random = (int)r;
        
        
        if (random == RED)   {
            return Color.RED;
        }   else if (random == BLUE)   {
            return Color.BLUE;
        }   else if (random == GREEN)   {
            return Color.GREEN;
        }   else if (random == YELLOW)   {
            return Color.YELLOW;
        }   else if (random == ORANGE)   {
            return Color.ORANGE;
        }   else if (random == PINK)   {
            return Color.PINK;
        }   else if (random == BLACK)   {
            return Color.BLACK;
        }   else if (random == GRAY)   {
            return Color.GRAY;
        }   else if (random == CYAN)   {
            return Color.CYAN;
        }  else  {
            return Color.MAGENTA;
        }
    }
    
    
    /**
      Set up the display window
      
      @param args -- not used
      */
    public static void main(String args[]) {
        JFrame frame = new JFrame("Art-O-Matic");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        ArtOMatic panel = new ArtOMatic();
        panel.setBackground(Color.WHITE);
        
        frame.getContentPane().add(panel);
        frame.setSize(WIDTH, HEIGHT);
        frame.setVisible(true);
    }
}
