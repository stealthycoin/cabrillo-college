import java.awt.*;

/**
    Abstractly defines a shape
    
*/
public abstract class MyShape {
    private int x1, x2, y1, y2;
    private Color color = Color.black;
    
    /**
        One of two constructors inits all values to 0
    */
    public MyShape()    {
        x1 = x2 = y1 = y2 = 0;
    }
    
    /**
        One of two constructors assigns values based in arguments
        
        @param newX1 value to be stored in x1
        @param newX2 value to be stored in x2
        @param newY1 value to be stored in y1
        @param newY2 value to be stored in y2
        @param f is the shape filled
    */
    public MyShape(int newX1, int newX2, int newY1, int newY2)    {
        x1 = newX1;
        x2 = newX2;
        y1 = newY1;
        y2 = newY2;
    }
    
    /**
        sets x1 to i
        
        @param i int to replace old one
    */
    public void setX1(int i) {
        x1 = i;
    }
    
    /**
        sets x2 to i
        
        @param i int to replace old one
    */
    public void setX2(int i) {
        x2 = i;
    }
    
    /**
        sets y1 to i
        
        @param i int to replace old one
    */
    public void setY1(int i) {
        y1 = i;
    }
    
    /**
        sets y2 to i
        
        @param i int to replace old one
    */
    public void setY2(int i) {
        y2 = i;
    }
    
    /**
        gets x1 value of the shape
        
        @return an integer
    */
    public int getX1()  {
        return x1;
    }
    
    /**
        gets x1 value of the shape
        
        @return an integer
    */
    public int getX2()  {
        return x2;
    }
    
    /**
        gets x1 value of the shape
        
        @return an integer
    */
    public int getY1()  {
        return y1;
    }
    
    /**
        gets x1 value of the shape
        
        @return an int
    */
    public int getY2()  {
        return y2;
    }
    
    /**
        gets the color
        
        @return a Color
    */
    public Color getColor()   {
        return color;
    }
    
    /**
        sets the color of the shape
        
        @param c the new color for the obect
    */
    public void setColor(Color c)  {
        color = c;
    }
    
    /**
        draws the obejct
        
        @param g grahics context
    */
    public abstract void draw(Graphics g);
    
    /**
        returns a string representation of the object
        
        @return a string bassed on the shapes location and size
    */
    public abstract String toString();
    

}
