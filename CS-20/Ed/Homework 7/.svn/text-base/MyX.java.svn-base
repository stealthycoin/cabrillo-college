import java.awt.*;
import javax.swing.*;

/**
    X model class
*/
public class MyX extends MyShape {
    /**
        One of two constructors inits all values to 0
    */
    public MyX()    {
        setX1(0);
        setX2(0);
        setY1(0);
        setY2(0);
    }
    
    /**
        One of two constructors assigns values based in arguments
        
        @param newX1 value to be stored in x1
        @param newX2 value to be stored in x2
        @param newY1 value to be stored in y1
        @param newY2 value to be stored in y2
    */
    public MyX(int newX1, int newX2, int newY1, int newY2)    {
        setX1(newX1);
        setX2(newX2);
        setY1(newY1);
        setY2(newY2);
    }
    
    
    /**
        draws the X
        
        @param g graphics context
    */
    public void draw(Graphics g)   {
        Graphics2D g2 = (Graphics2D)g;
        g2.setColor(getColor());
        g2.drawLine(getX1(), getX2(), getX1() + getY1(), getX2() + getY2());
        g2.drawLine(getX1(), getX2() + getY2(), getX1() + getY1(), getX2());
        
    }
    
    /**
        returns a string based on the position and size of the X
        
        @return returns a string
    */
    public String toString()   {
        return "MyX: x = " + getX1() + ", y = " + getX2()
                + ", width = " + getY1() + ", height = " + getY2();
    }

    
}
