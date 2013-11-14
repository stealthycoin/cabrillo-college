import java.io.*;
import java.util.*;

public class FloydWarshall2 {

    private int n;
    private Edge[] edges;
    private Integer[][] adjMatrix;//initial adj matrix
    private Integer[][][] D; //distances array
    private Integer[][][] P; //parent/predeccess
    

    public FloydWarshall2(ArrayList<String> data) {
        
        //break arraylist of data into a list of edges.
        //find largest node.
        edges = new Edge[data.size()];
        int highestNode = 0;
        for (int i = 0 ; i < edges.length ; i++) {
            String[] a = data.get(i).split(",");
            edges[i] = new Edge(Integer.valueOf(a[0]), Integer.valueOf(a[1]), Integer.valueOf(a[2]));
            if (edges[i].v > highestNode)
                highestNode = edges[i].v;
            if (edges[i].u > highestNode)
                highestNode = edges[i].u;
        }
        
        //size of array should be 1 bigger than the largest node.
        //then we load the edges into the adj-matrix
        n = highestNode+1;
        adjMatrix = new Integer[n][n];
        for (Edge e : edges) {
            adjMatrix[e.v][e.u] = e.w;
        }
        //set all selfs (where i=j) to 0
        setSelfs(adjMatrix);
        
        //run floyd warshall
        FW();
        //print results
        System.out.println("Distances matrix");
        print3DArray(D);
        System.out.println("Parent matrix");
        print3DArray(P);
    }

    public void FW() {
        D = new Integer[n][n][n];//these are null (infinity) by default
        P = new Integer[n][n][n];//all null (infinity) by default
        D[0] = copyMatrix(adjMatrix);//first layer of D is just the initial adjacency matrix
        P[0] = startParents(adjMatrix);//first layer of P is infinity where i=j or D[0][i][j] is infinity otherwise its i
        for (int k = 1 ; k < n ; k++) {
            D[k] = copyMatrix(D[k-1]); //set it to the matrix before it. (I don't see the point in havinh the third dimension at all)
            //why not just keep 1 2D array and update it k times?
            for (int i = 1 ; i < n ; i++) {
                for (int j = 1 ; j < n ; j++) {
                    D[k][i][j] = min(D[k-1][i][j], sum(D[k-1][i][k], D[k-1][k][j])); // get smaller distanced path i-j or i-k-j
                    if (D[k][i][j] != D[k-1][i][j])//meaning the path shortened since it can only change by decreasing in length
                        P[k][i][j] = P[k-1][k][j];//so the new parent node k across the edge k-j
                    else //stayed the same. Copy old parent. i-j is still shortest path.
                        P[k][i][j] = P[k-1][i][j];
                }
            }
        }
    }
    
    //this adds two integers together taking into account null (infinity)
    private Integer sum(Integer a, Integer b) {
        if (a == null || b == null) return null;
        return a + b;
    }
    
    //finds the minimum of two integers taking into account null (infinity)
    private Integer min(Integer a, Integer b) {
        if (a == null && b == null) return null;
        else if (a == null) return b;
        else if (b == null) return a;
        return a < b ? a : b;
    }


    //sets the P[0] array based on the initial adjacency matrix
    private Integer[][] startParents(Integer[][] matrix) {
        Integer[][] newMatrix = new Integer[n][n];
        for (int i = 1 ; i < n ; i++) {
            for (int j = 1 ; j < n ; j++) {
                if (i != j && matrix[i][j] != null) newMatrix[i][j] = i;
            }
        }
        return newMatrix;
    }

    /**
     *Copies a matrix so that there are no pointers between them
     */
    public Integer[][] copyMatrix(Integer[][] matrix) {
        Integer[][] newMatrix = new Integer[n][n];
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < n ; j++) {
                newMatrix[i][j] = matrix[i][j];
            }    
        }
        return newMatrix;
    }
    //set digonal distances to 0
    public void setSelfs(Integer[][] matrix) {
        //set distances-to-self = 0
        for (int i = 0 ; i < n ; i++) {
            matrix[i][i] = 0;
        }
    }

    //prints a 3d array
    public void print3DArray(Integer[][][] matrix) {
        for (int i = 0 ; i < n ; i++) {
            System.out.println("Step " + i);
            printArray(matrix[i]);
            System.out.println();
        }
    }

    //prints a 2d array (0-9 values only)
    public void printArray(Integer[][] matrix) {
        for (int y = 1 ; y < n ; y++) {
            for (int x = 1 ; x < n ; x++) {
                if (matrix[y][x] == null)
                    System.out.printf("%3c", (char)128);//prints ? for infinity
                else
                    System.out.printf("%3d", matrix[y][x]);
            }
            System.out.println();
        }
    }


    

    //reads stdin and starts floyd-warshall
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            
            String line;
            ArrayList<String> lines = new ArrayList<String>();
            while ((line = br.readLine()) != null)
                lines.add(line);
                
            FloydWarshall2 fw = new FloydWarshall2(lines);
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    //simpl edge class.
    class Edge {
        public int v,u,w;
        
        public Edge(int a, int b, int c) {
            v = a;
            u = b;
            w = c;
        }
    }
}