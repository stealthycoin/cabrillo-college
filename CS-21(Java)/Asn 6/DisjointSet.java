/**
 *  Name: John Carlyle
 *  Email: john.w.carlyle@gmail.com
 *  pengo: jcarlyle
 *  Asn#6: Amazing Union-Find
 *  DOM: April, 15
 *  Filename: DisjointSet.java
 *  Description: A set of sets that are questionably related. Thats about it. Its awesome.
 *  Code Status: Working/Tested
 *  Compiles Happily.
 *  
 */

import java.util.Hashtable;
import java.util.Enumeration;

public class DisjointSet {
    
    private int[] parent;
    private int[] rank;
    private int m;
    
    /**
     *  Creates a set of sets of size size.
     */
    public DisjointSet(int size) {
        m = size;
        parent = new int[m];
        rank = new int[m];
    }
    
    /**
     *  Returns whether or not the thing at position i is a set.
     */
    public boolean isSet(int i) {
        //System.out.println(i + " is " + (find(i) != 0));
        return (find(i) != 0); //buffer tiles all have parent 0
    }

    /**
     * Prints out all the sets. Testing purposes.
     */
    public void printSets() {
        Hashtable<Integer, Integer> ht = new Hashtable<Integer, Integer>();
        for (int i = 0 ; i < m ; i++) {
            if (find(i) != 0)
                ht.put(new Integer(find(i)), new Integer(0));
        }
    }
    
    /**
     *  Returns the number of sets in this disjoint set.
     */
    public int setCount() {
        Hashtable<Integer, Integer> ht = new Hashtable<Integer, Integer>();
        for (int i = 0 ; i < m ; i++) {
            if (find(i) != 0)
                ht.put(new Integer(find(i)), new Integer(0));
        }
        
        return ht.size();
    }

    /**
     *  Makes x a set.
    */
    public void makeSet(int x) {
        parent[x] = x;
        rank[x] = 0;
    }
    
    /**
     *  Finds the represntative of set x.
     */
    public int find(int x) {
        if (x != parent[x]) 
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    /**
     *  Joins the two sets of which x and y are a part of.
     */
    public void union(int x, int y) {
        join(find(x), find(y));
    }
    
    /**
     *  Join set x and set y if x and y are not already in the same set.
     *  Assumes x and y are representatives.
     */
    private void join(int x, int y) {
        if (x == y) return;
        if (rank[x] > rank[y]) {
            parent[y] = x;
        }
        else {
            parent[x] = y;
            if (rank[x] == rank[y]) {
                rank[y]++;
            }
        }
    }
}