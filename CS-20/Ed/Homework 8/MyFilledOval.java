import java.awt.*;
import javax.swing.*;

/**
    filled version of MyOval.
*/
public class MyFilledOval extends MyOval    {
    /**
        Constructor that sets up the supers.
    */
    public MyFilledOval(int x, int y, int x2, int y2)   {
        super(x, y, x2, y2);
    }
    /**
        Override draw so I can get a filled.
    */
    public void draw(Graphics g)  {
        g.setColor(getColor());
        g.fillOval(getX1(), getY1(), getX2() - getX1(), getY2() - getY1());
    }
}
