import java.awt.*;
import java.awt.geom.*;


public class PlayerSprite extends Sprite    {
    public static final float SPEED = .27f;
    public static final float ROTATION = .2f;
    public static final int COOLDOWN = 500;
    long timer;
    private Color color;
    private Polygon ship;
    private Point center;
    public boolean canFire;
    
    public PlayerSprite()   {
        this(100, 100, 20);
        canFire = true;
        timer = 0;
    }
    
    public Rectangle getBounds()    {
        Polygon bounds = new Polygon();
        float x = getX();
        float y = getY();
        float halfSize = getSize() / 2.0f;
        
        bounds.addPoint(Math.round(x - halfSize), Math.round(y - halfSize));
        bounds.addPoint(Math.round(x + halfSize), Math.round(y - halfSize));
        bounds.addPoint(Math.round(x - halfSize), Math.round(y + halfSize));
        bounds.addPoint(Math.round(x + halfSize), Math.round(y + halfSize));
        
        return bounds.getBounds();
    }
    
    public Polygon getPolygon() {
        return ship;
    }
    
    public PlayerSprite(int x, int y, int size)   {
        setAngle(0);
        color = Color.green;

        setX(x);
        setY(y);
        setSize(size);
        
        Point left = new Point(Math.round((x - getSize()/2.0f)), Math.round((y + getSize()/2.0f)));
        Point right = new Point(Math.round((x + getSize()/2.0f)), Math.round((y + getSize()/2.0f)));
        Point top = new Point(x, Math.round((y - getSize())));
        
        ship = new Polygon();
        ship.addPoint(left.x, left.y);
        ship.addPoint(right.x, left.y);
        ship.addPoint(top.x, top.y);
    }
    
    public Color getColor()  {
        return color;
    }
    
    public void update(long elapsedTime)    {
        Point left = new Point(Math.round((getX() - getSize()/2.0f)), Math.round((getY() + getSize()/2.0f)));
        Point right = new Point(Math.round((getX() + getSize()/2.0f)), Math.round((getY() + getSize()/2.0f)));
        Point top = new Point(Math.round(getX()), Math.round((getY() - getSize())));
        
        
        ship.reset();
        ship.addPoint(left.x, left.y);
        ship.addPoint(right.x, left.y);
        ship.addPoint(top.x, top.y);
        
        if (!canFire)   {
            timer += elapsedTime;
            if (timer >= COOLDOWN)   {
                canFire = true;
                timer = 0;
            }
        }
    }
    
    public void draw(Graphics2D g)    {
    
        float x = getX();
        float y = getY();
        float halfSize = getSize() / 2.0f;
        
        Point tl = new Point(Math.round(x - halfSize), Math.round(y - halfSize));
        Point tr = new Point(Math.round(x + halfSize), Math.round(y - halfSize));
        Point bl = new Point(Math.round(x - halfSize), Math.round(y + halfSize));
        Point br = new Point(Math.round(x + halfSize), Math.round(y + halfSize));
        
        Polygon bounds = new Polygon();
        bounds.addPoint(tl.x, tl.y);
        bounds.addPoint(tr.x, tr.y);
        bounds.addPoint(br.x, br.y);
        bounds.addPoint(bl.x, bl.y);
        
        g.setColor(color);
        
        g.rotate(Math.toRadians((double)getAngle()), (double)getX(), (double)getY());
        g.fillPolygon(ship);
        g.rotate(Math.toRadians((double)-getAngle()), (double)getX(), (double)getY());
        
        g.setColor(Color.red);
        g.drawPolygon(bounds);
        
    }

}
