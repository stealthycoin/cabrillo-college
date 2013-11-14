import java.awt.*;
import java.awt.geom.*;

/**
    Draws Crazy Things
    
    @author John Carlyle
    @version 1.0
*/

public class TurtleLoops {
    
    /**
        Begins execution of program.
        
        @param args not used.
    
    */
    public static void main(String[] args) {
        Turtle myrtle = new Turtle();
        TurtleLoops test = new TurtleLoops();
        
        TurtleSave save = new TurtleSave(myrtle.getX(), myrtle.getY(), myrtle.getHeading());
        while (true)    {
            myrtle.penUp();
            myrtle.moveTo(save.getX(), save.getY());
            myrtle.setHeading(save.getHeading());
            myrtle.setPenColor(Color.BLACK);
            myrtle.penDown();
            
            test.drawStar(myrtle, 50);
        
            myrtle.sleep(2000);
            myrtle.clear();
        
            myrtle.right(100);
            test.startFractalTree(myrtle, 200);
        
            myrtle.sleep(2000);
            myrtle.clear();
        
            for (int i = 3 ; i <= 6 ; i++)  {
                test.drawPolygon(myrtle, 50, i);
                myrtle.sleep(2000);
                myrtle.clear();
            }
        
            test.drawRosette(myrtle, 50, 32);
        
            myrtle.sleep(2000);
            myrtle.clear();
        
            test.drawSpiral(myrtle, 10, 50);
        
            myrtle.sleep(2000);
            myrtle.clear();
            myrtle.setPenColor(Color.RED);
        
            test.drawSpiralRec(myrtle, 10, 50);
        
            myrtle.sleep(2000);
            myrtle.clear();
        }
        
    }
    
    
    /**
    
        draws a square
        
        @param turtle The turtle to draw with
        @param size The size of the sides of the square in pixels
    
    */
    public void drawSquare(Turtle turtle, int size) {
        turtle.forward(size);
        turtle.right(90);
        turtle.forward(size);
        turtle.right(90);
        turtle.forward(size);
        turtle.right(90);
        turtle.forward(size);
        turtle.right(90);
    }
    
    /**
        draws a triangle
 
        @param turtle The turtle to draw with
        @param size The size of the sides of the triangle in pixels
    */
    public void drawEquilateralTriangle(Turtle turtle, int size)    {
        turtle.forward(size);
        turtle.right(120);
        turtle.forward(size);
        turtle.right(120);
        turtle.forward(size);
        turtle.right(120);
    }
    
    
    /**
        draws a pentagon
        
        @param turtle The turtle to draw with
        @param size THe size of the sides of the pentagon in pixels
        
        
    */
    public void drawPentagon(Turtle turtle, int size)  {
        turtle.forward(size);
        turtle.right(72);
        turtle.forward(size);
        turtle.right(72);
        turtle.forward(size);
        turtle.right(72);
        turtle.forward(size);
        turtle.right(72);
        turtle.forward(size);
        turtle.right(72);
    }
    
    /**
    
        draw a hexagon
        
        @param turtle The turtle to draw with
        @param size The size of the sides of the hexagon in pixels
        
    */
    public void drawHexagon(Turtle turtle, int size)  {
        turtle.forward(size);
        turtle.right(60);
        turtle.forward(size);
        turtle.right(60);
        turtle.forward(size);
        turtle.right(60);
        turtle.forward(size);
        turtle.right(60);
        turtle.forward(size);
        turtle.right(60);
        turtle.forward(size);
        turtle.right(60);
    }
    
    /** 
        
        draw a circle
        
        @param turtle turtle to draw with
        @param diameter Diameter of the circle
        @param quality The quality with which the circle is drawn, too high or low and the quality will be bad. Diameter/5 for quality is decent.
    */
    public void drawCircle(Turtle turtle, int diameter, int quality)  {
        int numLines = quality;
        double circumference = diameter * Math.PI;
        int lineSize = (int) (circumference / numLines);
        double angle = 360.0/numLines;
        for (int x = 0 ; x < numLines ; x++)  {
            turtle.forward(lineSize);
            turtle.right(angle);
        }
    }
    
