

import java.awt.*;

public class Wall extends Sprite    {

    Color c;
    Polygon line;
    
    public Wall(int ax, int ay, int bx, int by, Color c)   {
        line = new Polygon();
        line.addPoint(ax, ay);
        line.addPoint(bx, by);
        this.c = c;
    }
    
    public Rectangle getBounds()    {
        return line.getBounds();
    }
    
    public Color getColor()   {
        return c;
    }
    
    public Polygon getPolygon() {
        return line;
    }
    
    public void update(long elapsedTime)    {
    }
    
    public void draw(Graphics2D g)  {
        g.setColor(c);
        g.drawPolygon(line);
    }

}
