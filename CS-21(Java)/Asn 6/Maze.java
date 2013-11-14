/**
 *  Name: John Carlyle
 *  Email: john.w.carlyle@gmail.com
 *  pengo: jcarlyle
 *  Asn#6: Amazing Union-Find
 *  DOM: April, 15
 *  Filename: Maze.java
 *  Description: Maze object. Contains a disjoint set and an array representing
 *      the maze. Contains methods for generating a valid maze.
 *  Code Status: Working/Tested
 *  Compiles Happily.
 *  
 */

import java.util.Random;

public class Maze {

    public static int[] WALL_VALS = {1,2,4,8};
    public static int BUFF_SIZE = 2;
    
    /**
     *   :0
     *   
     *  |:1
     *  
     *  _:2
     *  
     * _|:3
     * 
     *|  :4
     *
     *| |:5
     *
     *|_ :6
     *
     *|_|:7
     * _ 
     *   :8
     * _
     *  |:9
     * __
     * __:10 (A)
     * __
     * _|:11 (B)
     * __
     *|  :12 (C)
     * __
     *| |:13 (D)
     * __
     *|__:14 (E)
     * __
     *|_|:15 (F)
     *
     */
    
    private DisjointSet sets;
    private int [] maze;
    private int size;
    private int bufferedSize;
    private int length;
    private int bufferedLength;
    private int start;
    private int end;
    
    private Random rand;
    
    /**
     *  Createa a maze of size 3
     */
    public Maze() {
        this(3);
    }
    
    /**
     *  Create a maze of size size.
     */
    public Maze(int size) {
        this.size = size;
        bufferedSize = size + 2;
        length = size*size;
        bufferedLength = bufferedSize*bufferedSize;
        start = size + 3;
        end = start + (length - 1) + (size - 1) * 2;
        
        sets = new DisjointSet(bufferedLength);
        
        maze = new int[bufferedLength];
        sets.makeSet(start);
        maze[start] = 11;
        int boxed = 0;
        for (int i = start+1 ; boxed < length - 2 ; i++) {
            if (i % bufferedSize != 0 && (i+1)%bufferedSize != 0) {
                sets.makeSet(i);
                maze[i] = 15;
                boxed++;
            }
        }
        sets.makeSet(end);
        maze[end] = 14;
        
        rand = new Random(System.currentTimeMillis());
    }
    
    /**
     *  return the maze array.
     */
    public int[] getMaze() {
        return maze;
    }
    
    /**
     *Get the size of the array with the +2 for the bufferes around the edges.
     */
    public int getBufSize() {
        return bufferedSize;
    }
    
    /**
     *  Get the size of the maze
     */
    public int getSize() {
        return size;
    }
    
    /**
     *This method creates a valid maze.
     */
    public void joinAllSets() {
        while (sets.setCount() != 1) {
            int[] rmi = scrambleIndices();
            
            for (int i : rmi) {
                shuffleWalls();
                int j = 0;
                int attempt = 0;
                int wall;
                do {
                    wall = WALL_VALS[attempt];
                    j = translateThroughWall(i, wall);
                    attempt++;
                } while (!sets.isSet(j) && attempt <= 4);
                
                if (sets.isSet(i) && sets.isSet(j) && sets.find(i) != sets.find(j)) {
                    sets.union(i, j);
                    maze[i] -= wall;
                    maze[j] -= oppWall(wall);
                }
            }
        }
    }
    
    /**
     *Randomly re-orders the WALL_VALS array
     */
    private void shuffleWalls() {
        for (int i = 0 ; i < WALL_VALS.length ; i++) {
            WALL_VALS = swap(WALL_VALS, i, rand.nextInt(WALL_VALS.length));
        }
    }
    
    /**
     *returns a randomly scrambled array of all valid maze indexes
     */
    private int[] scrambleIndices() {
        //rmi = random maze indicies
        int [] rmi = new int[length];
        
        //copy valid maze indicies to rmi (not the buffer indicies)
        for (int i = 0, j = start ; i < length ; j++) {
            if (j % bufferedSize != 0 && (j+1)%bufferedSize != 0) {
                rmi[i] = j;
                i++;
            }
        }
        
        //randomly re-order the indicies
        for (int i = 0 ; i < rmi.length ; i++) {
            rmi = swap(rmi, i, rand.nextInt(rmi.length));
        }
        
        return rmi;
    }
    
    /**
     *Helper swap function
     */
    private int[] swap(int[] A, int x, int y) {
        int temp = A[x];
        A[x] = A[y];
        A[y] = temp;
        return A;
    }
    
    /**
     *Return the opposite wall from x
     */
    private int oppWall(int x) {
        if (x == 8) return 2;
        if (x == 4) return 1;
        if (x == 2) return 8;
        if (x == 1) return 4;
        return 0;
    }
    
    /**
     *Return the wall on the other side of wall w from tile x.
     */
    private int translateThroughWall(int x, int w) {
        if (w == 8) return x - bufferedSize;
        if (w == 4) return x - 1;
        if (w == 2) return x + bufferedSize;
        if (w == 1) return x + 1;
        return 0;
    }
    
    /**
     *Print the maze to console
     */
    public void print() {
        int printed = 0;
        for (int i = start ; i <= end ; i++) {
            if (i % bufferedSize != 0 && (i+1)%bufferedSize != 0) {
                System.out.print(Integer.toHexString(maze[i]));
                printed++;
                if (printed % size == 0)
                    System.out.println();
            }
        }
        System.out.println();
    }
}