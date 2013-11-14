/**
 *  Name: John Carlyle
 *  Email: john.w.carlyle@gmail.com
 *  pengo: jcarlyle
 *  Asn#6: Amazing Union-Find
 *  DOM: April, 15
 *  Filename: GenerateMaze.java
 *  Description: Testing class.
 *  Code Status: Working/Tested
 *  Compiles Happily.
 *  
 */

import java.util.Scanner;

public class GenerateMaze {

    /**
     *Creates a nxn maze and prins it to the screen
     */
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.print("Enter size of maze: ");
        int n = s.nextInt();
        
        //initialize the maze
        Maze maze = new Maze(n);
        
        maze.joinAllSets();
        maze.print();
    }
}