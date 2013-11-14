import java.awt.*;
import javax.swing.*;

/**
    model for a line
*/
public class MyLine extends MyShape {
    /**
        One of two constructors inits all values to 0
    */
    public MyLine()    {
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
    public MyLine(int newX1, int newX2, int newY1, int newY2)    {
        setX1(newX1);
        setX2(newX2);
        setY1(newY1);
        setY2(newY2);
    }
    
    
    /**
        draws the line
        
        @param g graphics context
    */
    public void draw(Graphics g)   {
        g.setColor(getColor());
        g.drawLine(getX1(), getY1(), getX2(), getY2());
    }
    
    /**
        returns a string based on the end points of the line
        
        @return returns a string
    */
    public String toString()   {
        return "MyLine: x1 = " + getX1() + ", x2 = " + getX2()
                + ", y1 = " + getY1() + ", y2 = " + getY2();
    }
}
