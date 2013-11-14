import java.awt.*;
import javax.swing.*;

/**
    Filled version of MyRect
*/
public class MyFilledRect extends MyRect    {
    
    /**
        Sets up the super classes.
    */
    public MyFilledRect(int x, int y, int x2, int y2)   {
        super(x, y, x2, y2);
    }

    /**
        Overrides MyRect's drawing With filled goodnes.
    */
    public void draw(Graphics g)    {
        g.setColor(getColor());
        g.fillRect(getX1(), getY1(), getX2() - getX1(), getY2() - getY1());
    }
}
