import javax.swing.*;
import java.awt.image.BufferedImage;
import java.awt.*;
import java.awt.event.*;
import java.io.*;

/**
    MyDrawing is an extension of JPanel that draws random things.
     P.S. Click on the fishie
    
    @author John carlyle
    @version 1.0 10/10/06
*/

public class MyDrawing extends  JPanel implements MouseListener {
    public static final int RED = 1;
    public static final int BLUE = 2;
    public static final int GREEN = 3;
    public static final int YELLOW = 4;
    public static final int ORANGE = 5;
    public static final int PINK = 6;
    public static final int BLACK = 7;
    public static final int GRAY = 8;
    public static final int CYAN = 9;
    
    
    public static final int FISH_SIZE = 16;
    public static final int RECT_SIZE = 90;
    public static final int NUM_ITEMS = 5;
    public static int HEIGHT = 300, WIDTH = 400; 
    public static int fx, fy;
    public static BufferedImage image;
    

    /**
        paintComponent This is a built in method of the JPanel 
            I am overriding and adding drawing commands to.
        
        @param g Drawable area.
    */
    public void paintComponent(Graphics g)  {
        super.paintComponent(g);
        HEIGHT = this.getHeight();
        WIDTH = this.getWidth();
        
        drawLines(g);
        drawRects(g);
        
        double x = Math.random();
        fx = (int)(x * (WIDTH - image.getWidth()));
        double y = Math.random();
        fy = (int)(y * (HEIGHT - image.getHeight()));
        double h = Math.random();
        g.drawImage(image, fx, fy , null);
    }
    
    /**
        drawLines draws 5 lines of random length, placment, and color.
        
        @param g Provides the graphics area in which to draw the rects.
    */
    public void drawLines(Graphics g) {
        for (int i = 0; i < NUM_ITEMS; i++)  {
            double x = Math.random();
            x *= WIDTH;
            double y = Math.random();
            y *= HEIGHT;
            double x2 = Math.random();
            x2 *= WIDTH;
            double y2 = Math.random();
            y2 *= HEIGHT;
            
            g.setColor(randColor());
            g.drawLine((int)x, (int)y, (int)x2, (int)y2);
        }
    }
    
    /**
        drawRects draws 5 randomly sized and colored rectangles
        
        @param g Provides the grahics area in which to draw the rects.
    */
    public void drawRects(Graphics g)   {
        for (int i = 0; i < NUM_ITEMS; i++)  {
            double x = Math.random();
            x *= WIDTH;
            double y = Math.random();
            y *= HEIGHT;
            double h = Math.random();
            h *= RECT_SIZE;
            double w = Math.random();
            w *= RECT_SIZE;
            
            g.setColor(randColor());
            g.drawRect((int)x, (int)y, (int)w, (int)h);
            g.fillRect((int)x, (int)y, (int)w, (int)h);
        }
    }
    
    
    /**
        randColor simply returns a random color.
        
        @return red, blue, green, yellow, orange, pink, black, 
            gray, cyan, magenta.
    */
    public Color randColor()    {
        double r = Math.random();
        r *= 10;
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
        Not Used
        
        @param me Not used
    */
    public void mousePressed(MouseEvent me) {
    }
    
    /**
        Clicky clicky
        
        @param me Mouse Event info
    */
    public void mouseReleased(MouseEvent me)    {
        int x = me.getX();
        int y = me.getY();
        if (x > fx && y > fy && x < fx + FISH_SIZE && y < fy + FISH_SIZE)   {
            updateUI();
        }
    }
    
    /**
        Not Used
        
        @param me Not used
    */
    public void mouseClicked(MouseEvent me) {
    }
    
    /**
        Not Used
        
        @param me Not used
    */
    public void mouseEntered(MouseEvent me) {
    }
    
    /**
        Not Used
        
        @param me Not used
    */
    public void mouseExited(MouseEvent me)  {
    }        
    
    /**
        Constructor, sets up mouse listening
    */
    public MyDrawing()  {
        addMouseListener(this);
    }
    
    /**
        Main method starts execution of the program and loads the image/
        
        @param args Not used.
    */
    public static void main(String args[])   {
        ImageLoader loader = new ImageLoader();
        image = loader.loadImage("cheepcheep.gif");
        JFrame frame = new JFrame("Drawing");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        MyDrawing panel = new MyDrawing();
        panel.setBackground(Color.WHITE);
        panel.setPreferredSize(new Dimension(WIDTH, HEIGHT));
        frame.add(panel);
         
        frame.setResizable(false);
        frame.pack();
        frame.setVisible(true);

    }
}
