//
//  PaintApp.java
//  
//
//  Created by John Carlyle on 10/30/06.
//

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

/**
    PaintApp is the drawing context.
*/

public class PaintApp extends JPanel    {
    
    public LinkedList shapes;
    public Point p1, p2;
    private boolean fill;
    private PaintAppFrame container;
    
    /**
        Paint app constructor
        
        @param c Needs access to its container, that way it can determine
        the values of various controls and act accordingly.
    */
    public PaintApp(PaintAppFrame c)   {
        container = c;
        shapes = new LinkedList();
        addMouseListener(new MouseAdapter() {
                /**
                    MouseReleased triggers when you release the mouse button
                    It sets the second point and triggers a genShape()
            
                    @param me Mouse event containing info on click
                */
                public void mouseReleased(MouseEvent me)   {
                    p2 = me.getPoint();
                    genShape();
                }
        
                /**
                    MousePressed triggers when the mouse gets pressed down
                    all it does is set the first point
            
                    @param me Mouse event containing info on click
                */
                public void mousePressed(MouseEvent me)   {
                    p1 = me.getPoint();
                }
                        });
        p1 = new Point();
        p2 = new Point();
    }
    
    /**
        Removes all objects from the drawing area.
    */
    
    public void clear() {
        shapes.clear();
        updateUI();
    }
    
    /**
        Generates a new shape based on many factors.
    */
    public void genShape()  {
        String shapeString = (String)container.drawType.getSelectedItem();
        
        MyShape shape;
        
        if (shapeString.equals("Line"))   {
            shape = new MyLine(p1.x, p2.x, p1.y, p2.y);
        } else if (shapeString.equals("Rectangle"))    {
            if (container.fillChecked)   {
                shape = new MyFilledRect(p1.x, p2.x, p1.y, p2.y);
            }   else    {
                shape = new MyRect(p1.x, p2.x, p1.y, p2.y);
            }
        } else if (shapeString.equals("Oval"))    {
            if (container.fillChecked)   {
                shape = new MyFilledOval(p1.x, p2.x, p1.y, p2.y);
            }   else    {
                shape = new MyOval(p1.x, p2.x, p1.y, p2.y);
            }
            
        } else  {
            shape = shape = new MyLine(p1.x, p2.x, p1.y, p2.y);
        }
        shape.setColor(Color.BLACK);
        shape.setColor(container.getSelectedColor());
        shapes.addToStart((Object)shape);
        updateUI();
    }
    
    /**
        Removes the last object in the shapes array, effectivly an undo
    */
    public void removeLast() {
        shapes.removeFromStart();
        updateUI();
    }
    
    /**
        Does the acutal drawing and toStringing of the objects.
        
        @param g is the graphics context for the drawing
    */
    public void paintComponent(Graphics g)    {
        super.paintComponent(g);
        LinkedList.ListIter iterator = shapes.iterator();
        while (iterator.hasNext())  {
            System.out.println("Has Next");
            MyShape shape = (MyShape)iterator.next();
            shape.draw(g);
            System.out.println(shape.toString());
        }
        System.out.println("Done");
       
    }
}
