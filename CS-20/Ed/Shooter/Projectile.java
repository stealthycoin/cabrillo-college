import java.awt.*;

public class Projectile extends Sprite  {
    public static final float SPEED = PlayerSprite.SPEED * 10.0f;
    float radius;
    Color color;
    
    public Projectile(float x, float y, float dx, float dy, Color c, float size)    {
        super();
        setX(x);
        setY(y);
        setVelocityX(dx);
        setVelocityY(dy);
        color = c;
        radius = size;
    }
    
    public Rectangle getBounds()    {
        return new Rectangle((int)getX(), (int)getY(), (int)(radius * 2.0f), (int)(radius * 2.0f));
    }
    
    public Color getColor() {
        return color;
    }
    
    public Polygon getPolygon() {
        Polygon rect = new Polygon();
        rect.addPoint((int)getX(), (int)getY());
        rect.addPoint((int)(getX() + radius * 2.0f), (int)getY());
        rect.addPoint((int)(getX() + radius * 2.0f), (int)(getY() + radius * 2.0f));
        rect.addPoint((int)getX(), (int)(getY() * 2.0f));
        
        return rect;
    }
    
    public void draw(Graphics2D g)  {
        g.setColor(color);
        g.fillOval(Math.round(getX() - radius), Math.round(getY() - radius), Math.round(radius * 2.0f), Math.round(radius * 2.0f));
    }
}