    /**
 * Use the turtle to draw a start with 5 points.
 *
 * @param turtle The turtle to draw with.
 * @param size The size of the sides of the points.
 */
    public void drawStar(Turtle turtle, int size)   {
        turtle.forward(size);
        turtle.right(160);
        turtle.forward(size);
        turtle.left(90);
        turtle.forward(size);
        turtle.right(160);
        turtle.forward(size);
        turtle.left(90);
        turtle.forward(size);
        turtle.right(160);
        turtle.forward(size);
        turtle.left(90);
        turtle.forward(size);
        turtle.right(160);
        turtle.forward(size);
        turtle.left(90);
        turtle.forward(size);
        turtle.right(160);
        turtle.forward(size);
    }
    /**
    * Use the turtle to draw a regular polygon with the specified
    * number of sides.
    *
    * @param turtle The turtle to draw with.
    * @param size The size of the sides of the polygon in pixels.
    * @param numSides The number of sides.
    */
    public void drawPolygon(Turtle turtle, int size, int numSides)  {
        drawCircle(turtle, size, numSides);
    }
    
    /**
    * Use the turtle to draw a rosette made up of numerous squares
    * rotated around a central axis.
    *
    * @param turtle The turtle to draw with.
    * @param size The size of the sides of the squares.
    * @param numSquares The number of squares to use in the rosette.
    */
    public void drawRosette(Turtle turtle, int size, int numSquares) {
        int angle = 360 / numSquares;
        for (int x = 0 ; x < numSquares ; x++)  {   
            drawSquare(turtle, size);
            turtle.right(angle);
        }
        
    }
    
    /**
    * Use the turtle and a loop to draw a spiral with lines
    * increasing from size to maxSize in length and using an
    * angle of 15 degrees between each line.
    *
    * @param turtle The turtle to draw with.
    * @param size The minimum length of the lines of the spiral.
    * @param maxSize The maximum length of the lines of the
    * spiral.
    */
    public void drawSpiral(Turtle turtle, int size, int maxSize) {
        for (int x = size ; x < maxSize ; x++)  {
            turtle.forward(x);
            turtle.right(15);
        }
    }

    /**
    * Use the turtle and recursion to draw a spiral with lines
    * increasing from size to maxSize in length and using an
    * angle of 15 degrees between each line.
    *
    * @param turtle The turtle to draw with.
    * @param size The minimum length of the lines of the spiral.
    * @param maxSize The maximum length of the lines of the
    * spiral.
    */
    public void drawSpiralRec(Turtle turtle, int size, int maxSize) {
        drawSpiralRecSegment(turtle, size, maxSize);
    }
    
    public void drawSpiralRecSegment(Turtle turtle, int size, int maxSize)  {
        if (size == maxSize)   {
            return;
        }
        else    {
            turtle.forward(size);
            turtle.right(15);
            drawSpiralRecSegment(turtle, ++size, maxSize);
        }
    }
    
    
    /**
    * Start a fractal tree
    *
    * @param turtle The turtle to draw with.
    * @param length The length of the base stem
    * @see http://www.shiffman.net/itp/classes/nature/week07_s06/tree/Tree.pde
    */
    public void startFractalTree(Turtle turtle, int length)  {
        turtle.forward(length);
        turtle.backward(length);
        turtle.right(180);
        branch(turtle, length);
        
    }
    
    /**
    * Use the turtle to draw a fractal tree
    *
    * @param turtle The turtle to draw with.
    * @param length The length of each branch
    * @see http://www.shiffman.net/itp/classes/nature/week07_s06/tree/Tree.pde
    */
    public void branch(Turtle turtle, int length) {
        length *= 0.66f;
        if (length > 2) {
            
            TurtleSave save = new TurtleSave(turtle.getX(), turtle.getY(), turtle.getHeading());
            turtle.right(45);
            turtle.forward(length);
            branch(turtle, length);
            
            turtle.moveTo(save.getX(), save.getY());
            turtle.setHeading(save.getHeading());
            
            save.setPos(turtle.getX(), turtle.getY());
            save.setHeading(turtle.getHeading());
            turtle.left(45);
            turtle.forward(length);
            branch(turtle, length);
            
            turtle.moveTo(save.getX(), save.getY());
            turtle.setHeading(save.getHeading());
        }
    }
}
