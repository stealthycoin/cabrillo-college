/**
 *  Name: John Carlyle
 *  Email: john.w.carlyle@gmail.com
 *  pengo: jcarlyle
 *  Asn#6: Amazing Union-Find
 *  DOM: April, 15
 *  Filename: MazeFrame.java
 *  Description: Testing class.
 *  Code Status: Working/Tested
 *  Compiles Happily.
 *  
 */

import java.awt.*;
import javax.swing.*;

public class MazeFrame extends Canvas {
    public static int TILE_L = 16;
    
    private int n;
    private Maze maze;
    
    /**
    *  Creates a new Canvas with a randomly generated maze in it.
    */    
    public MazeFrame() {
        super();
        
        String n = JOptionPane.showInputDialog(null, "Enter length of sides for a maze");
        try {
            this.n = Integer.valueOf(n);
        }
        catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
        
        
        //initialize the maze
        maze = new Maze(Integer.valueOf(n));        
        maze.joinAllSets();
    }
    
    /**
     *Gets the dimensions of the square maze(length, width)
     */
    public int getN() {
        return n;
    }
    /**
     *  Creates a JFrame and puts this MazeFrame
     */
    public static void main(String[] args) {
        MazeFrame maze = new MazeFrame();
        JFrame frame = new JFrame("Maze");
        maze.setSize(new Dimension((maze.getN()+2)*TILE_L,(maze.getN()+2)*TILE_L));
        
        frame.getContentPane().add(maze);
        frame.pack();
        
        frame.setResizable(false);
        frame.setVisible(true);
    }
    
    public void paint(Graphics g) {
        super.paint(g);
        int x = -1, y = -1;
        g.setColor(Color.black);
        for (int i : maze.getMaze()) {
            x++;
            drawTile(x*TILE_L, y*TILE_L, i, g);
            if (x % maze.getBufSize() == 0) {
                y++;
                x = 0;
            }
        }
    }
    
    public void drawTile(int x, int y, int i, Graphics g) {
        if (i == 1) {
            drawRight(x,y,g);
        }
        if (i == 2) {
            drawBottom(x,y,g);
        }
        if (i == 3) {
            drawRight(x,y,g);
            drawBottom(x,y,g);
        }
        if (i == 4) {
            drawLeft(x,y,g);
        }
        if (i == 5) {
            drawLeft(x,y,g);
            drawRight(x,y,g);
        }
        if (i == 6) {
            drawLeft(x,y,g);
            drawBottom(x,y,g);
        }
        if (i == 7) {
            drawLeft(x,y,g);
            drawBottom(x,y,g);
            drawRight(x,y,g);
        }
        if (i == 8) {
            drawTop(x,y,g);
        }
        if (i == 9) {
            drawTop(x,y,g);
            drawRight(x,y,g);
        }
        if (i == 10) {
            drawTop(x,y,g);
            drawBottom(x,y,g);
        }
        if (i == 11) {
            drawTop(x,y,g);
            drawRight(x,y,g);
            drawBottom(x,y,g);
        }
        if (i == 12) {
            drawTop(x,y,g);
            drawLeft(x,y,g);
        }
        if (i == 13) {
            drawLeft(x,y,g);
            drawTop(x,y,g);
            drawRight(x,y,g);
        }
        if (i == 14) {
            drawTop(x,y,g);
            drawBottom(x,y,g);
            drawLeft(x,y,g);
        }
        if (i == 15) {
            drawTop(x,y,g);
            drawRight(x,y,g);
            drawLeft(x,y,g);
            drawBottom(x,y,g);
        }
    }
    
    public void drawTop(int x, int y, Graphics g) {
        g.drawLine(x, y, x + TILE_L, y);
    }
    
    public void drawBottom(int x, int y, Graphics g) {
        g.drawLine(x, y + TILE_L, x + TILE_L, y + TILE_L);
    }
    
    public void drawRight(int x, int y, Graphics g) {
        g.drawLine(x + TILE_L, y, x + TILE_L, y + TILE_L);
    }
    
    public void drawLeft(int x, int y, Graphics g) {
        g.drawLine(x, y, x, y + TILE_L);
    }
}