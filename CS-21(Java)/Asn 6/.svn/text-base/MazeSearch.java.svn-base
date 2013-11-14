/**
 *  Name: John Carlyle
 *  Email: john.w.carlyle@gmail.com
 *  pengo: jcarlyle
 *  Asn#8: Breadth-First Search
 *  DOM: April, 25ish
 *  Filename: MazeSearch.java
 *  Description: Testing class.
 *  Code Status: Working/Tested
 *  Compiles Happily.
 *  
 */

import java.io.*;
import java.util.*; public class MazeSearch {

    private char[] maze;
    private int size;
    private int d[];
    private int p[];
    private int[][] graph;

    /**
     *Constructs a maze search object with an ascci maze input
     */
    public MazeSearch(String maze) {
        this.maze = maze.toCharArray();
        size = (int)Math.sqrt(maze.length());
        makeGraph();
    }
    
    /**
     *Makes a graph out of the chars.
     *Hybrid of matrix and list
     */
    private void makeGraph() {
        graph = new int[maze.length][4];
        
        for (int i = 0 ; i < graph.length ; i++) {
            for (int j = 0; j < graph[0].length ; j++) {
                graph[i][j] = -1;
            }
        }
        String binary;
        for (int i = 0 ; i < maze.length ; i++) {
            binary = Integer.toBinaryString(Character.digit(maze[i], 16));
            int digit = 0, adj = 0;
            for (int j = binary.length() - 1; j >= 0 ; j--) {
                if (binary.substring(j, j+1).equals("0")) {
                    switch (digit) {
                    case 0:
                        graph[i][adj++] = translateThroughWall(i, 1);
                        break;
                    case 1:
                        graph[i][adj++] = translateThroughWall(i, 2);
                        break;
                    case 2:
                        graph[i][adj++] = translateThroughWall(i, 4);
                        break;
                    case 3:
                        graph[i][adj++] = translateThroughWall(i, 8);
                        break;
                    }
                }
                digit++;
            }
            while (digit < 4)
                graph[i][adj++] = translateThroughWall(i, (int)Math.pow(2, digit++));
        }
    }
    
    /**
     *Runs BFS on the graph
     *Starting at position s.
     */
    public void BFS(int s) {
        d = new int[maze.length];
        p = new int[maze.length];
        if (s < maze.length) {
            for (int u = 0 ; u < maze.length ; u++) {
                p[u] = -1;
                d[u] = -1;
            }
            d[s] = 0;
            
            LinkedList<Integer> queue = new LinkedList<Integer>();
            queue.add(s);
            while (queue.size() != 0) {
                int u = queue.removeFirst();
                for (int v : graph[u]) {
                    if (v >= 0) {
                        if (d[v] == -1) {
                            d[v] = d[u]+1;
                            p[v] = u;
                            queue.add(v);
                        }
                    }
                }
            }
        }
    }
    
    /**
     *Printed the graph. For testing purposes
     */
    public void printGraph() {
        for (int[] i : graph) {
            for (int j : i) {
                System.out.print(j);
            }
            System.out.println();
        }
    }
    
    /**
     *Goes through wall w of position x
     *Returns the int value of the tile on the other side.
     *RV protects from leaving the maze grid.
     */
    private int translateThroughWall(int x, int w) {
        int rv = 0;
        if (w == 8) rv = x - size;
        if (w == 4) rv = x - 1;
        if (w == 2) rv = x + size;
        if (w == 1) rv = x + 1;
        if (rv >= maze.length) rv = -1;
        return rv;
    }
    
    /**
     *Prints the solution based ont he results of the BFS. More specifically
     *the p array.
     */
    public String solve() {
        int node = 0;
        String solution = getCoordinate(0);
        while (p[node] != -1) {
            node = p[node];
            solution += " " + getCoordinate(node);
        }
        return solution;
    }
    
    /**
     *prints x, y position of vertex v
     */
    private String getCoordinate(int v) {
        return "("+v%size+","+v/size+")";
    }
    
    /**
     *gets size of the maze
     */
    public int getLength() {
        return maze.length;
    }
    
    /**
     *reads and runs the test.
     */
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            
            String line, lines = "";
            while ((line = br.readLine()) != null)
                lines += line;
            MazeSearch ms = new MazeSearch(lines);
            //to solve the graph of the maze
            //we need to start a breadth first search from the finish
            ms.BFS(ms.getLength()-1);
            //now we follow the parent-trail from the start position
            System.out.println(ms.solve());
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }
}