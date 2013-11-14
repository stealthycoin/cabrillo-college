import java.awt.*;
import java.awt.geom.*;

public class Sprite {
	public static final float GRAVITY = .000f;
	private float xpos;
	private float ypos;
	private float dx;
	private float dy;
    private float angle;
    private int size;
	private boolean isMoving;
	
    public Rectangle getBounds()   {
        return null;
    }
    
	public Sprite()	{
		isMoving = false;
        angle = 180.0f;
	}
	
    public int getSize()    {
        return size;
    }
    
    public void setSize(int s)  {
        size = s;
    }
    
    public float getAngle() {
        return angle;
    }
    
    public void setAngle(float newAngle)  {
        angle = newAngle;
    }
    
	public void setMoving(boolean m)	{
		isMoving = m;
	}
	
	public boolean getMoving()	{
		return isMoving;
	}
	
	public void update(long elapsedTime)	{

	}
	
	public void collideVertical() {	
		setVelocityY(0);
	}
	
	public void collideHorizontal()	{
		setVelocityX(0);
	}
	
	public boolean isFlying()	{
		return false;
	}
	
	public void draw(Graphics2D g)	{
	}
	
    public Color getColor() {
        return null;
    }
    
    public Polygon getPolygon() {
        return null;
    }
	
	public float getX()	{
		return xpos;
	}
	
	public float getY()	{
		return ypos;
	}
	
	public void setX(float x)	{
        xpos = x;
	}
	
	public void setY(float y)	{
        ypos = y;
	}
	
	public int getWidth()	{
        return 0;
	}
	
	public int getHeight()	{
		return 0;
	}
	
	public float getVelocityX()	{
		return dx;
	}
	
	public float getVelocityY()	{
		return dy;
	}
	
	public void setVelocityX(float newDx)	{
		dx = newDx;
	}
	
	public void setVelocityY(float newDy)	{
		dy = newDy;
	}
}