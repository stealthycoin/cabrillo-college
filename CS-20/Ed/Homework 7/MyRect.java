import java.awt.*;
import javax.swing.*;

/**
    The model for a rectangle shape
*/
public class MyRect extends MyShape {

    /**
        One of two constructors inits all values to 0
    */
    public MyRect()    {
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
    public MyRect(int newX1, int newX2, int newY1, int newY2)    {
        setX1(newX1);
        setX2(newX2);
        setY1(newY1);
        setY2(newY2);
    }
    
    
    /**
        draws the rectangle
        
        @param g graphics context
    */
    public void draw(Graphics g)   {
        g.setColor(getColor());
        g.drawRect(getX1(), getX2(), getY1(), getY2() );
    }
    
    /**
        returns a string based on the rects position and size
        
        @return returns a string
    */
    public String toString()   {
        return "MyRect: x1 = " + getX1() + ", x2 = " + getX2()
                + ", width = " + getY1() + ", height = " + getY2();
    }


}
