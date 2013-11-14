/**
    Draws Initials
    
    @author John Carlyle
    @version 1.0
*/
public class TurtleTracks {

    /**
        Begins execution of program.
        
        @param args not used.
    
    */
    public static void main(String[] args) {
        Turtle myrtle = new Turtle();
        TurtleTracks test = new TurtleTracks();
        myrtle.penUp();
        myrtle.moveTo(800/3, 700);
        myrtle.penDown();
        //test.startKotch2(myrtle, 6, 10000);
        System.out.println(test.mult(5, 5));
        
    }
    
    public int mult(int number, int times) {
        if (times == 1) return number;
        return number + mult(number, times-1);
    }
    
    public int fib(int number) {
        if (number < 2) {
            return number;
        }
        else {
            return fib(number - 1) + fib(number - 2);
        }
 	}
    
    public void startKotch2(Turtle myrtle, int level, int distance) {
        //F = forward
        //+ = 60 degrees right
        //- = 60 degrees left
        String sequence = "F++F++F";
        for (int i = 1 ; i < level ; i++) {
            sequence = sequence.replace("F", "F-F++F-F");
        }
        String[] symbols = sequence.split("");
        int numFs = 0;
        for (String s : symbols) {
            if(s.equals("F")) {
                numFs++;
            }
        }
        drawKotch2(myrtle, sequence, distance/numFs);
    }
    
    public void drawKotch2(Turtle myrtle, String seq, int distance) {
        if (seq.length() < 1) {
            return;
        }
        String character = seq.substring(0, 1);
        if (character.equals("F")) {
            myrtle.forward(distance);
        }
        else if (character.equals("+")) {
            myrtle.right(60);
        }
        else if (character.equals("-")) {
            myrtle.left(60);
        }
        drawKotch2(myrtle, seq.substring(1, seq.length()), distance);
    }
    
    public void startKotch(Turtle myrtle, int level, int distance) {
        drawKotch(myrtle, level, distance);
        myrtle.right(120);
        drawKotch(myrtle, level, distance);
        myrtle.right(120);
        drawKotch(myrtle, level, distance);
        myrtle.right(120);
    }
    
    public void drawKotch(Turtle myrtle, int level, int distance) { 
        if (level < 1)  {
            return;
        }
        else {
            myrtle.forward(distance/3);
            myrtle.left(60);
            drawKotch(myrtle, level - 1, distance/2);
            myrtle.right(120);
            drawKotch(myrtle, level - 1, distance/2);
            myrtle.left(60);
            myrtle.forward(distance/3);
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
}
